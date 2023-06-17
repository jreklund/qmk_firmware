// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// Copyright 2022 Johan Eklund

#pragma once

#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 500

#define USE_SERIAL_PD2

// Tap/Hold timing
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// Activate Caps Word by pressing Left Shift + Right Shift
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
