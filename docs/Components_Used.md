## Components Used

### Transmitter Unit
- **Arduino Nano**  
  Used to process motion data from the sensor and generate control commands.

- **MPU6050 Accelerometer and Gyroscope**  
  Used to detect hand orientation and movement for gesture recognition.

- **NRF24L01 Wireless Transceiver Module**  
  Used to transmit gesture-based commands wirelessly to the receiver unit.

---

### Receiver Unit
- **Arduino UNO**  
  Used to receive wireless commands and control the motor driver.

- **NRF24L01 Wireless Transceiver Module**  
  Used to receive command data from the transmitter.

- **L298N Dual H-Bridge Motor Driver**  
  Used to control the direction and operation of the DC motors.

- **DC Motors and Car Chassis**  
  Used to convert electrical control signals into mechanical movement.

---

### Power and Supporting Components
- **18650 Lithium-Ion Batteries**  
  Used to provide sufficient current and stable voltage for motors and control circuitry.

- **Decoupling Capacitor (47 µF)**  
  Added across the power pins of the NRF24L01 modules to stabilize voltage and reduce communication instability.

- **Jumper Wires**  
  Used for electrical connections between components.

- **Breadboard (during prototyping)**  
  Used for temporary circuit assembly and testing.

---

### Tools
- **Soldering Iron**  
  Used to make permanent electrical connections.

- **Multimeter**  
  Used for continuity checks and voltage measurements during debugging.
