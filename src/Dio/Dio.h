#ifndef DIO_H
#define DIO_H

#include "Config/Dio_Cfg.h"

#define Dio_Init()  // 初期化処理なし

#ifdef  __cplusplus
extern "C" {
#endif
    byte Dio_Read(DioType pin);
    void Dio_Write(DioType pin, byte value);
#ifdef  __cplusplus
}
#endif

#endif  /* DIO_H */

