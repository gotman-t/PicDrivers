# PicDrivers
Mcu drivers for PIC series.

## Dio Driver
### NOTE
This driver only works with "PIC16 (L) F1705 / 9".

### Path
* src/Dio/*
* src/Config/Dio_Cfg.c
* src/Config/Dio_Cfg.h

### API
#### Dio_Init
Nothing to do.

### Dio_Read
```
DioLevelType Dio_Read(DioType dio);
```

Read digital I/O port.

### Dio_Write
```
void Dio_Write(DioType dio, DioLevelType value);
```

Write digital I/O port.

## Gpt Driver
### NOTE
This driver only works with "PIC16 (L) F1705 / 9".

### Path
* src/Gpt/*
* src/Config/Gpt_Cfg.c
* src/Config/Gpt_Cfg.h

### API
#### Gpt_Init
```
void Gpt_Init(void);
```

Initialize Gpt.

#### Gpt_StartTimer
```
void Gpt_StartTimer(GptTimerType timer, unsigned char time);
```

Start the multi porpose timer.

## I2c Driver
### NOTE
This driver only works with "PIC16 (L) F1705 / 9".

### Path
* src/I2c/*
* src/Config/I2c_Cfg.c
* src/Config/I2c_Cfg.h

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
