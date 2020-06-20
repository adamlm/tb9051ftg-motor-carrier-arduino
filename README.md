
# TB9051FTG
This is an Arduino library for the Pololu TB9051FTG single brushed DC motor driver carrier.

## Getting started
### Hardware
You will need the Pololu [TB9051FTG Single Brushed DC Motor Driver Carrier](https://www.pololu.com/product/2997).

### Software
You can install the library through the [LIbrary Manager](https://www.arduino.cc/en/guide/libraries) in the [Arduino IDE](https://www.arduino.cc/en/Main/Software).

1. Open the Library Manager by clicking _Sketch > Include LIbrary > Manager Libraries ..._.
2. Search for _TB9051FTG_.
3. Click on the TB9051FTG entry.
4. (Optional) Select the version you want to install by selecting it in the drop-down menu. The Library Manager defaults to the latest version.
5. Click _Install_.

## Example Programs
The library comes with two example programs: one for simple motor control and one for measuring the motor current.

### Motor Control (`simple_control.ino`)
This program incrementally increases the motor's throttle. Initially, the motor is at rest, and a `for` loop increases the throttle output percentage in increments of 10% (`0.1`). Once the motor program sets the output to full throttle, it enters another `for` loop to decrease the motor output in increments of 10% (`0.1`). The program then repeats this sequence for the opposite direction.

### Monitor Current (`monitor_current.ino`)
This program periodically reads the motor current measurement from the TB9051FTG carrier and prints it to the serial connection. At startup, the program sets the motor's output to 10% (`0.1`). Then it reads a current estimate from the TB9051FTG carrier, and it prints that measurement to the serial connection. The program reads the current measurement approximately every 100 milliseconds (ms).

## Documentation
For information regarding the TB9051FTG motor driver carrier's pinout, see the Description section of the [product page](https://www.pololu.com/product/2997).

### Constants
* `kPinNotUsed`

   Indicates that a specified pin on the TB9051FTG motor carrier is not connected to the Arduino. Value is set at `255`.

   As an example, the program should pass this constant to the constructor when the EN pin on the motor carrier is not connected to the Arduino (i.e., when the EN pin is electrically connected to VCC or GND).

### Constructor
* `TB9051FTG(uint8_t pwm1, uint8_t pwm2, uint8_t ocm = kPinNotUsed,
              uint8_t diag = kPinNotUsed, uint8_t occ = kPinNotUsed,
              uint8_t en = kPinNotUsed, uint8_t enb = kPinNotUsed);`

  Custom constructor for the TB9051FTG. It configures all the pins and sets some default operating modes. Some arguments have default values, so they do not need to be specified when calling the constructor. An exception to this is when a non-default argument is specified after default arguments. In this case, the unused arguments need to be specified with `kPinNotUsed`.

  Arguments:
  * `pwm1` The pin number connected to the PWM1 input on the motor driver carrier.
  * `pwm2` The pin number connected to the PWM2 input on the motor driver carrier.
  * `ocm` (optional) The pin number connected to the OCM output on the motor driver carrier. Defaults to `kPinNotUsed`.
  * `diag` (optional) The pin number connected to the DIAG output on the motor driver carrier. Defaults to `kPinNotUsed`.
  * `occ` (optional) The pin number connected to the OCC input on the motor driver carrier. Defaults to `kPinNotUsed`.
  * `en` (optional) The pin number connected to the EN input on the motor driver carrier. Defaults to `kPinNotUsed`.
  * `enb` (optional) The pin number connected to the ENB input on the motor driver carrier. Defaults to `kPinNotUsed`.

### Functions
* `float getCurrent(void) const;`

  Reads an estimate of the motor current from the motor driver carrier. Output is in milliamps (mA). **Note:** This measurement is a coarse approximation only. Consider using an external sensor for fine current measurements.

  Arguments:
  * None

  Returns:
  * Current measurement in mA.


* `uint8_t getDiagnostic(void) const;`

  Reads the DIAG pin on the motor driver carrier. If there is a fault, or if the motor driver carrier is disabled by the EN or ENB pins, it returns logical low (`0`). Otherwise, it returns logical high (`1`).

  Arguments:
  * None

  Returns:
  * `0` if fault or disabled. `1` otherwise.


* `void setDeadband(float lower, float upper);`

  Sets the dead band range. When the throttle output value is within this range, the motor driver carrier stops the motor according to the current brake mode configuration.

  Arguments:
  * `lower` Lower dead band value (exclusively).
  * `upper` Upper dead band value (exclusively).

  Returns:
  * None


* `void setBrakeMode(bool mode);`

  Sets the brake mode for the motor driver carrier. If the carrier is set to brake mode (mode `1`), the carrier outputs will be shorted to ground when the motor stops. This acts as a brake. If the carrier is not set to brake mode (`0`), the carrier outputs will be left floating, so the motor will coast to a stop.

  Arguments:
  * `mode` Brake mode (`1`) or non brake mode (`0`).

  Returns:
  * None


* `void setOutput(float percent) const;`

  Sets the throttle output percentage [-1, 1], which is the percentage of the driver carrier's input voltage. When the output percentage is negative, the motor will turn in reverse.

 Arguments:
 * `percent` output throttle percentage.

 Returns
 * None


* `void setOcc(uint8_t value) const;`

  Sets the over-current response. If low (`0`), the motor driver carrier is disabled when an over-current event happens. The motor driver carrier can be reset by toggling either the EN pin or the ENB pin. If high (`1`), the motor driver carrier will re-enable after a short period following an over-current event.

  Arguments:
  * `value` over-current response (`1`, or `0`).


* `void enable(void);`

  Enable the motor driver carrier's outputs. The motor driver carrier Initially is disabled, so it needs to be manually enabled using this function.

  Arguments:
  * None

  Returns:
  * None


* `void disable(void);`

  Disable the motor driver carrier's outputs.

  Arguments:
  * None

  Returns
  * None
