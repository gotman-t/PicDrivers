# PicDrivers
Mcu drivers for PIC series.

## I2c Driver
### NOTE
This driver only works with "PIC16 (L) F1705 / 9".

### Path
* src/I2c
* src/I2cCfg

### API
#### I2c_Init
```c
void I2c_Init(void)
```

Initialize I2c.

#### I2c_Write
``` c
I2cRetType I2c_Write(unsigned char addr, unsigned char cmd, unsigned char data);
```

TODO

#### I2c_ReadArray
``` c
I2cRetType I2c_ReadArray(unsigned char addr, unsigned char cmd, unsigned char size, unsigned char* data);
```
TODO

### Type
#### I2cRetType
This type has following Definitions.

|Definition|Description|
|-|-|
|I2C_SUCCESS|I2c communication is Successful|
|I2C_FAILURE|I2c communication is failed|

## Licence
"PicDrivers" is under [MIT license](https://en.wikipedia.org/wiki/MIT_License).
