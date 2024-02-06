// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 450
#define LEADER_NO_TIMEOUT
	/* only no timeout for the first key to press, afterwards the LEADER_TIMEOUT counts */

#define COMBO_MUST_TAP_PER_COMBO

#define COMBO_TERM 50
	/* Default is 50ms */

