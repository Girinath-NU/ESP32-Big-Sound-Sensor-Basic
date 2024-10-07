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
