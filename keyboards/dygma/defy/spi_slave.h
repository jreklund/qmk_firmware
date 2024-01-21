// Copyright 2023 Johan Eklund (@jreklund)
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <hal.h>
#include <gpio.h>
#include <chibios_config.h>
#include "communications_protocol.h"

typedef struct {
    SPIDriver *spip;
    SPIConfig *spiConfig;
    uint8_t MOSI;
    uint8_t MISO;
    uint8_t SCK;
    uint8_t SS;
    uint8_t mode;
    uint8_t divisor;
    uint8_t reset;
} SPISlave;

extern SPISlave port0;
extern SPISlave port1;

void spi_slave_init(SPISlave *slave);

void spi_slave_start(SPISlave *slave);

void spi_slave_transmit(SPISlave *slave, Packet *data);

void spi_slave_receive(SPISlave *slave, Packet *data);

void spi_slave_exchange(SPISlave *slave, Packet *tx, Packet *rx);

void spi_slave_stop(SPISlave *slave);
