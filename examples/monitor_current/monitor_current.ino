#include <TB9051FTGMotorCarrier.h>

// TB9051FTGMotorCarrier pin definitions
static constexpr uint8_t pwm1Pin{5};
static constexpr uint8_t pwm2Pin{6};
static constexpr uint8_t ocmPin{A1};

// Instantiate TB9051FTGMotorCarrier
static TB9051FTGMotorCarrier driver{pwm1Pin, pwm2Pin, ocmPin};

void setup() {
  Serial.begin(9600);

  driver.enable();
  driver.setOutput(0.1);
}

void loop() {
  Serial.println(driver.getCurrent());
  delay(100);
}
