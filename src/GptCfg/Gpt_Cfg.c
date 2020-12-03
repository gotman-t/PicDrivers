#include <stddef.h>
#include "Gpt.h"
#include "Config/Gpt_Cfg.h"
#include "Gpt_Internal.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

// static const TimerTask k_TimerTaskList[] = {};

const GptCfg k_GptCfg = {
    0,
    NULL,
};