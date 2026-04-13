# 🚗⚡ Fully Automated EV Charging Station with RFID Based Billing System

---

## 📖 Project Overview

The **Fully Automated EV Charging Station with RFID Based Billing System** is an advanced embedded and IoT-based automation project designed to simplify and modernize electric vehicle (EV) charging infrastructure.

This system uses **RFID technology for user authentication**, **Arduino UNO as the main controller**, **ACS712 current sensor for energy measurement**, and a **relay module for automatic power control**. The system automatically starts charging when a valid RFID card is detected, continuously monitors energy consumption, and generates billing in real time.

All information such as charging status, energy usage, and billing amount is displayed on a **16x2 LCD display**.

👉 The main goal of this project is to eliminate manual intervention and create a **fully automated, secure, and smart EV charging system** suitable for future smart cities.

---

## 📌 Project Architecture / Diagram

![Project Diagram](images/project.jpg)

👉 This diagram represents the complete system including:
- RFID module (user authentication)
- Arduino UNO (control unit)
- Relay module (charging control)
- ACS712 sensor (energy measurement)
- LCD display (output system)

---

## 🎯 Objectives

| No | Objective |
|----|----------|
| 1 | To design a fully automated EV charging station |
| 2 | To implement RFID-based secure authentication |
| 3 | To monitor real-time energy consumption |
| 4 | To calculate billing automatically using Arduino |
| 5 | To control charging using relay module |
| 6 | To reduce human dependency completely |
| 7 | To build a low-cost smart EV infrastructure model |

---

## ⚙️ Features of the System

| Feature | Description |
|--------|------------|
| 🔐 RFID Authentication | Secure user verification using RFID tags |
| ⚡ Automatic Charging | Relay turns ON/OFF automatically |
| 📊 Energy Monitoring | Real-time current and power measurement |
| 💰 Smart Billing | Automatic cost calculation system |
| 📟 LCD Display | Shows live status, energy, and bill |
| 🧠 Embedded Automation | Fully Arduino-controlled system |
| 🔌 Safety Control | Relay-based protection mechanism |
| 📡 IoT Upgrade Ready | Can be extended to cloud system |

---

## 🛠️ Components Used

| Component | Specification | Quantity |
|----------|--------------|----------|
| Arduino UNO | ATmega328P Microcontroller | 1 |
| RFID Reader | RC522 (13.56 MHz) | 1 |
| RFID Cards | UID-based authentication | 2-3 |
| ACS712 Sensor | 5A/20A current sensor | 1 |
| Relay Module | 5V single channel | 1 |
| LCD Display | 16x2 I2C Module | 1 |
| Green LED | Charging indicator | 1 |
| Red LED | Idle/Denied indicator | 1 |
| Buzzer | 5V active buzzer | 1 |
| Power Supply | 5V DC regulated | 1 |
| Jumper Wires | Male/Female | As needed |

---

## 🔌 Circuit Diagram Explanation

![Circuit Diagram](circuit/circuit.jpg)

### 📡 RFID Module (RC522)
- SDA → D10  
- SCK → D13  
- MOSI → D11  
- MISO → D12  
- RST → D9  
- VCC → 3.3V  
- GND → GND  

### ⚡ Relay Module
- IN → D7  
- VCC → 5V  
- GND → GND  

### 📟 LCD (I2C Module)
- SDA → A4  
- SCL → A5  
- VCC → 5V  
- GND → GND  

### 🔋 ACS712 Sensor
- OUT → A0  
- VCC → 5V  
- GND → GND  

---

## 🔄 Working Principle (Step-by-Step)

| Step | Process |
|-----|--------|
| 1 | User taps RFID card on reader |
| 2 | Arduino reads UID from RFID module |
| 3 | UID is verified from stored database |
| 4 | If valid → relay turns ON |
| 5 | Charging starts automatically |
| 6 | ACS712 measures current continuously |
| 7 | Power and energy are calculated in real time |
| 8 | LCD displays live charging status |
| 9 | User taps card again to stop charging |
| 10 | Relay turns OFF and final bill is displayed |

---

## 📊 LCD Display Output

| State | LCD Message |
|------|-------------|
| Idle | “Tap RFID Card” |
| Start | “Charging Started” |
| Active | “Power / Energy / Bill” |
| End | “Final Bill Generated” |
| Denied | “Access Denied” |

---

## 💰 Billing Calculation

### Formulas Used:

- Current (A) = (Vout - 2.5) / 0.185  
- Power (W) = Voltage × Current  
- Energy (kWh) = Power × Time / 1000  
- Bill (₹) = Energy × Rate per kWh  

---

### 📌 Example Calculation:

| Parameter | Value |
|----------|------|
| Voltage | 230V |
| Current | 3A |
| Time | 1 Hour |
| Power | 690W |
| Energy | 0.69 kWh |
| Rate | ₹8/kWh |
| Final Bill | ₹5.52 |

---

## 📷 Output / Results
![Circuit](images/circuit.jpg)

👉 This shows real-time system output including:
- RFID scanning
- LCD display
- Charging status

---

## 📦 Applications

| Sector | Usage |
|-------|------|
| 🚗 EV Charging Stations | Public charging infrastructure |
| 🏙️ Smart Cities | Automated transport systems |
| 🏢 Corporate Buildings | Employee EV charging |
| 🚚 Fleet Management | Vehicle charging control |
| 🏫 Engineering Colleges | IoT/Embedded projects |
| 🔋 Energy Systems | Smart monitoring systems |

---

## 🚀 Future Enhancements

| Feature | Improvement |
|--------|-------------|
| ☁️ Cloud Integration | AWS / Firebase dashboard |
| 📱 Mobile App | Remote monitoring system |
| 💳 Digital Payment | UPI / QR billing |
| ☀️ Solar Charging | Renewable energy integration |
| 📡 IoT System | Real-time remote control |
| 🔐 Advanced Security | OTP / App authentication |

---

## ⚠️ Limitations

- Requires stable power supply  
- Prototype level implementation  
- RFID cards must be pre-registered  
- No cloud system in basic version  

---

## 🏁 Conclusion

The **Fully Automated EV Charging Station with RFID Based Billing System** is a smart and efficient solution for future EV infrastructure.

It eliminates human intervention completely and ensures:
- Secure authentication  
- Accurate energy measurement  
- Automatic billing  
- Low-cost implementation  

This system is highly suitable for **smart cities and modern EV charging networks**.
