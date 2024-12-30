/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#endif // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

/* Charybdis-specific features. */

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_TIME 1000
#define AUTO_MOUSE_THRESHOLD 16
#define AUTO_MOUSE_DEBOUNCE 75
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#define CHARYBDIS_MINIMUM_DEFAULT_DPI     1600
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200
#define CHARYBDIS_MINIMUM_SNIPING_DPI     400
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100

#define COMBO_COUNT 2
#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0
#define TAPPING_TOGGLE 1
#define PERMISSIVE_HOLD

// activate the leader key
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300

// achordion settings
#define ACHORDION_STREAK