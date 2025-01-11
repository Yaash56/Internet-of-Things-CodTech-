#include <SoftwareSerial.h>

// Pin definition for the LED
int ledPin = 13;  // LED connected to digital pin 13

// Create a SoftwareSerial object for Bluetooth communication
SoftwareSerial BTserial(10, 11);  // RX, TX pins (change as needed)

// Setup function to initialize the LED and Bluetooth
void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output
  BTserial.begin(9600);     // Initialize Bluetooth serial communication at 9600 baud
  Serial.begin(9600);       // Initialize the serial monitor for debugging
}

void loop() {
  if (BTserial.available()) {
    char receivedChar = BTserial.read();  // Read the received character
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH);  // Turn the LED on
      Serial.println("LED ON");
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW);   // Turn the LED off
      Serial.println("LED OFF");
    }
  }
}