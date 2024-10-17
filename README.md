
<h3 align="center">
  AVR Smart Home: Final Project
</h3>


---

## 🏠 Project Description

In this project, we create a **Smart Home System** using AVR microcontroller and peripheral components like Keypad, LCD, LEDs, DC motors, Temperature sensor, LDR, and Buzzer. The system is designed to ensure **home security** and **temperature control**, offering various functionalities:

### 🚪 **Home Access Security**:
1. **Password Authentication**: 
    - Use a **keypad** (2x2) to enter the password and an **LCD** to display prompts.
    - If the **password is correct**:
      - Turn on a **green LED**, display "Welcome Home" on the LCD, and open the **door** using a DC motor.
    - If the **password is wrong**:
      - Turn on a **red LED**, display "Wrong password" on the LCD, and give another chance to enter the password.
    - The user has **three attempts**. After three wrong attempts:
      - An **alarm** will sound using a **buzzer**, and the red LED will **blink** for 5 seconds.

### 🌡️ **Temperature Control**:
2. **Threshold Temperature Control**: 
    - Monitor temperature using a **temperature sensor**.
    - If the **temperature exceeds 25°C**:
      - Turn on a **fan** (using DC motor) until the temperature drops below the threshold.
    - If the **temperature exceeds 50°C**:
      - Trigger an **alarm** using a buzzer, display "Fire" on the LCD, and turn off the alarm manually using a **push button**.
    - The current **temperature** is displayed on the **LCD** at all times.

### 💡 **Light Control using LDR**:
3. **LDR-based LED control**:
    - Use an **LDR** to control **5 LEDs**. The brightness level from the LDR determines how many LEDs light up.

---

## 🛠️ **Components Used**

- AVR Microcontroller
- **Keypad** (2x2)
- **LCD** display
- **LEDs** (Red, Green, and 5 others for brightness control)
- **DC Motor** (for the door and fan)
- **Buzzer** (for alarm)
- **Temperature Sensor**
- **LDR** (Light Dependent Resistor)
- **Push Button**

---

## 🔧 **Functional Requirements**

### **1. Security System:**
- **Password Authentication** with 3 attempts.
- Turn on a **red LED** and display "Wrong Password" on the **LCD** if the password is wrong.
- Turn on a **green LED**, display "Welcome Home" on the **LCD**, and **open the door** if the password is correct.
- After 3 wrong attempts, sound the **alarm** and blink the **red LED** for 5 seconds.

### **2. Temperature Control:**
- Use a **DC motor** to control a fan based on the **temperature threshold**.
- Turn on the **fan** when the temperature exceeds **25°C**, and turn it off when it drops below.
- Sound an **alarm** and display "Fire" on the **LCD** if the temperature exceeds **50°C**, requiring manual reset via a **push button**.

### **3. LDR-based LED Control:**
- Use the **LDR** to control the number of **LEDs** that are on based on the light intensity.

---

## ⚙️ **Bonus Features**
- Implement **ADC Asynchronous** conversion and trigger **ISR** upon end-of-conversion.
- Handle the **fire alarm push button** using an **External Interrupt**.
- Replace the **DC motor** with a **Stepper motor** and rotate it **90 degrees** for door control.

---

### 🛠 **Tools**

<p align="left">
  <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> 
    <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="C Language" width="40" height="40"/> 
  </a>
</p>


---


