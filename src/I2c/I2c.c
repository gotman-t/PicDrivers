#include <xc.h>
#include "I2c.h"

#define I2C_FREQ (100000)
#define I2C_TIME_UP (5)    // [ms]

typedef bool(*ConditionFunc)(void);

#if I2C_READARRAY_API
static bool RestartI2c(void);
static bool ReceiveBuff(unsigned char ack, unsigned char* buf);
#endif
static bool StartI2c(void);
static bool ExitI2c(void);
static bool SendBuff(unsigned char buf);
static bool WaitCondition(ConditionFunc func);
static bool IsReady(void);
static bool IsStarted(void);
static bool IsRestarted(void);
static bool IsStoped(void);
static bool IsSendFinished(void);

static unsigned char m_Count;

void I2c_Init(void) {
    SSPADD = (I2C_FOSC / (4 * I2C_FREQ)) - 1;

    SSP1CON1bits.SSPM = 0b1000; // I2Cマスタモード
    SSP1CON1bits.SSPEN = 1; // シリアルポート有効化
    SSP1CON2 = 0x00; // I2C通信をアイドルにする
    SSP1STAT = 0x00; // 標準速度モードに設定

    return;
}

#if I2C_READARRAY_API
I2cRetType I2c_ReadArray(
    unsigned char addr,
    unsigned char cmd,
    unsigned char size,
    unsigned char* data) {
    bool isSucceed;

    isSucceed = StartI2c();

    isSucceed |= SendBuff(addr << 1);
    isSucceed |= SendBuff(cmd);

    isSucceed |= RestartI2c();

    isSucceed |= SendBuff(addr << 1 | 1);

    for (unsigned char i = 0; i < size; i++) {
        isSucceed |= ReceiveBuff(i + 1 < size, &data[i]);
    }

    isSucceed |= ExitI2c();

    return isSucceed ? I2C_SUCCESS : I2C_FAILURE;
}
#endif

I2cRetType I2c_Write(
    unsigned char addr,
    unsigned char cmd,
    unsigned char data) {
    bool isSucceed;

    isSucceed = StartI2c();

    isSucceed |= SendBuff(addr << 1);
    isSucceed |= SendBuff(cmd);
    isSucceed |= SendBuff(data);

    isSucceed |= ExitI2c();

    return isSucceed ? I2C_SUCCESS : I2C_FAILURE;
}

void I2c_Interrupt(void) {
    m_Count++;
}

static bool StartI2c(void) {
    if (!WaitCondition(IsReady)) { return false; } // I2C待機

    SSP1CON2bits.SEN = 1; // 開始

    if (!WaitCondition(IsStarted)) { return false; } // 開始確認

    return true;
}

#if I2C_READARRAY_API
static bool RestartI2c(void) {
    if (!WaitCondition(IsReady)) { return false; } // I2C待機

    SSP1CON2bits.RSEN = 1; // 開始

    if (!WaitCondition(IsRestarted)) { return false; } // 開始確認

    return true;
}
#endif

static bool ExitI2c(void) {
    if (!WaitCondition(IsReady)) { return false; } // I2C待機
    SSP1CON2bits.PEN = 1; // 終了

    if (!WaitCondition(IsStoped)) { return false; } // 終了確認

    return true;
}

static bool SendBuff(unsigned char buf) {
    SSP1IF = 0; // 終了フラグクリア
    SSPBUF = buf;

    if (!WaitCondition(IsSendFinished)) { return false; } // 送信終了待ち

    return true;
}

#if I2C_READARRAY_API
static bool ReceiveBuff(unsigned char ack, unsigned char* buf) {
    SSP1CON2bits.RCEN = 1;

    if (!WaitCondition(IsReady)) { return false; } // I2C待機

    *buf = SSPBUF;

    if (!WaitCondition(IsReady)) { return false; } // I2C待機

    SSP1CON2bits.ACKDT = (ack == 1 ? 0 : 1);
    SSP1CON2bits.ACKEN = 1;

    return true;
}
#endif

static bool WaitCondition(ConditionFunc func) {
    m_Count = 0;
    while (!func()) {
        if (m_Count >= I2C_TIME_UP) {
            return false;
        }
    }
    return true;
}

static bool IsReady(void) {
    return SSP1STATbits.R_nW == 0 && ((SSP1CON2 & 0x1F) == 0);
}

static bool IsStarted(void) {
    return SSP1CON2bits.SEN == 0;
}

static bool IsRestarted(void) {
    return SSP1CON2bits.RSEN == 0;
}

static bool IsStoped(void) {
    return SSP1CON2bits.PEN == 0;
}

static bool IsSendFinished(void) {
    return SSP1IF;
}