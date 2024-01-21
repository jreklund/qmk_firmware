// Copyright 2023 Johan Eklund (@jreklund)
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#define HAL_USE_SPI TRUE
#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD

#include_next <halconf.h>
