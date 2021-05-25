#ifndef DIO_H
#define DIO_H

#include "Config/Dio_Cfg.h"

typedef enum {
    DIO_LOW,
    DIO_HIGH,
} DioLevelType;

#ifdef  __cplusplus
extern "C" {
#endif
    void Dio_Init(void);
    DioLevelType Dio_Read(DioType dio);
    void Dio_Write(DioType dio, DioLevelType value);
#ifdef  __cplusplus
}
#endif

#endif  /* DIO_H */

