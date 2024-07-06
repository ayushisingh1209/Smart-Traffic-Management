// Define the pins for the LEDs
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Define the reset pin (RST_PIN) on the RFID reader module
#define SS_PIN          10         // Define the slave select pin (SS_PIN) on the RFID reader module

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create an MFRC522 instance
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  SPI.begin();          // Initialize SPI communication
  mfrc522.PCD_Init();   // Initialize MFRC522
  // Set the LED pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
   //Check if serial data is available
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Tag Detected"); // Sending a string indicating tag detection
  }
  if (Serial.available() > 0) {
    // Read the incoming byte
    char receivedChar = Serial.read();

    // Blink LED1 if 'a' is received
    if (receivedChar == 'a') {
      int duration = Serial.parseInt();
      digitalWrite(ledPin1, HIGH);
      delay(duration * 1000);
      digitalWrite(ledPin1, LOW);
    }
    // Blink LED2 if 'b' is received
    else if (receivedChar == 'b') {
      int duration = Serial.parseInt();
      digitalWrite(ledPin2, HIGH);
      delay(duration * 1000);
      digitalWrite(ledPin2, LOW);
    }
    // Blink LED3 if 'c' is received
    else if (receivedChar == 'c') {
      int duration = Serial.parseInt();
      digitalWrite(ledPin3, HIGH);
      delay(duration * 1000);
      digitalWrite(ledPin3, LOW);
    }
    // Blink LED4 if 'd' is received
    else if (receivedChar == 'd') {
      int duration = Serial.parseInt();
      digitalWrite(ledPin4, HIGH);
      delay(duration * 1000);
      digitalWrite(ledPin4, LOW);
    }
  }
}
