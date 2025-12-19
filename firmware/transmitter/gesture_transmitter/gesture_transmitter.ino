#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Wire.h"
#include "MPU6050.h"

// nRF24L01 pins
#define CSN_GPIO 8
#define CE_GPIO  7

RF24 radio(CE_GPIO, CSN_GPIO);
MPU6050 accelgyro;

// Acceleration values (X and Y axes)
int16_t ax, ay;

// RF communication
const byte address[6] = "00001";
uint8_t Tx_command = 0;

void setup() {
  Serial.begin(115200);

  // RF module setup
  radio.begin();
  radio.setChannel(100);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  // MPU6050 setup
  Wire.begin();
  accelgyro.initialize();

  Serial.println("Transmitter ready");
}

void loop() {
  // Read accelerometer data
  accelgyro.getMotion6(&ax, &ay, nullptr, nullptr, nullptr, nullptr);

  // Gesture-to-command mapping
  if (ay <= -4000) {
    Tx_command = 1;        // Forward
  } else if (ay >= 4000) {
    Tx_command = 2;        // Backward
  } else if (ax >= 4000) {
    Tx_command = 3;        // Left
  } else if (ax <= -4000) {
    Tx_command = 4;        // Right
  } else {
    Tx_command = 0;        // Stop
  }

  Serial.println(Tx_command);

  // Transmit command
  radio.write(&Tx_command, sizeof(Tx_command));

  delay(100);
}
