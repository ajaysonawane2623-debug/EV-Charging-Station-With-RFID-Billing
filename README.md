⚡ Fully Automated EV Charging Station with RFID Based Billing System

📖 Project Overview
The Fully Automated EV Charging Station with RFID Based Billing System is an embedded system designed to automate the electric vehicle (EV) charging process using an Arduino microcontroller and RFID authentication technology.
The system identifies registered users via RFID cards, initiates the charging session automatically, measures energy consumed using a current sensor (ACS712), calculates the bill in real-time, and displays the information on a 16x2 LCD screen. Charging is controlled through a relay module which switches the power supply ON/OFF based on session status.
This project targets smart city infrastructure, public charging stations, and private EV parking lots — offering a secure, cashless, and fully automated billing solution without any manual intervention.

🤖 Without Human Intervention — Fully Automated
This is the core feature of the project. The entire charging process runs automatically without any human operator or manual involvement at any stage:
StageTraditional SystemThis System (Automated)User AuthenticationSecurity guard checks IDRFID card auto-verified by ArduinoStarting ChargerOperator manually switches ONRelay auto-activates on valid cardEnergy MeasurementManual meter readingACS712 sensor reads automaticallyBill CalculationManual calculation by operatorArduino calculates in real-timeBill DisplayPaper receipt / manual entryAuto-displayed on LCD instantlyStopping ChargerOperator manually switches OFFRelay auto-deactivates on card tapAccess ControlHuman security checkUID-based auto access controlFraud PreventionManual verificationOnly registered UIDs are accepted
🔑 Key Automation Points:

No cashier needed — billing is 100% automatic
No security guard needed — RFID handles access control
No operator needed — relay switches power ON/OFF by itself
No manual meter reading — ACS712 reads current continuously
No manual calculation — Arduino computes energy and bill instantly
24x7 operation — system works round the clock without any human presence
Zero human error — all measurements and calculations are done by the microcontroller


🎯 Objectives

To design a fully automated EV charging system using RFID authentication
To implement secure user identification using RFID RC522 module and UID-based access
To measure real-time energy consumption using current and voltage sensors
To automatically calculate and display billing information on an LCD screen
To control the charging relay automatically based on session start/stop
To develop a low-cost, reliable, and scalable smart charging solution
To eliminate the need for any human operator at the charging station


🧠 Working Principle

RFID Authentication — When the user taps their RFID card on the RC522 reader, Arduino reads the card's unique UID and verifies it against a pre-stored registered UID database.
Session Start — If authentication is successful:

The relay activates and connects the EV charger to the power supply
A green LED turns ON
The buzzer beeps once as confirmation
The LCD displays "Charging Started" with user details


Energy Metering — During the session:

The ACS712 current sensor measures the current drawn continuously
Power is calculated as: P (W) = V × I
Energy is accumulated as: E (kWh) = P × Time / 3600000


Real-time Billing — The system calculates:

Total energy consumed (kWh)
Bill amount = Energy (kWh) × Rate (₹/kWh)
All data displayed live on LCD


Session End — When the user taps the card again:

Relay deactivates, power supply disconnects
Final bill is displayed on LCD
Red LED turns ON
Buzzer beeps twice




✅ All of the above steps happen automatically — no human involvement required at any point.


🔄 System Flow
[ Tap RFID Card ]
        |
        v
[ Read UID from RC522 ]
        |
        v
[ Check UID in Database ]
       / \
      /   \
   YES     NO
    |       |
    v       v
[ Relay  [ Access
  ON ]   Denied ]
    |       |
    v       v
[ Charging  [ Red LED
  Starts ]   Buzzer ]
    |
    v
[ ACS712 Measures Current ]
    |
    v
[ Calculate Power & Energy ]
    |
    v
[ Display on LCD - Live Update ]
    |
    v
[ Tap Card Again ]
    |
    v
[ Relay OFF - Charging Stops ]
    |
    v
[ Calculate Final Bill ]
    |
    v
