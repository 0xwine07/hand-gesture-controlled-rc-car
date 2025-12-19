#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// nRF24L01 pins
#define CSN_GPIO 8
#define CE_GPIO  7

// Motor driver pins (IN1, IN2, IN3, IN4)
const int MOTOR_PINS[4] = {2, 3, 4, 5};

// RF module
RF24 radio(CE_GPIO, CSN_GPIO);
const byte ADDRESS[6] = "00001";

// Received command
uint8_t rxCommand = 0;

// Function prototype
void controlMotors(const bool state[4]);

void setup() {
  Serial.begin(115200);

  // Motor pins setup
  for (int i = 0; i < 4; i++) {
    pinMode(MOTOR_PINS[i], OUTPUT);
    digitalWrite(MOTOR_PINS[i], LOW);   // Stop motors at boot
  }

  // RF module setup
  if (!radio.begin()) {
    Serial.println("nRF24L01 init failed");
    while (1);
  }

  radio.setChannel(100);
  radio.openReadingPipe(1, ADDRESS);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

  Serial.println("Receiver ready");
}

void loop() {
  if (radio.available()) {
    radio.read(&rxCommand, sizeof(rxCommand));

    Serial.print("Received Command: ");
    Serial.println(rxCommand);

    // Motor states
    const bool forwardState[4]  = {1, 0, 1, 0};
    const bool backwardState[4] = {0, 1, 0, 1};
    const bool leftState[4]     = {1, 0, 0, 1};
    const bool rightState[4]    = {0, 1, 1, 0};
    const bool stopState[4]     = {0, 0, 0, 0};

    switch (rxCommand) {
      case 1:
        Serial.println("Forward");
        controlMotors(forwardState);
        break;

      case 2:
        Serial.println("Backward");
        controlMotors(backwardState);
        break;

      case 3:
        Serial.println("Left");
        controlMotors(leftState);
        break;

      case 4:
        Serial.println("Right");
        controlMotors(rightState);
        break;

      default:
        Serial.println("Stop");
        controlMotors(stopState);
        break;
    }
  }

  delay(200);
}

// Apply motor states
void controlMotors(const bool state[4]) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(MOTOR_PINS[i], state[i]);
  }
}
