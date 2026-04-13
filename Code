=====================================================
 *  Fully Automated EV Charging Station
 *  with RFID Based Billing System
 * =====================================================
 *  Platform   : Arduino UNO (ATmega328P)
 *  RFID       : RC522 (SPI)
 *  Sensor     : ACS712 Current Sensor
 *  Display    : 16x2 LCD via I2C
 *  Author     : Embedded Systems Project
 *  Year       : 2025
 * =====================================================
 *
 *  PIN CONNECTIONS:
 *  RC522  --> Arduino
 *  SDA    --> D10
 *  SCK    --> D13
 *  MOSI   --> D11
 *  MISO   --> D12
 *  RST    --> D9
 *  VCC    --> 3.3V
 *  GND    --> GND
 *
 *  LCD (I2C)  --> Arduino
 *  SDA        --> A4
 *  SCL        --> A5
 *  VCC        --> 5V
 *  GND        --> GND
 *
 *  ACS712     --> Arduino
 *  AOUT       --> A0
 *  VCC        --> 5V
 *  GND        --> GND
 *
 *  Relay      --> D7
 *  Green LED  --> D6
 *  Red LED    --> D5
 *  Buzzer     --> D4
 * =====================================================
 *
 *  Required Libraries:
 *  - MFRC522           (RFID RC522)
 *  - LiquidCrystal_I2C (LCD Display)
 *  - Wire              (Built-in)
 *  - SPI               (Built-in)
 * =====================================================
 */

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// =====================================================
// PIN DEFINITIONS
// =====================================================
#define SS_PIN         10   // RC522 SDA/SS
#define RST_PIN         9   // RC522 RST
#define RELAY_PIN       7   // Relay control
#define GREEN_LED       6   // Charging active indicator
#define RED_LED         5   // Idle / Access denied
#define BUZZER          4   // Audio alert
#define CURRENT_SENSOR A0   // ACS712 analog output

// =====================================================
// OBJECT INITIALIZATION
// =====================================================
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27
MFRC522 rfid(SS_PIN, RST_PIN);       // RFID instance

// =====================================================
// REGISTERED RFID UIDs
// Add your RFID card UIDs here
// To find UID: upload, open Serial Monitor,
// tap card and note the UID printed
// =====================================================
byte registeredUID[][4] = {
  {0xA1, 0xB2, 0xC3, 0xD4},   // User 1 - Rahul
  {0x11, 0x22, 0x33, 0x44},   // User 2 - Priya
  // Add more users below:
  // {0xXX, 0xXX, 0xXX, 0xXX},   // User 3 - Name
};
String userNames[] = {"Rahul", "Priya"};
int totalUsers = 2;  // Update this when adding more users

// =====================================================
// BILLING CONFIGURATION
// =====================================================
float ratePerUnit    = 8.0;    // Rs. per kWh (change as needed)
float supplyVoltage  = 230.0;  // AC supply voltage in Volts

// =====================================================
// SESSION VARIABLES
// =====================================================
bool chargingActive    = false;
float totalEnergy      = 0.0;   // kWh consumed
float totalBill        = 0.0;   // Rs. bill amount
unsigned long sessionStart = 0; // Session start time (ms)
int currentUser        = -1;    // Currently charging user index

// =====================================================
// SETUP
// =====================================================
void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  // LCD init
  lcd.init();
  lcd.backlight();

  // Pin modes
  pinMode(RELAY_PIN,  OUTPUT);
  pinMode(GREEN_LED,  OUTPUT);
  pinMode(RED_LED,    OUTPUT);
  pinMode(BUZZER,     OUTPUT);

  // Initial state
  digitalWrite(RELAY_PIN, LOW);   // Charger OFF
  digitalWrite(GREEN_LED, LOW);   // Green OFF
  digitalWrite(RED_LED,  HIGH);   // Red ON (idle)

  // Welcome screen
  lcd.setCursor(0, 0);
  lcd.print("EV Charging Sys");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EV Charging Sys");
  lcd.setCursor(0, 1);
  lcd.print("Tap Card...");

  Serial.println("=================================");
  Serial.println("EV Charging Station Ready");
  Serial.println("Waiting for RFID card...");
  Serial.println("=================================");
}

