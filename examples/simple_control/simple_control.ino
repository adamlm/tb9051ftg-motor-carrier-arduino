#include <TB9051FTG.h>

// TB9051FTG pin definitions
static constexpr uint8_t pwm1Pin{5};
static constexpr uint8_t pwm2Pin{6};

// Instantiate TB9051FTG
static const TB9051FTG driver{pwm1Pin, pwm2Pin};

static uint8_t throttlePercent{0};

void setup() {
  driver.enable();
  driver.setOutput(throttlePercent);
}

void loop() {
    // Ramp up to full forward throttle
    for (auto i{0}; i < 10; i++) {
        driver.setOutput(throttlePercent);
        throttlePercent += 10;
        delay(1000);
    }

    // Ramp down to 0 throttle
    for (auto i{0}; i < 10; i++) {
        driver.setOutput(throttlePercent);
        throttlePercent -= 10;
        delay(1000);
    }

    // Ramp up to full reverse throttle
    for (auto i{0}; i < 10; i++) {
        driver.setOutput(throttlePercent);
        throttlePercent -= 10;
        delay(1000);
    }

    // Ramp up to 0 throttle
    for (auto i{0}; i < 10; i++) {
        driver.setOutput(throttlePercent);
        throttlePercent += 10;
        delay(1000);
    }
}
