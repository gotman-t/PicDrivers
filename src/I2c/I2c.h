#ifndef I2C_H
#define I2C_H

#include <stdbool.h>
#include "Config/I2c_Cfg.h"

typedef enum {
    I2C_SUCCESS,
    I2C_FAILURE,
}I2cRetType;

#ifdef  __cplusplus
extern "C" {
#endif

    void I2c_Init(void);
    I2cRetType I2c_Write(unsigned char addr, unsigned char cmd, unsigned char data);

#if I2C_READARRAY_API
    I2cRetType I2c_ReadArray(unsigned char addr, unsigned char cmd, unsigned char size, unsigned char* data);
#endif // I2C_READARRAY_API

#ifdef  __cplusplus
}
#endif

#endif  /* I2C_H */

