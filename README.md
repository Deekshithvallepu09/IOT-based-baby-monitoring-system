# 🌱 Arduino Environment Monitoring System

This project uses an Arduino with multiple sensors to monitor environmental conditions such as temperature, soil moisture, and gas levels. It reacts by activating LEDs, buzzers, and a servo motor, and displays real-time data on an LCD screen.

---

## 🚀 Features

- 📊 **LCD Display** showing temperature, soil moisture, and gas levels  
- 🌡️ **Temperature Alert** triggers LED, servo motion, and a melody  
- 💧 **Soil Moisture Alert** triggers a buzzer if moisture is high  
- 🛑 **Gas Level Alert** triggers buzzer for gas detection  
- 🎵 **Buzzer Sound Alerts** and a servo that moves on high temperature  

---

## 🔌 Hardware Requirements

- Arduino Uno or compatible board  
- TMP36 Temperature Sensor (A0)  
- Soil Moisture Sensor (A2)  
- MQ-x Gas Sensor (A1)  
- Buzzer (D10)  
- LED (D9)  
- Servo Motor (D6)  
- 16x2 LCD Display with 6-pin connection:  
  - RS → D12  
  - EN → D11  
  - D4 → D5  
  - D5 → D4  
  - D6 → D3  
  - D7 → D2  
- Breadboard and jumper wires  

---

## 🧠 Code Overview

**Libraries Used:**
- `LiquidCrystal` for LCD display
- `Servo` for servo motor control

**Main Functions:**
- `moveServoFor10Sec()` – oscillates servo motor for 10 seconds  
- `beepBuzzer(seconds)` – sounds buzzer for specified time  
- `playHappySleepSound()` – plays a melody  

---

## 💻 How to Run in VS Code

1. Install [Arduino IDE](https://www.arduino.cc/en/software)  
2. Install [Visual Studio Code](https://code.visualstudio.com)  
3. Install the **Arduino extension** in VS Code  
4. Connect your Arduino via USB  
5. Open the folder in VS Code  
6. Press `Ctrl+Shift+P` and select:  
   - `Arduino: Select Board` → Choose "Arduino Uno"  
   - `Arduino: Select Serial Port` → Choose correct COM port  
7. Click ✓ to compile, → to upload  

---

## 🧪 Sensor Calibration Notes

- **TMP36** outputs 0.5V at 0°C, 10mV per °C  
- **Soil Sensor** mapping might need calibration:  
  - Dry ≈ 1023, Wet ≈ 300 (reverse-mapped)  
- **Gas Sensor** should be tested and scaled based on sensor type (e.g. MQ-2, MQ-7)  

---

## ⚠️ Thresholds & Alerts

| Parameter        | Threshold      | Action Triggered                |
|------------------|----------------|---------------------------------|
| Temperature      | ≥ 40°C         | LED ON, Servo motion, Melody    |
| Soil Moisture    | > 40%          | Buzzer for 3 sec                |
| Gas Concentration| > 30%          | Buzzer beeps twice              |

---

## 📷 Optional Add-ons

- Add a DHT11/DHT22 for better humidity sensing  
- Add EEPROM for saving calibration data  
- Add Serial Monitor output for debugging  

---

## 📄 License

This project is open-source and free to use for educational and prototyping purposes.
