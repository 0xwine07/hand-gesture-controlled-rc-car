## System Working

The hand gesture controlled RC car operates using a two-unit architecture consisting of a transmitter and a receiver.

---

### Transmitter Unit
- An MPU6050 motion sensor continuously measures hand orientation and movement.
- An Arduino Nano reads the accelerometer data and processes it to detect predefined gestures.
- Each gesture is mapped to a specific movement command (forward, backward, left, right, or stop).
- The command is transmitted wirelessly using an NRF24L01 module operating in the 2.4 GHz ISM band.

---

### Wireless Communication
- The NRF24L01 modules provide short-range, low-latency communication between the transmitter and receiver.
- Communication parameters such as channel selection and power level are configured to improve reliability and reduce interference.

---

### Receiver Unit
- The receiver Arduino (UNO) listens for incoming wireless commands.
- Upon receiving a command, the Arduino interprets it and generates corresponding control signals.
- These signals are sent to an L298N motor driver, which controls the direction of rotation of the DC motors.

---

### Motor Control
- The L298N motor driver drives the motors based on the received command.
- Different combinations of motor inputs enable forward, backward, left, right, and stop motions.
- The motors continue executing the command until a new command is received.

---

### Overall Operation Flow
1. Hand gesture detected by MPU6050
2. Gesture processed by Arduino Nano
3. Command transmitted wirelessly
4. Command received by Arduino UNO
5. Motor driver actuates motors accordingly
