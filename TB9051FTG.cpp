#include "TB9051FTG.h"

TB9051FTG::TB9051FTG(const uint8_t pwm1, const uint8_t pwm2, 
                     const uint8_t ocm, const uint8_t diag,
                     const uint8_t occ, const uint8_t en,
                     const uint8_t enb) :
                     pwm1(pwm1),
                     pwm2(pwm2),
                     ocm(ocm),
                     diag(diag),
                     occ(occ),
                     en(en),
                     enb(enb) {

    pinMode(this->pwm1, OUTPUT);
    pinMode(this->pwm2, OUTPUT);

    if (this->ocm != kPinNotUsed) {
        pinMode(this->ocm, INPUT);
    }

    if (this->diag != kPinNotUsed) {
        pinMode(this->diag, INPUT);
    }

    if (this->occ != kPinNotUsed) {
        pinMode(this->occ, OUTPUT);
    }

    if (this->en != kPinNotUsed) {
        pinMode(this->en, OUTPUT);
    }

    if (this->enb != kPinNotUsed) {
        pinMode(this->enb, OUTPUT);
    }
}
 
void TB9051FTG::setOutput(const float percent) {
    const auto output{static_cast<uint8_t>(abs(percent) * 255)};

    if (percent < 0) {
        analogWrite(this->pwm1, 0);
        analogWrite(this->pwm2, output);
    } else {
        analogWrite(this->pwm1, output);
        analogWrite(this->pwm2, 0);
    }
}

uint8_t TB9051FTG::getCurrent(void) {
    return this->ocm != kPinNotUsed? analogRead(this->ocm): kPinNotUsed;
}

void TB9051FTG::setOcc(const uint8_t value) {
    if (this->occ != kPinNotUsed) {
        digitalWrite(this->occ, value);
    }
}

void TB9051FTG::enable(void) {
    if (this->en != kPinNotUsed) {
        digitalWrite(this->en, 1);
    }

    if (this->en != kPinNotUsed) {
        digitalWrite(this->enb, 0);
    }
}

void TB9051FTG::disable(void) {
    if (this->en != kPinNotUsed) {
        digitalWrite(this->en, 0);
    }

    if (this->enb != kPinNotUsed) {
        digitalWrite(this->enb, 1);
    }
}

uint8_t TB9051FTG::getDiagnostic(void) {
    return this->diag != kPinNotUsed? digitalRead(this->diag): kPinNotUsed;
}

uint8_t TB9051FTG::getEnPin(void) const {
    return this->en;
}

