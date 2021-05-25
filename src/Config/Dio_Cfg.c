#include "Common.h"

#include "DriverCommon.h"
#include "Dio/Dio_Internal.h"
#include "Dio_Cfg.h"

static byte ReadRA4(void) {
    return RA4;
}

static byte ReadRA5(void) {
    return RA5;
}

static byte ReadRC2(void) {
    return RC2;
}

static void WriteRA2(byte value) {
    RA2 = value;
}

static void WriteRC3(byte value) {
    RC3 = value;
}

static void WriteRC4(byte value) {
    RC4 = value;
}

static void WriteRC5(byte value) {
    RC5 = value;
}

const DioCfg k_DioCfg[] = {
    {NULL, WriteRA2},
    {ReadRA4, NULL},
    {ReadRA5, NULL},
    {ReadRC2, NULL},
    {NULL, WriteRC3},
    {NULL, WriteRC4},
    {NULL, WriteRC5},
};