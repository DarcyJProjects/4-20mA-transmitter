// 3.3V to 4-20mA Transmitter Firmware
#include <stdint.h>

// ======================== USER CONFIGURATION ==================================

// --- Pin Definitions ---
constexpr uint8_t SENSOR_PIN = A0; // 0-3.3V Analogue Sensor Input
constexpr uint8_t PWM_PIN    = 9;  // PWM Output to RC Filter/Op-Amp

// --- Averaging Configuration ---
// The module takes a reading every 'SAMPLE_INTERVAL_MS'.
// It averages 'NUM_SAMPLES' before updating the 4-20mA output.
constexpr uint32_t SAMPLE_INTERVAL_MS = 10;  // Take a sample every 10 ms
constexpr uint16_t NUM_SAMPLES        = 100; // Average 100 samples (updates every 1000 ms)

// --- Scaling & Mapping Configuration ---
// 1. Define your input sensor range (ADC values)
// On a 5V ATMega328P (10-bit ADC): 5V = 1023, 3.3V = ~675. 
// Adjust these to match your specific sensor's calibrated output range.
constexpr uint16_t ADC_IN_MIN = 0;   
constexpr uint16_t ADC_IN_MAX = 450; 

// 2. Define your output loop range (PWM values 0-255)
// Adjust these based on the voltage drop needed across your sense resistor.
// NOTE: Inverted logic - lower PWM value creates a higher voltage drop (higher current).
constexpr uint8_t PWM_OUT_4MA  = 250; 
constexpr uint8_t PWM_OUT_20MA = 153; 

// ======================= END USER CONFIGURATION ===============================

// State Variables
uint32_t lastSampleTime = 0;
uint32_t sampleSum      = 0;
uint16_t sampleCount    = 0;

void setup() {
  pinMode(PWM_PIN, OUTPUT);
  Serial.begin(115200); 
  Serial.println("4-20mA Transmitter Initialised.");
} 

void loop() {
  uint32_t currentMillis = millis();

  // 1. Take samples at the configured interval
  if (currentMillis - lastSampleTime >= SAMPLE_INTERVAL_MS) {
    sampleSum += analogRead(SENSOR_PIN);
    sampleCount++;
    lastSampleTime = currentMillis;

    // 2. Once we reach the configured number of samples, calculate and output
    if (sampleCount >= NUM_SAMPLES) {
      
      // Calculate average
      uint16_t avgReading = sampleSum / NUM_SAMPLES;

      // Map the reading to the 4-20mA PWM range
      int16_t pwmValue = map(avgReading, ADC_IN_MIN, ADC_IN_MAX, PWM_OUT_4MA, PWM_OUT_20MA);
      
      // Constrain to ensure we strictly stay within 4-20mA limits.
      pwmValue = constrain(pwmValue, PWM_OUT_20MA, PWM_OUT_4MA);

      // Output the new PWM value
      analogWrite(PWM_PIN, (uint8_t)pwmValue);

      // Debugging output
      Serial.print("Avg ADC: "); Serial.print(avgReading);
      Serial.print(" | PWM Out: "); Serial.println(pwmValue);

      // Reset accumulators for the next batch
      sampleSum = 0;
      sampleCount = 0;
    }
  }
}
