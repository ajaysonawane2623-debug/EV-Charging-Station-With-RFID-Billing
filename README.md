# 🚗⚡ Fully Automated EV Charging Station with RFID Based Billing System

---

## 📖 Project Overview
The **EV Charging Station with RFID Billing System** is a smart embedded system that automates EV charging using RFID authentication. It controls charging, measures energy, and calculates billing automatically without human intervention.

---

## 🎯 Objectives

| No | Objective |
|----|----------|
| 1 | To design automated EV charging system |
| 2 | To implement RFID-based authentication |
| 3 | To measure real-time energy consumption |
| 4 | To calculate automatic billing |
| 5 | To control charging using relay |
| 6 | To reduce human intervention |

---

## ⚙️ Features

| Feature | Description |
|--------|------------|
| 🔐 RFID Authentication | User identification using RFID |
| ⚡ Auto Charging | Relay-based automatic control |
| 📊 Energy Monitoring | Real-time current measurement |
| 💰 Auto Billing | Arduino-based calculation |
| 📟 LCD Display | Live system status |
| 🧠 Automation | Fully embedded system |
| 🔌 Safety Control | Relay protection system |

---

## 🛠️ Components Used

| Component | Specification | Quantity |
|----------|--------------|----------|
| Arduino UNO | ATmega328P | 1 |
| RFID Reader | RC522 (13.56 MHz) | 1 |
| RFID Cards | UID based | 2-3 |
| ACS712 Sensor | 5A/20A | 1 |
| Relay Module | 5V | 1 |
| LCD Display | 16x2 I2C | 1 |
| LED (Green/Red) | Indicator | 2 |
| Buzzer | 5V Active | 1 |
| Power Supply | 5V DC | 1 |

---

## 🔌 Circuit Connections

| Module | Pin | Connection |
|--------|-----|------------|
| RFID RC522 | SDA | D10 |
| RFID RC522 | SCK | D13 |
| RFID RC522 | MOSI | D11 |
| RFID RC522 | MISO | D12 |
| RFID RC522 | RST | D9 |
| RFID RC522 | VCC | 3.3V |
| RFID RC522 | GND | GND |
| Relay | IN | D7 |
| LCD (I2C) | SDA | A4 |
| LCD (I2C) | SCL | A5 |
| ACS712 | OUT | A0 |
| Green LED | + | D6 |
| Red LED | + | D5 |
| Buzzer | + | D4 |

---

## 🔄 Working Principle

| Step | Process |
|-----|--------|
| 1 | RFID card scan |
| 2 | UID verification |
| 3 | Relay ON (charging starts) |
| 4 | ACS712 measures current |
| 5 | Power & energy calculation |
| 6 | LCD shows live data |
| 7 | RFID tap again |
| 8 | Relay OFF (charging stops) |
| 9 | Final bill display |

---

## 📊 LCD Output States

| State | Display Message |
|------|----------------|
| Idle | Tap RFID Card |
| Start | Charging Started |
| Active | Power + Energy + Bill |
| End | Final Bill |
| Denied | Access Denied |

---

## 💰 Billing Formula

| Parameter | Formula |
|-----------|--------|
| Current | (Vout - 2.5) / 0.185 |
| Power | V × I |
| Energy | P × Time / 1000 |
| Bill | Energy × Rate |

---

## 📦 Applications

| Area | Use |
|-----|----|
| EV Stations | Public charging |
| Parking Systems | Smart parking |
| Smart Cities | Infrastructure |
| Colleges | IoT projects |
| Industries | Fleet charging |

---

## 🚀 Future Enhancements

| Feature | Upgrade |
|--------|--------|
| Cloud System | AWS / Firebase integration |
| Mobile App | Remote monitoring |
| Payment | UPI / QR system |
| Solar Charging | Renewable integration |
| Dashboard | Live analytics |

---

## 🏁 Conclusion
The system provides a **fully automated EV charging solution** using RFID technology. It ensures secure authentication, real-time billing, and eliminates human intervention completely.

---

## 📜 License
MIT License

---

## ⭐ Support
| Action | Description |
|-------|------------|
| ⭐ Star | Support project |
| 🍴 Fork | Improve project |
| 🔧 Use | Academic purpose |
