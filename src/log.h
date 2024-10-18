/**
 *
 * Agora Real Time Engagement
 * Created by Zhang Jie in 2024-06.
 * Copyright (c) 2024 Agora IO. All rights reserved.
 *
 */
#pragma once

#define AZURE_TTS_LOG_TAG "AZURE_TTS_EXTENSION"

#include "ten_utils/log/log.h"

#define AZURE_TTS_LOGI(...) TEN_LOGI(AZURE_TTS_LOG_TAG, __VA_ARGS__)
#define AZURE_TTS_LOGE(...) TEN_LOGE(AZURE_TTS_LOG_TAG, __VA_ARGS__)
#define AZURE_TTS_LOGW(...) TEN_LOGW(AZURE_TTS_LOG_TAG, __VA_ARGS__)
#define AZURE_TTS_LOGD(...) TEN_LOGD(AZURE_TTS_LOG_TAG, __VA_ARGS__)
