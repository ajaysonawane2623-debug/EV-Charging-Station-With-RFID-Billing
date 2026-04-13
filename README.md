🚗⚡ Fully Automated EV Charging Station with RFID Based Billing System
📖 Project Overview

The Fully Automated EV Charging Station with RFID Based Billing System is an embedded IoT-based solution designed to automate EV charging using Arduino + RFID technology.

The system identifies users using RFID cards, controls charging automatically via relay, measures energy consumption using ACS712 current sensor, and calculates billing in real-time. All information is displayed on a 16x2 LCD display.

👉 This system is designed for:

Smart cities
Public EV charging stations
Private parking systems
Corporate EV infrastructure
🤖 Fully Automated System (No Human Required)
Process	Traditional System	This Project (Automated)
User Authentication	Security guard checks ID	RFID auto verification
Start Charging	Manual switch ON	Relay auto ON
Energy Measurement	Manual meter reading	ACS712 automatic
Billing	Manual calculation	Arduino real-time billing
Stop Charging	Manual OFF switch	RFID tap auto OFF
Access Control	Human check	UID-based system
🎯 Objectives
To design a fully automated EV charging system using RFID
To implement secure user authentication (RFID RC522)
To measure real-time energy consumption
To calculate automatic billing
To control relay-based charging system
To eliminate human intervention completely
To build low-cost smart EV infrastructure
⚙️ Features
🔐 RFID-based authentication
⚡ Automatic charging control
📊 Real-time energy monitoring
💰 Automatic billing calculation
📟 LCD display output
🧠 Fully embedded automation
🔌 Relay-based safe switching
📡 Scalable IoT upgrade support
🛠️ Components Used
Component	Specification	Qty
Arduino UNO	ATmega328P	1
RFID RC522	13.56 MHz	1
RFID Cards	UID based	2-3
ACS712 Sensor	5A/20A	1
LCD Display	16x2 I2C	1
Relay Module	5V	1
LEDs	Red/Green	2
Buzzer	Active	1
Jumper Wires	Male/Female	As needed
Power Supply	5V DC	1
🔌 Circuit Connections
📡 RFID (RC522)
SDA → D10
SCK → D13
MOSI → D11
MISO → D12
RST → D9
VCC → 3.3V
GND → GND
⚡ Relay Module
IN → D7
VCC → 5V
GND → GND
📟 LCD (I2C)
SDA → A4
SCL → A5
🔋 Sensors
ACS712 → A0
💡 Indicators
Green LED → D6
Red LED → D5
Buzzer → D4
🔄 Working Principle
1️⃣ RFID Authentication

User taps RFID card → Arduino reads UID → verifies database

2️⃣ Charging Start
Relay ON
Green LED ON
LCD shows “Charging Started”
Buzzer beep once
3️⃣ Energy Monitoring
ACS712 continuously measures current
Power & energy calculated in real-time
4️⃣ Billing System
Energy (kWh) = P × Time / 1000
Bill = Energy × Rate
5️⃣ Charging Stop

User taps card again → relay OFF → final bill shown

🔁 System Flow
RFID Tap → UID Read → Verify → Start Charging → Measure Energy → Calculate Bill → Display → Stop Charging
📊 LCD Output States
State	Display
Idle	Tap Card
Start	Charging Start
Active	Power + Energy + Bill
End	Final Bill
Denied	Access Denied
💰 Billing Formula
Current = (Vout - 2.5) / 0.185
Power = V × I
Energy = P × Time / 1000
Bill = Energy × Rate
📦 Applications
EV charging stations
Smart parking systems
Smart city projects
Corporate EV infrastructure
College IoT projects
🚀 Future Enhancements
GSM / WiFi billing (SMS alerts)
Mobile app integration
Cloud dashboard (IoT)
Prepaid charging system
QR payment integration
Multiple charging ports
🏁 Conclusion

This project demonstrates a fully automated EV charging system with RFID authentication and real-time billing. It removes human dependency completely and provides a smart, scalable, and efficient solution for future EV infrastructure.

📜 License

This project is licensed under the MIT License.

⭐ Support

If you like this project:

⭐ Star repository
🍴 Fork it
🔧 Use in academic projects
