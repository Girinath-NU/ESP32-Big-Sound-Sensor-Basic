# Sound Sensor Detection with Debouncing on ESP32

This project demonstrates how to use a sound sensor with an ESP32 to detect sound events. The code reads the digital output from the sensor and prints a message to the Serial Monitor when sound is detected. To prevent multiple detections from a single sound event, a debounce mechanism is implemented.

## Features

- Detects sound via a digital output from the sound sensor.
- Implements a debounce mechanism to avoid multiple detections from a single sound event.
- Prints "Sound Detected!" to the Serial Monitor when a sound event occurs.

## Hardware Requirements

- ESP32 or ESP8266
- Sound sensor module (with a digital output pin)
- Jumper wires
- Breadboard (optional)

## Circuit Diagram

| ESP32 Pin | Sound Sensor Pin   |
|-----------|--------------------|
| GPIO 27   | Digital Output Pin  |
| GND       | GND                |
| 3.3V      | VCC                |

Make sure to connect the sensor's digital output pin to the defined GPIO pin in the code (`GPIO 27`).

## Code Explanation

1. **Pin Definition:**
   - `#define DIGITAL_PIN 27`: Defines the GPIO pin (27) that is connected to the sound sensor’s digital output.

2. **Debounce Mechanism:**
   - `#define DEBOUNCE_DELAY 1000`: Defines a 1000-millisecond delay to avoid repeated detection of the same sound event.
   - `unsigned long lastDetectionTime`: Stores the last time a sound event was detected to ensure no immediate repeated detections.

3. **Sound Detection Logic:**
   - The code uses `digitalRead(DIGITAL_PIN)` to check if the sound sensor has detected a sound.
   - If sound is detected (i.e., digital value is HIGH) and enough time (defined by the debounce delay) has passed since the last detection, it prints "Sound Detected!" to the Serial Monitor.

## How to Use

1. **Wiring:**
   - Connect the sound sensor to the ESP32 as per the circuit diagram.
   
2. **Upload Code:**
   - Copy the provided code into your Arduino IDE.
   - Upload the code to your ESP32 or ESP8266.

3. **Monitor Output:**
   - Open the Serial Monitor at a baud rate of `115200` to see the "Sound Detected!" message each time the sensor detects sound.

## Code

```cpp
#define DIGITAL_PIN 27   // GPIO pin for the digital output of the sound sensor
#define DEBOUNCE_DELAY 1000  // Delay time (in milliseconds) to avoid repeated detection

unsigned long lastDetectionTime = 0;  // To store the time of the last detection

void setup() {
  Serial.begin(115200);           // Initialize serial communication
  pinMode(DIGITAL_PIN, INPUT);    // Set the digital pin as input
}

void loop() {
  int digitalValue = digitalRead(DIGITAL_PIN);  // Read from the digital pin
  unsigned long currentTime = millis();  // Get the current time
  
  // Check if sound is detected and debounce period has passed
  if (digitalValue == HIGH && (currentTime - lastDetectionTime > DEBOUNCE_DELAY)) {
    Serial.println("Sound Detected!");
    lastDetectionTime = currentTime;  // Update the last detection time
  }
}
