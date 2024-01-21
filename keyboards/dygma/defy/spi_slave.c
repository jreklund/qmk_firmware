// Copyright 2023 Johan Eklund (@jreklund)
// SPDX-License-Identifier: GPL-3.0-only

#include "communications_protocol.h"
#include "spi_slave.h"

__attribute__((weak)) void spi_slave_init(SPISlave *slave) {
    // Try releasing special pins for a short time
    setPinInput(slave->SCK);
    setPinInput(slave->MOSI);
    setPinInput(slave->MISO);
    setPinInput(slave->SS);

    chThdSleepMilliseconds(10);
    palSetPadMode(PAL_PORT(slave->SCK), PAL_PAD(slave->SCK), SPI_SCK_PAL_MODE);
    palSetPadMode(PAL_PORT(slave->MOSI), PAL_PAD(slave->MOSI), SPI_MOSI_PAL_MODE);
    palSetPadMode(PAL_PORT(slave->MISO), PAL_PAD(slave->MISO), SPI_MISO_PAL_MODE);
    palSetPadMode(PAL_PORT(slave->SS), PAL_PAD(slave->SS), SPI_CS_PAL_MODE);
    spiStop(slave->spip);

    setPinOutput(slave->reset);
    writePinLow(slave->reset);
    chThdSleepMicroseconds(1);
    writePinHigh(slave->reset);
}

void spi_slave_start(SPISlave *slave) {
    // Motorola frame format and 8bit transfer data size.
    slave->spiConfig->SSPCR0 = SPI_SSPCR0_FRF_MOTOROLA | SPI_SSPCR0_DSS_8BIT;
    // Serial output clock = (ck_sys or ck_peri) / (SSPCPSR->CPSDVSR * (1 +
    // SSPCR0->SCR)). SCR is always set to zero, as QMK SPI API expects the
    // passed divisor to be the only value to divide the input clock by.
    slave->spiConfig->SSPCPSR = slave->divisor; // Even number from 2 to 254

    switch (slave->mode) {
        case 0:
            slave->spiConfig->SSPCR0 &= ~SPI_SSPCR0_SPO; // Clock polarity: low
            slave->spiConfig->SSPCR0 &= ~SPI_SSPCR0_SPH; // Clock phase: sample on first edge
            break;
        case 1:
            slave->spiConfig->SSPCR0 &= ~SPI_SSPCR0_SPO; // Clock polarity: low
            slave->spiConfig->SSPCR0 |= SPI_SSPCR0_SPH;  // Clock phase: sample on second edge transition
            break;
        case 2:
            slave->spiConfig->SSPCR0 |= SPI_SSPCR0_SPO;  // Clock polarity: high
            slave->spiConfig->SSPCR0 &= ~SPI_SSPCR0_SPH; // Clock phase: sample on first edge
            break;
        case 3:
            slave->spiConfig->SSPCR0 |= SPI_SSPCR0_SPO; // Clock polarity: high
            slave->spiConfig->SSPCR0 |= SPI_SSPCR0_SPH; // Clock phase: sample on second edge transition
            break;
    }

    slave->spiConfig->ssport = PAL_PORT(slave->SS);
    slave->spiConfig->sspad  = PAL_PAD(slave->SS);

    spiStart(slave->spip, slave->spiConfig);
    slave->spip->spi->SSPCR1 = 0U; // Disable
    slave->spip->spi->SSPCR1 = SPI_SSPCR1_SSE | SPI_SSPCR1_MS; // Enable slave mode
}

void spi_slave_transmit(SPISlave *slave, Packet *data) {
    spiSend(slave->spip, MAX_TRANSFER_SIZE, data->buf);
}

void spi_slave_receive(SPISlave *slave, Packet *data) {
    spiReceive(slave->spip, MAX_TRANSFER_SIZE, data->buf);
}

void spi_slave_exchange(SPISlave *slave, Packet *tx, Packet *rx) {
    spiExchange(slave->spip, MAX_TRANSFER_SIZE, tx->buf, rx->buf);
}

void spi_slave_stop(SPISlave *slave) {
    spiStop(slave->spip);
}