[ Display Bill on LCD ]
    |
    v
[ Session Complete ]

🛒 Components Required
S.NoComponentSpecificationQuantity1Arduino UNOATmega328P, 16 MHz12RFID RC522 Module13.56 MHz, SPI13RFID Cards / TagsUID based2-34ACS712 Current Sensor5A or 20A version1516x2 LCD DisplayHD44780 compatible16I2C Module (PCF8574)For LCD175V Relay ModuleSingle channel18Green LED5mm19Red LED5mm110BuzzerActive, 5V111Resistors220Ω for LEDs212Power Supply5V/2A DC113Breadboard830 tie points114Jumper WiresMale-Male, Male-FemaleAs needed

🔌 Circuit Diagram
                          +5V      GND
                           |        |
           +---------------+--------+---------------+
           |           ARDUINO UNO                  |
           |                                        |
           |  [A0]------- ACS712 (AOUT)             |
           |                                        |
           |  [D10]------ RC522 (SDA/SS)            |
           |  [D13]------ RC522 (SCK)               |
           |  [D11]------ RC522 (MOSI)              |
           |  [D12]------ RC522 (MISO)              |
           |  [D9] ------- RC522 (RST)              |
           |                                        |
           |  [A4/SDA]--- I2C LCD (SDA)             |
           |  [A5/SCL]--- I2C LCD (SCL)             |
           |                                        |
           |  [D7] ------- Relay (IN)               |
           |  [D6] ------- Green LED (+)            |
           |  [D5] ------- Red LED (+)              |
           |  [D4] ------- Buzzer (+)               |
           +----------------------------------------+


   RC522 MODULE               ACS712 SENSOR
   +-----------+              +----------+
   | SDA  -->D10|             | VCC --> 5V|
   | SCK  -->D13|             | GND --> G |
   | MOSI -->D11|             | OUT --> A0|
   | MISO -->D12|             +----------+
   | RST  --> D9|
   | VCC  --> 3.3V|           RELAY MODULE
   | GND  --> GND|            +----------+
   +-----------+              | VCC --> 5V|
                              | GND --> G |
   LCD (I2C)                  | IN  --> D7|
   +-----------+              | COM --> EV Charger|
   | SDA  --> A4|             | NO  --> Power Supply|
   | SCL  --> A5|             +----------+
   | VCC  --> 5V|
   | GND  --> GND|            LEDs & BUZZER
   +-----------+              Green LED: D6 --> 220Ω --> GND
                              Red LED:   D5 --> 220Ω --> GND
                              Buzzer:    D4 --> GND

📌 Pin Configuration
Arduino PinConnected ToPurposeD10 (SS)RC522 SDARFID SPI Slave SelectD13 (SCK)RC522 SCKSPI ClockD11 (MOSI)RC522 MOSISPI Master OutD12 (MISO)RC522 MISOSPI Master InD9RC522 RSTRFID ResetA4 (SDA)I2C LCD SDALCD DataA5 (SCL)I2C LCD SCLLCD ClockA0ACS712 AOUTCurrent Sensor Analog InputD7Relay INRelay ControlD6Green LEDCharging Active IndicatorD5Red LEDIdle / Access DeniedD4BuzzerAudio Alert3.3VRC522 VCCRFID Power5VRelay, LCD, ACS712 VCCComponent PowerGNDAll GNDCommon Ground

Required Libraries
Install in Arduino IDE via Tools → Manage Libraries:
MFRC522           by GithubCommunity      (RFID RC522)
LiquidCrystal_I2C by Frank de Brabander  (I2C LCD)
Wire              (Built-in)
SPI               (Built-in)

🖥️ Final Output
System Output at Each Stage (Fully Automatic — No Human Needed):
1. Idle State:
+----------------+
| EV Charging Sys|
| Tap Card...    |
+----------------+

Red LED ON, Relay OFF
System continuously polls for RFID — no human watching needed


2. Valid Card Tap — Auto session start:
+----------------+
| Hi, Rahul      |
| Charging Start!|
+----------------+

