#ifndef GPT_H
#define GPT_H

#include "Config/Gpt_Cfg.h"

#ifdef  __cplusplus
extern "C" {
#endif
    void Gpt_Init(void);
    void Gpt_StartTimer(GptTimerType timer, unsigned char time);
#ifdef  __cplusplus
}
#endif

#endif  /* GPT_H */

