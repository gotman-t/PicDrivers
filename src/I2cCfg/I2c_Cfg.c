#include "Driver/Mcu/Mcu.h"

#define I2C_FOSC (8000000)
#define I2C_FREQ (100000)

const unsigned char k_SspAdd = (I2C_FOSC / (4 * I2C_FREQ)) - 1;