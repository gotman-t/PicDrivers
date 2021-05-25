#include "Common.h"
#include "DriverCommon.h"
#include "Dio.h"
#include "Dio_Internal.h"

byte Dio_Read(DioType dio) {
    return k_DioCfg[dio].Read();
}

void Dio_Write(DioType dio, byte value) {
    k_DioCfg[dio].Write(value);
    return;
}