#include <SoftwareSerial.h>
#include <BlynkSimpleSerialBLE.h>

// Pin definition for the LED
int ledPin = 13;  // LED connected to digital pin 13

// Create a SoftwareSerial object for Bluetooth communication
SoftwareSerial BTserial(10, 11);  // RX, TX pins (change as needed)

// Blynk authentication token
char auth[] = "YourBlynkAuthToken";  // Replace with your Blynk Auth Token

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output
  BTserial.begin(9600);     // Initialize Bluetooth serial communication at 9600 baud
  Blynk.begin(BTserial, auth);  // Initialize Blynk with Bluetooth serial communication
}

void loop() {
  Blynk.run();  // Run Blynk
}

// Virtual Pin for controlling the LED in the Blynk app
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  if (pinValue == 1) {
    digitalWrite(ledPin, HIGH);  // Turn the LED on
  } else {
    digitalWrite(ledPin, LOW);   // Turn the LED off
  }
}