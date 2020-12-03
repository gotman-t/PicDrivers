#include <xc.h>
#include "Gpt.h"
#include "Config/Gpt_Cfg.h"
#include "Gpt_Isr.h"
#include "Gpt_Internal.h"

static unsigned char m_Cnt;

void Gpt_Init(void) {
    m_Cnt = 0;

    // Timer0の設定 1Clock = 0.032ms
    OPTION_REGbits.TMR0CS = 0; // 内部サイクルクロックを利用
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS = 0b111; // プリスケーラ 1:256


    // タイマ割り込みの許可
    INTCONbits.GIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 1;
    return;
}

void Gpt_StartTimer(GptTimerType timer, unsigned char time) {
    // TODO ほかタイマの使用
    INTCONbits.TMR0IF = 0;
    m_Cnt = 0xff - time;
    TMR0 = m_Cnt;
    return;
}

void InterruptTmr0(void) {
    // __wmulを割り込み時に呼び出さないため、ポインタのインクリメントを利用する。
    const TimerTask* task = k_GptCfg.taskList;
    for (unsigned char i = 0; i < k_GptCfg.taskNum; i++, task++) {
        (*task)();
    }
    TMR0 = m_Cnt;
}