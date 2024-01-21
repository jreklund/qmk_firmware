// Copyright 2023 Johan Eklund (@jreklund)
// SPDX-License-Identifier: GPL-3.0-only

#include "matrix.h"
#include "spi_slave.h"
#include "communications_protocol.h"
#include "print.h"
#include "debug.h"
#include "crc.h"

SPIConfig SPI_PORT_0_CONFIG = {NULL, 0, 0, 0};
SPIConfig SPI_PORT_1_CONFIG = {NULL, 0, 0, 0};

SPISlave port0 = {
    &SPI_PORT_0,
    &SPI_PORT_0_CONFIG,
    SPI_MOSI_0,
    SPI_MISO_0,
    SPI_CLK_0,
    SPI_CS_0,
    1,
    8,
    SIDE_nRESET_1
};

SPISlave port1 = {
    &SPI_PORT_1,
    &SPI_PORT_1_CONFIG,
    SPI_MOSI_1,
    SPI_MISO_1,
    SPI_CLK_1,
    SPI_CS_1,
    1,
    8,
    SIDE_nRESET_2
};

void reset_sides(void) {
    setPinOutput(SIDE_nRESET_1); // output
    setPinOutput(SIDE_nRESET_2); // output
    writePinLow(SIDE_nRESET_1); // clear/false
    writePinLow(SIDE_nRESET_2); // clear/false
    chThdSleepMilliseconds(10); // sleep
    setPinInputHigh(SIDE_nRESET_1); // input & pull-up
    setPinInputHigh(SIDE_nRESET_2); // input & pull-up
    chThdSleepMilliseconds(50); // sleep
}

void matrix_init_custom(void) {
    reset_sides();

    spi_slave_init(&port0);
    spi_slave_start(&port0);

    Packet ptxI;
    Packet prxI;
    ptxI.header.size = 0;
    ptxI.header.device = WIRED_NEURON_DEFY;
    ptxI.header.command = IS_ALIVE;
    ptxI.header.has_more_packets = 0;
    ptxI.header.crc = 0;
    ptxI.header.crc = crc8(ptxI.buf, sizeof(Header) + ptxI.header.size);
    printf("TXI-header.device: %d\n", ptxI.header.device);
    printf("TXI-header.command: %d\n", ptxI.header.command);
    printf("TXI-header.crc: %d\n", ptxI.header.crc);
    spi_slave_exchange(&port0, &ptxI, &prxI);
    printf("RXI-header.device: %d\n", prxI.header.device);
    printf("RXI-header.command: %d\n", prxI.header.command);
    printf("RXI-header.crc: %d\n", prxI.header.crc);

    Packet ptxC;
    Packet prxC;
    ptxC.header.size = 0;
    ptxC.header.device = WIRED_NEURON_DEFY;
    ptxC.header.command = CONNECTED;
    ptxC.header.has_more_packets = 0;
    ptxC.header.crc = 0;
    ptxC.header.crc = crc8(ptxC.buf, sizeof(Header) + ptxC.header.size);
    printf("TXC-header.device: %d\n", ptxC.header.device);
    printf("TXC-header.command: %d\n", ptxC.header.command);
    printf("TXC-header.crc: %d\n", ptxC.header.crc);
    spi_slave_exchange(&port0, &ptxC, &prxC);
    printf("RXC-header.device: %d\n", prxC.header.device);
    printf("RXC-header.command: %d\n", prxC.header.command);
    printf("RXC-header.crc: %d\n", prxC.header.crc);

    // TODO: initialize hardware here

    // gpio_init(SIDE_nRESET_1);
    // gpio_init(SIDE_nRESET_2);
    // DefyWN::side::reset_sides();
        // gpio_set_dir(SIDE_nRESET_1, GPIO_OUT);
        // gpio_set_dir(SIDE_nRESET_2, GPIO_OUT);
        // gpio_put(SIDE_nRESET_1, false);
        // gpio_put(SIDE_nRESET_2, false);
        // sleep_ms(10);
        // gpio_set_dir(SIDE_nRESET_2, GPIO_IN);
        // gpio_set_dir(SIDE_nRESET_1, GPIO_IN);
        // gpio_pull_up(SIDE_nRESET_1);
        // gpio_pull_up(SIDE_nRESET_2);
        // sleep_ms(50);
    // Hands::setup();
        // Enable LEDs
        // other crap we don't need
    // KeyScannerWN::setup();
        // Not doing anything

    // Communications.init();
        // port0.init(); && port1.init();
            // gpio_init(spiSettings.reset);
            // gpio_set_dir(spiSettings.reset, GPIO_OUT);
            // gpio_put(spiSettings.reset, false);
            // sleep_us(1);
            // gpio_put(spiSettings.reset, true);
            // queue_init(&tx_messages_, sizeof(Packet), 80);
            // queue_init(&rx_messages_, sizeof(Packet), 80);
        // Send Communications_protocol::Commands::CONNECTED to both sides
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

    // printf("printf: %d\n", MAX_TRANSFER_SIZE);
    // dprintf("dprintf: %d\n", MAX_TRANSFER_SIZE);

    // printf("\n%ld\n", port0.spip->spi->SSPCR1);

    Packet ptxS;
    Packet prxS;
    ptxS.header.size = 0;
    ptxS.header.device = WIRED_NEURON_DEFY;
    ptxS.header.command = IS_ALIVE;
    ptxS.header.has_more_packets = 0;
    ptxS.header.crc = 0;
    ptxS.header.crc = crc8(ptxS.buf, sizeof(Header) + ptxS.header.size);
    printf("TXS-header.device: %d\n", ptxS.header.device);
    printf("TXS-header.command: %d\n", ptxS.header.command);
    printf("TXS-header.crc: %d\n", ptxS.header.crc);
    spi_slave_exchange(&port0, &ptxS, &prxS);
    printf("RXS-header.device: %d\n", prxS.header.device);
    printf("RXS-header.command: %d\n", prxS.header.command);
    printf("RXS-header.crc: %d\n", prxS.header.crc);

    // TODO: add matrix scanning routine here

    // Kaleidoscope.loop();
        // millis_at_cycle_start_ = millis();
        // kaleidoscope::Hooks::beforeEachCycle();
        // device().scanMatrix();
        // kaleidoscope::Hooks::beforeReportingState();
        // device().hid().keyboard().sendReport();
        // device().hid().keyboard().releaseAllKeys();
        // kaleidoscope::Hooks::afterEachCycle();

    // Communications.run();
        // Query both sides
        // checkActive

    return matrix_has_changed;
}
