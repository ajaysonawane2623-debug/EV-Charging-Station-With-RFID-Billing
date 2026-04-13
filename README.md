🚗⚡ EV Charging Station with RFID Billing System
📌 Project Overview

The EV Charging Station with RFID Billing System is a smart and automated charging solution designed for electric vehicles. The system uses RFID technology to identify users, control charging access, and automatically calculate billing based on energy consumption. This project eliminates manual intervention and provides a fully automated, secure, and efficient EV charging experience.

This system is highly useful in public EV charging stations, parking systems, and fleet management systems where multiple users need controlled and trackable charging access.

🎯 Objective
To design a smart EV charging system using RFID technology
To enable automatic user authentication
To control EV charging using relay module automation
To calculate real-time energy consumption and billing
To reduce manual work and improve charging efficiency
To build a low-cost IoT-based EV infrastructure model
⚙️ Features

🔐 RFID-based secure authentication system
⚡ Automatic charging ON/OFF control
📊 Real-time energy monitoring
💰 Automated billing calculation system
📟 LCD display for status and billing details
🧠 Microcontroller-based smart decision system
🔌 Safe relay-controlled power management
📡 Scalable for IoT integration

🛠️ Components Used
Component	Description
Arduino UNO / ESP32	Main microcontroller
RFID Reader (RC522)	Reads RFID card/tag
RFID Tags/Cards	User identification
Relay Module	Controls charging ON/OFF
Current Sensor (ACS712 / similar)	Measures energy usage
Voltage Sensor	Monitors supply voltage
LCD Display (16x2 I2C)	Displays system status
Power Supply Unit	Provides required power
Jumper Wires	Connections
Breadboard	Prototyping
🔌 Circuit Diagram Explanation

The system is connected as follows:

📡 RFID Module (RC522)
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
📟 LCD Display (I2C)
SDA → A4
SCL → A5
VCC → 5V
GND → GND
🔋 Sensor Unit
Current sensor → Analog pin (A0)
Voltage sensor → Analog pin (A1)
🔄 Working Principle
User scans RFID card
Microcontroller verifies user ID
If valid → relay activates charging system
Current and voltage sensors measure energy usage
System calculates total power consumption
Billing amount is calculated automatically
LCD displays:
User status
Charging status
Total bill
After completion → relay turns OFF charging
📦 Applications

🚗 EV charging stations
🏢 Smart parking systems
🚚 Fleet vehicle charging management
🏫 Educational IoT demonstrations
🏙️ Smart city infrastructure
🔋 Energy monitoring systems

📋 Installation & Setup
Step 1: Hardware Setup

Connect all components according to the circuit diagram.

Step 2: Software Setup
Install Arduino IDE
Add required libraries:
MFRC522 (RFID)
LiquidCrystal_I2C
Select board (Arduino UNO / ESP32)
Step 3: Upload Code

Upload main.ino to the microcontroller.

Step 4: Run System
Scan RFID card
Observe LCD output
Monitor billing system
💻 Code Overview
if (rfidDetected == true) {
    authenticateUser();
    digitalWrite(relay, HIGH); // Start charging
    measureEnergy();
    calculateBilling();
    displayOnLCD();
}
📊 System Advantages

✔ Fully automated charging system
✔ No manual billing required
✔ Secure RFID authentication
✔ Accurate energy measurement
✔ Low-cost implementation
✔ Scalable for real-world deployment

⚠️ Limitations
Requires stable power supply
Limited to prototype level without IoT cloud integration
RFID cards must be pre-registered
🚀 Future Enhancements
Cloud-based billing system (AWS / Firebase)
Mobile app integration
QR code-based charging
Solar-powered EV charging station
Real-time remote monitoring dashboard
📷 Output Section

📌 Add images of:

Working model
LCD display
RFID scanning
Circuit setup
📜 License

This project is licensed under the MIT License.
You are free to use, modify, and distribute this project with proper attribution.

⭐ Support

If you find this project useful:

⭐ Star the repository
🍴 Fork it for improvements
🔧 Use it in your academic projects