// =====================================================
// MAIN LOOP
// =====================================================
void loop() {
  // Continuously update display during charging
  if (chargingActive) {
    updateChargingDisplay();
  }

  // Check if new RFID card is present
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Print scanned UID to Serial Monitor (for debugging)
  Serial.print("Card UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Verify UID
  int userIndex = verifyUID();

  if (userIndex >= 0) {
    // Valid user
    if (!chargingActive) {
      startCharging(userIndex);         // Start new session
    } else if (userIndex == currentUser) {
      stopCharging();                   // End current session
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Another Session");
      lcd.setCursor(0, 1);
      lcd.print("Already Active!");
      beep(2, 100);
      delay(2000);
    }
  } else {
    accessDenied();   // Unknown card
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  delay(1000);
}

// =====================================================
// VERIFY UID AGAINST REGISTERED USERS
// Returns user index if found, -1 if not found
// =====================================================
int verifyUID() {
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

// =====================================================
// START CHARGING SESSION
// AUTO: Relay ON, Green LED ON, Timer starts
// =====================================================
void startCharging(int userIndex) {
  currentUser    = userIndex;
  chargingActive = true;
  totalEnergy    = 0.0;
  totalBill      = 0.0;
  sessionStart   = millis();

  // AUTO relay ON — no human needed
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED,   LOW);

  beep(1, 300);  // Single beep confirmation

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hi, " + userNames[userIndex]);
  lcd.setCursor(0, 1);
  lcd.print("Charging Start!");
  delay(2000);

  Serial.println("---------------------------------");
  Serial.println("Session Started: " + userNames[userIndex]);
  Serial.println("---------------------------------");
}

// =====================================================
// STOP CHARGING SESSION
// AUTO: Relay OFF, Bill calculated and displayed
// =====================================================
void stopCharging() {
  chargingActive = false;

  // AUTO relay OFF — no human needed
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED,  HIGH);

  beep(2, 150);  // Double beep — session end

  // Calculate session duration
  unsigned long duration = (millis() - sessionStart) / 1000;
  int mins = duration / 60;
  int secs = duration % 60;

  // Display final bill
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Energy:");
  lcd.print(totalEnergy, 3);
  lcd.print("kWh");
  lcd.setCursor(0, 1);
  lcd.print("Bill: Rs.");
  lcd.print(totalBill, 2);
  delay(4000);

  // Display session duration
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(mins);
  lcd.print("m ");
  lcd.print(secs);
  lcd.print("s");
  lcd.setCursor(0, 1);
  lcd.print("Thank You!");
  delay(3000);

  Serial.println("---------------------------------");
  Serial.println("Session Ended: " + userNames[currentUser]);
  Serial.print("Energy: "); Serial.print(totalEnergy, 4); Serial.println(" kWh");
  Serial.print("Bill  : Rs."); Serial.println(totalBill, 2);
  Serial.print("Time  : "); Serial.print(mins); Serial.print("m "); Serial.print(secs); Serial.println("s");
  Serial.println("---------------------------------");

  currentUser = -1;

  // Return to idle screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EV Charging Sys");
  lcd.setCursor(0, 1);
  lcd.print("Tap Card...");
}

// =====================================================
// UPDATE CHARGING DISPLAY (called every loop)
// AUTO: Reads current, calculates power, energy, bill
// =====================================================
void updateChargingDisplay() {
  float current = readCurrent();
  float power   = supplyVoltage * current;

  unsigned long elapsed = millis() - sessionStart;
  float hours = elapsed / 3600000.0;

  // Accumulate energy and bill
  totalEnergy = (power * hours) / 1000.0;  // Wh to kWh
  totalBill   = totalEnergy * ratePerUnit;

  // Live display update
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("I:");
  lcd.print(current, 2);
  lcd.print("A P:");
  lcd.print((int)power);
  lcd.print("W");

  lcd.setCursor(0, 1);
  lcd.print("E:");
  lcd.print(totalEnergy, 3);
  lcd.print(" Rs:");
  lcd.print(totalBill, 1);

  // Serial log
  Serial.print("Current: "); Serial.print(current, 2); Serial.print("A | ");
  Serial.print("Power: ");   Serial.print(power, 1);   Serial.print("W | ");
  Serial.print("Energy: ");  Serial.print(totalEnergy, 4); Serial.print("kWh | ");
  Serial.print("Bill: Rs."); Serial.println(totalBill, 2);

  delay(1000);
}

// =====================================================
// READ CURRENT FROM ACS712 (5A version)
// Change 0.185 to 0.100 for 20A version
// =====================================================
float readCurrent() {
  long sum = 0;
  for (int i = 0; i < 100; i++) {
    sum += analogRead(CURRENT_SENSOR);
    delay(1);
  }
  float avgVal  = sum / 100.0;
  float voltage = (avgVal / 1023.0) * 5.0;
  float current = (voltage - 2.5) / 0.185;  // ACS712-5A: 185mV/A
  if (current < 0.05) current = 0;           // Ignore noise
  return current;
}

// =====================================================
// ACCESS DENIED — Unknown card rejected automatically
// =====================================================
void accessDenied() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Access Denied!");
  lcd.setCursor(0, 1);
  lcd.print("Invalid Card");

  beep(3, 100);  // Triple beep alert
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EV Charging Sys");
  lcd.setCursor(0, 1);
  lcd.print("Tap Card...");

  Serial.println("ACCESS DENIED — Unknown card tapped!");
}

// =====================================================
// BUZZER FUNCTION
// times   = number of beeps
// duration = beep length in ms
// =====================================================
void beep(int times, int duration) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER, HIGH);
    delay(duration);
    digitalWrite(BUZZER, LOW);
    if (i < times - 1) delay(120);
  }
}
