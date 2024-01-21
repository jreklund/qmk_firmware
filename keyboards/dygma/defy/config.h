// Copyright 2023 Johan Eklund (@jreklund)
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#define MATRIX_ROWS 5
#define MATRIX_COLS 16

#define SIDE_nRESET_1 GP22 // nRESET signal OUT to keyboard side 1; HIGH = running, LOW = reset
#define SIDE_nRESET_2 GP10 // nRESET signal OUT to keyboard side 2; HIGH = running, LOW = reset

#define SPI_PORT_0    SPID0
#define SPI_MOSI_0    GP20
#define SPI_MISO_0    GP23
#define SPI_CLK_0     GP18
#define SPI_CS_0      GP21

#define SPI_PORT_1    SPID1
#define SPI_MOSI_1    GP8
#define SPI_MISO_1    GP11
#define SPI_CLK_1     GP14
#define SPI_CS_1      GP9

#define SPI_CS_PAL_MODE (PAL_MODE_ALTERNATE_SPI | PAL_RP_PAD_SLEWFAST | PAL_RP_PAD_DRIVE4)
