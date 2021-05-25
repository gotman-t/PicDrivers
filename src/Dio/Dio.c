#include "Dio.h"
#include "Dio_Internal.h"

void Dio_Init(void){
    // no action
}

DioLevelType Dio_Read(DioType dio) {
    return k_DioCfg[dio].Read();
}

void Dio_Write(DioType dio, DioLevelType value) {
    k_DioCfg[dio].Write(value);
    return;
}