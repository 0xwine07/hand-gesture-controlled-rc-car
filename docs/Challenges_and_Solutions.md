## Challenges and Solutions

### NRF24L01 Communication Instability
**Challenge:**  
The NRF24L01 modules occasionally lost communication due to power fluctuations and RF interference.

**Solution:**  
- Added decoupling capacitors across the power pins of the NRF24L01 modules.
- Reduced RF power level to improve stability over short distances.
- Adjusted channel selection to avoid interference in the 2.4 GHz band.

---

### Power Drain from Motor Driver
**Challenge:**  
The L298N motor driver caused rapid battery drain and voltage drops, leading to inconsistent motor behavior.

**Solution:**  
- Replaced zinc-carbon batteries with 18650 lithium-ion batteries to provide higher current capacity and stable voltage output.

---

### Inconsistent Motor Response
**Challenge:**  
Sudden gesture changes resulted in erratic motor movement.

**Solution:**  
- Simplified gesture-to-command mapping logic.
- Added appropriate delays and refined control logic to ensure smoother transitions.

---

### System Integration Issues
**Challenge:**  
Integrating sensors, wireless modules, and motor control introduced timing and coordination challenges.

**Solution:**  
- Modularized firmware into transmitter and receiver roles.
- Improved code structure to ensure predictable and reliable system behavior.