Green LED ON, Red LED OFF
Relay AUTO ON — EV charger connected
Buzzer beeps once — no operator needed


3. During Charging — Auto live monitoring:
+----------------+
| I:3.20A P:736W |
| E:0.020 Rs:0.2 |
+----------------+

Current, Power, Energy, Bill — auto updated every second


4. Session End — Auto bill generated:
+----------------+
| Energy:0.045kWh|
| Bill: Rs.0.36  |
+----------------+

Relay AUTO OFF — charger disconnected
Final bill auto-calculated and displayed
Buzzer beeps twice — system auto-returns to idle


5. Access Denied — Auto rejection:
+----------------+
| Access Denied! |
| Invalid Card   |
+----------------+

Unknown card auto-rejected — no security guard needed
Buzzer beeps 3 times, system auto-resets


📊 LCD Display Output
StateLine 1Line 2IdleEV Charging SysTap Card...Auth OKHi, [UserName]Charging Start!ChargingI:X.XXA P:XXXWE:X.XXX Rs:X.XSession EndEnergy:X.XXXkWhBill: Rs.X.XXDeniedAccess Denied!Invalid Card

⚙️ Technical Specifications
ParameterValueMicrocontrollerArduino UNO (ATmega328P)Clock Speed16 MHzRFID ModuleMFRC522 (RC522)RFID Frequency13.56 MHzRFID InterfaceSPI ProtocolRFID Read Range~3–5 cmCurrent SensorACS712 (5A version)Sensor Sensitivity185 mV/ASupply Voltage (simulated)230V ACRelay Load Rating10A / 250V ACLCD16x2 HD44780 via I2CI2C Address0x27 (default)Operating Voltage5V DCBilling RateRs.8/kWh (configurable)Human Operators Required0 (Zero)

💰 Billing Calculation
Current (A)   = (ACS712 Output Voltage - 2.5V) / 0.185

Power (W)     = Supply Voltage (V) × Current (A)

Energy (kWh)  = Power (W) × Time (hours) / 1000

Bill (Rs.)    = Energy (kWh) × Rate (Rs./kWh)
Example:

Current measured: 3.2A
Supply Voltage: 230V
Charging Time: 0.5 hours
Power = 230 × 3.2 = 736 W
Energy = 736 × 0.5 / 1000 = 0.368 kWh
Bill = 0.368 × 8 = Rs. 2.94


All calculations done automatically by Arduino — no human involvement needed.


🏙️ Applications

Public EV charging stations in parking lots and malls
Apartment complex and housing society EV charging infrastructure
Office building and corporate campus EV charging management
Smart city and government EV charging network projects
Prepaid / subscription-based private EV charging services
College and university EV charging lab projects
Unmanned / unattended charging stations operating 24x7


🚀 Future Enhancements

 GSM/WiFi module (SIM800L / ESP8266) for SMS/WhatsApp billing receipt
 EEPROM storage to save usage history of each user
 Prepaid balance system — deduct from stored balance per session
 Mobile App integration via Bluetooth (HC-05) for remote monitoring
 Multiple charging slots with individual metering
 QR Code display for digital payment (UPI)
 Cloud dashboard for operator monitoring (ThingSpeak / Blynk)
 Over-current protection with automatic relay trip


🏁 Conclusion
The Fully Automated EV Charging Station with RFID Based Billing System presents an efficient, secure, and cost-effective solution for modern EV charging infrastructure. The system is 100% automated — no human operator is required at any stage of the process.
By integrating RFID authentication, real-time energy metering via ACS712, relay-based automatic power control, and LCD-based billing display, this project demonstrates a practical embedded systems application aligned with the growing demand for smart EV charging solutions.
Users simply tap their registered RFID card to start and stop charging, and the system handles authentication, metering, and billing entirely on its own — 24 hours a day, 7 days a week, without any human presence. This makes it ideal for deployment in smart cities, residential complexes, and corporate campuses across India and globally.
