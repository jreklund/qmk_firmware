// Copyright 2023 Johan Eklund (@jreklund)
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include_next <mcuconf.h>

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE
