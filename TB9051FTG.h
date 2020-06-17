#pragma once

#include <Arduino.h>

constexpr uint8_t kPinNotUsed{255};

class TB9051FTG {
public:
    /**
     * Custom constructor.
     */
    TB9051FTG(uint8_t pwm1, uint8_t pwm2, uint8_t ocm = kPinNotUsed, 
              uint8_t diag = kPinNotUsed, uint8_t occ = kPinNotUsed, 
              uint8_t en = kPinNotUsed, uint8_t enb = kPinNotUsed);

    // Getters
    uint8_t getOccPin(void) const;
    uint8_t getEnPin(void) const;
    uint8_t getEnbPin(void) const;
    uint8_t getPwm1Pin(void) const;
    uint8_t getPwm2Pin(void) const;
    uint8_t getOcmPin(void) const;
    uint8_t getDiagPin(void) const;

    uint8_t getCurrent(void);
    uint8_t getDiagnostic(void);

    // Setters
    void setOccPin(uint8_t pin);
    void setEnPin(uint8_t pin);
    void setEnbPin(uint8_t pin);
    void setPwm1Pin(uint8_t pin);
    void setPwm2in(uint8_t pin);
    void setOcmin(uint8_t pin);
    void setDiagPin(uint8_t pin);

    void setDeadband(float range);
    void setBrakeMode(uint8_t mode);
    void setOutput(float percent);
    void setOcc(uint8_t value);

    // Other functions
    void enable(void);
    void disable(void);

private:
    uint8_t occ;  // Over current response
    uint8_t en;  // Enable
    uint8_t enb;  // Inverted enable
    uint8_t pwm1;  // PWM for OUT1
    uint8_t pwm2;  // PWM for OUT2
    uint8_t ocm;  // Current monitor
    uint8_t diag;  // Diagnostic error
};

