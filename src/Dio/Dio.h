#ifndef DIO_H
#define DIO_H

#include "Config/Dio_Cfg.h"

typedef enum {
    LOW,
    HIGH,
} DioLevelType;

#ifdef  __cplusplus
extern "C" {
#endif
    void Dio_Init(void);
    DioLevelType Dio_Read(DioType pin);
    void Dio_Write(DioType pin, DioLevelType value);
#ifdef  __cplusplus
}
#endif

#endif  /* DIO_H */

