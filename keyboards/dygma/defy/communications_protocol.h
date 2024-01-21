// Copyright 2023 Dygma Lab S.L.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <stdint.h>

typedef enum {
    UNKNOWN = 0,
    KEYSCANNER_DEFY_LEFT,
    KEYSCANNER_DEFY_RIGHT,
    RF_DEFY_LEFT,
    RF_DEFY_RIGHT,
    NEURON_DEFY,
    RF_NEURON_DEFY,
    WIRED_NEURON_DEFY,
    BLE_NEURON_2_DEFY,
    BLE_DEFY_LEFT,
    BLE_DEFY_RIGHT,
} Devices;

typedef enum {
    IS_DEAD = 0,
    IS_ALIVE,
    CONNECTED,
    DISCONNECTED,
    SLEEP,
    WAKE_UP,
    VERSION,
    ALIVE_INTERVAL,
    //Keys
    HAS_KEYS = 10,
    KEYSCAN_INTERVAL,
    //LEDS
    BRIGHTNESS = 20,
    MODE_LED,
    LED,
    PALETTE_COLORS,
    LAYER_KEYMAP_COLORS,
    LAYER_UNDERGLOW_COLORS,
    GET_OPEN_LED,
    GET_SHORT_LED,
    //Battery
    BATTERY_LEVEL = 40,
    BATTERY_STATUS,
    BATTERY_SAVING,
    //Config
    RF_ADDRESS = 50,
} Commands;

typedef struct {
    Commands command;
    Devices device;
    struct {
        uint8_t size : 7;
        bool has_more_packets : 1;
    };
    uint8_t crc;
} Header;

static const uint8_t MAX_TRANSFER_SIZE = 32;
static const uint8_t MAX_DATA_SIZE     = MAX_TRANSFER_SIZE - sizeof(Header);

typedef union {
    struct {
        Header header;
        uint8_t data[28];
    };
    uint8_t buf[32];
} Packet;
