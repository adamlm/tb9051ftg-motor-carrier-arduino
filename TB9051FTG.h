#pragma once

#include <Arduino.h>

constexpr uint8_t kPinNotUsed{255};

class TB9051FTG {
public:
    TB9051FTG(uint8_t pwm1, uint8_t pwm2, uint8_t ocm = kPinNotUsed, 
              uint8_t diag = kPinNotUsed, uint8_t occ = kPinNotUsed, 
              uint8_t en = kPinNotUsed, uint8_t enb = kPinNotUsed);

    void setOutput(float percent);
    uint8_t getCurrent(void);
    void setOcc(uint8_t value);
    void enable(void);
    void disable(void);
    uint8_t getDiagnostic(void);

private:
    uint8_t occ;  // Over current response
    uint8_t en;  // Enable
    uint8_t enb;  // Inverted enable
    uint8_t pwm1;  // PWM for OUT1
    uint8_t pwm2;  // PWM for OUT2
    uint8_t ocm;  // Current monitor
    uint8_t diag;  // Diagnostic error
};

