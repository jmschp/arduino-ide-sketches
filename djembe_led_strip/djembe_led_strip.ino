#include <FastLED.h>

#define LED_PIN 6
#define NUM_LEDS 300
// #define BRIGHTNESS 100
#define MICROPHONE_PIN 2
// #define CLAP_THRESHOLD 800  // Adjust based on your calibration
#define SNAKE_LENGTH 10
// #define SNAKE_DELAY 10     // Delay between snake movement
#define DEBOUNCE_TIME 125  // Debounce time in milliseconds

unsigned long lastClapTime = 0;  // Tracks the last time a clap was detected

CRGB leds[NUM_LEDS];

// Define a struct to hold the state of each snake
struct Snake {
  int position;
  bool active;
  CRGB color;
};

// Create an array to track multiple snakes
#define MAX_SNAKES 30  // Maximum number of active snakes
Snake snakes[MAX_SNAKES];

void setup() {
  delay(3000);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.clear();
  FastLED.show();

  // Initialize all snakes as inactive
  for (int i = 0; i < MAX_SNAKES; i++) {
    snakes[i].active = false;
  }
}

void loop() {
  int sensorValue = digitalRead(MICROPHONE_PIN);
  unsigned long currentTime = millis();

  // Detect clap and activate a new snake
  if (sensorValue && (currentTime - lastClapTime > DEBOUNCE_TIME)) {
    activateSnake();
    lastClapTime = currentTime;
  }

  moveSnakes();
  FastLED.show();
  // delay(SNAKE_DELAY);
}

// Function to activate a new snake
void activateSnake() {
  for (int i = 0; i < MAX_SNAKES; i++) {
    if (!snakes[i].active) {
      snakes[i].position = 0;   // Start at the beginning of the strip
      snakes[i].active = true;  // Mark the snake as active
      snakes[i].color = CHSV(random(0, 255), 255, 255);
      break;  // Only activate one snake per clap
    }
  }
}

// Function to move all active snakes
void moveSnakes() {
  FastLED.clear();

  for (int i = 0; i < MAX_SNAKES; i++) {
    if (snakes[i].active) {
      for (int j = 0; j < SNAKE_LENGTH; j++) {
        int ledIndex = snakes[i].position + j;
        if (ledIndex < NUM_LEDS) {
          uint8_t brightness = map(SNAKE_LENGTH - j, 0, SNAKE_LENGTH, 255, 15);
          leds[ledIndex] = snakes[i].color;
          leds[ledIndex].nscale8(constrain(brightness, 15, 255));
        }
      }

      snakes[i].position++;  // Move the snake forward

      // Deactivate the snake if it has moved off the strip
      if (snakes[i].position >= NUM_LEDS) {
        snakes[i].active = false;
      }
    }
  }
}
