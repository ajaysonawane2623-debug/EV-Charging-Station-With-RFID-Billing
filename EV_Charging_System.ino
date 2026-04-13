/*
=====================================================
 Fully Automated EV Charging Station
 RFID Based Billing System
=====================================================
 Platform   : Arduino UNO
 RFID       : RC522
 Sensor     : ACS712
 Display    : 16x2 LCD I2C
=====================================================
*/

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------------- PIN CONFIG ----------------
#define SS_PIN 10
#define RST_PIN 9
#define RELAY_PIN 7
#define GREEN_LED 6
#define RED_LED 5
#define BUZZER 4
#define CURRENT_SENSOR A0

// ---------------- OBJECTS ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);

// ---------------- USERS ----------------
byte registeredUID[][4] = {
  {0xA1, 0xB2, 0xC3, 0xD4},
  {0x11, 0x22, 0x33, 0x44}
};

String userNames[] = {"Rahul", "Priya"};
int totalUsers = 2;

// ---------------- BILLING ----------------
float ratePerUnit = 8.0;
float supplyVoltage = 230.0;

// ---------------- VARIABLES ----------------
bool chargingActive = false;
float totalEnergy = 0;
float totalBill = 0;
unsigned long sessionStart = 0;
int currentUser = -1;

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  lcd.init();
  lcd.backlight();

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(RED_LED, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("EV Charging Sys");
  lcd.setCursor(0, 1);
  lcd.print("Tap Card...");
}

// ---------------- LOOP ----------------
void loop() {

  if (chargingActive) updateDisplay();

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  int userIndex = checkUID();

  if (userIndex >= 0) {
    if (!chargingActive) startCharging(userIndex);
    else if (userIndex == currentUser) stopCharging();
  } else {
    accessDenied();
  }

  rfid.PICC_HaltA();
}

// ---------------- UID CHECK ----------------
int checkUID() {
  for (int i = 0; i < totalUsers; i++) {
    bool match = true;
    for (int j = 0; j < 4; j++) {
      if (rfid.uid.uidByte[j] != registeredUID[i][j]) {
        match = false;
        break;
      }
    }
    if (match) return i;
  }
  return -1;
}

// ---------------- START ----------------
void startCharging(int user) {
  currentUser = user;
  chargingActive = true;
  sessionStart = millis();

  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  lcd.clear();
  lcd.print("Hi ");
  lcd.print(userNames[user]);
  lcd.setCursor(0, 1);
  lcd.print("Charging ON");

  beep(1);
}

// ---------------- STOP ----------------
void stopCharging() {
  chargingActive = false;

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  lcd.clear();
  lcd.print("Bill: Rs ");
  lcd.print(totalBill);

  delay(3000);

  currentUser = -1;
  lcd.clear();
  lcd.print("Tap Card...");
}

// ---------------- DISPLAY ----------------
void updateDisplay() {
  float current = readCurrent();
  float power = supplyVoltage * current;

  float hours = (millis() - sessionStart) / 3600000.0;

  totalEnergy = (power * hours) / 1000.0;
  totalBill = totalEnergy * ratePerUnit;

  lcd.clear();
  lcd.print("I:");
  lcd.print(current, 2);
  lcd.print("A");

  lcd.setCursor(0, 1);
  lcd.print("Bill:");
  lcd.print(totalBill, 1);

  delay(1000);
}

// ---------------- CURRENT ----------------
float readCurrent() {
  float sum = 0;
  for (int i = 0; i < 50; i++) {
    sum += analogRead(CURRENT_SENSOR);
    delay(1);
  }

  float voltage = (sum / 50.0) * (5.0 / 1023.0);
  float current = (voltage - 2.5) / 0.185;

  if (current < 0) current = 0;
  return current;
}

// ---------------- ACCESS DENIED ----------------
void accessDenied() {
  lcd.clear();
  lcd.print("Access Denied");

  beep(3);
  delay(1500);

  lcd.clear();
  lcd.print("Tap Card...");
}

// ---------------- BEEP ----------------
void beep(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER, HIGH);
    delay(150);
    digitalWrite(BUZZER, LOW);
    delay(100);
  }
}
