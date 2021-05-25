#include <xc.h>
#include "Dio/Dio_Internal.h"
#include "Dio_Cfg.h"

static void WriteRA2(DioLevelType value) {
    RA2 = value;
}

static DioLevelType ReadRA4(void) {
    return RA4;
}

static void WriteRA4(DioLevelType value) {
    RA4 = value;
}

const DioCfg k_DioCfg[] = {
    {NULL, WriteRA2},
    {ReadRA4, WriteRA4},
};