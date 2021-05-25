#ifndef GPT_INTERNAL_H
#define GPT_INTERNAL_H

typedef void(*TimerTask)(void);

typedef struct {
    unsigned char taskNum;
    const TimerTask* taskList;
} GptCfg;

extern const GptCfg k_GptCfg;

#endif  /* GPT_INTERNAL_H */

