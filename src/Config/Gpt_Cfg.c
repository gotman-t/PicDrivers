#include <stddef.h>
#include "Gpt/Gpt.h"
#include "Gpt/Gpt_Internal.h"
#include "Config/Gpt_Cfg.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

static const TimerTask k_TimerTaskList[] = {
    // Add cyclic task here
};

const GptCfg k_GptCfg = {
    ARRAY_SIZE(k_TimerTaskList),
    k_TimerTaskList,
};
