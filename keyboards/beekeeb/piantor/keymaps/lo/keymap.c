// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "sendstring_german.h"

enum layers {
	L_BASE = 0,
	L_NAV,
	L_NUM_L,
	L_NUM_R,
	L_SYM,
	L_F
};

enum custom_keycodes {
    LT_LEADER = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      *     ┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐
      *     │  ESC  │   Q   │   W   │   E   │   R   │   T   │       │   Z   │   U   │   I   │   O   │   P   │   Ü   │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │  Tab  │   A   │   S   │   D   │   F   │   G   │       │   H   │   J   │   K   │   L   │   Ö   │   Ä   │
      *     │       │  Ctl  │  Gui  │  NAV  │  Sft  │       │       │       │  Sft  │  SYM  │  Gui  │  Ctl  │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │  Sft  │   Y   │   X   │   C   │   V   │   B   │       │   N   │   M   │   ,   │   .   │   -   │ Repeat│
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
      *                               ┌───────┐                                   ┌───────┐
      *                               |       |                                   |       |
      *                               │  CTL  ├───────┐                   ┌───────┤  Bsp  │
      *                               |       |       |                   |       |       |
      *                               └───────┤  Sft  ├───────┐   ┌───────┤ Space ├───────┘
      *                                       |     LEADER    |   |       |       |
      *                                       └───────┤ Enter │   │  SYM  ├───────┘
      *                                               |       |   |       |
      *                                               └───────┘   └───────┘
      */
    [L_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,		KC_Q,			KC_W,			KC_E,			KC_R,			KC_T,					KC_Y,			KC_U,			KC_I,			KC_O,			KC_P,				KC_LBRC, 
        KC_TAB,		LCTL_T(KC_A),	LGUI_T(KC_S),	LT(L_NAV, KC_D),LSFT_T(KC_F),	KC_G,					KC_H,			RSFT_T(KC_J),	LT(L_NUM_L,KC_K),RGUI_T(KC_L),	RCTL_T(KC_SCLN),	KC_QUOT, 
        KC_LSFT, 	KC_Z, 			KC_X, 			KC_C, 			KC_V, 			KC_B, 					KC_N, 			KC_M, 			KC_COMM, 		KC_DOT, 		KC_SLSH, 			QK_REP, 
        											KC_LCTL,    	KC_LSFT, 		KC_ENTER,	        	MO(L_SYM),		KC_SPC, 		KC_BSPC),
    [L_NAV] = LAYOUT_split_3x6_3(
    	_______, 	_______, 		_______, 		_______, 		_______, 		_______, 				LCTL(KC_PGUP), 	KC_HOME, 		KC_UP, 			KC_END, 		KC_NO, 				KC_NO, 
    	_______, 	_______, 		_______, 		_______, 		_______, 		_______, 				LCTL(KC_PGDN), 	KC_LEFT, 		KC_DOWN, 		KC_RGHT, 		MO(3), 				KC_NO, 
    	_______, 	_______, 		_______, 		_______, 		_______, 		_______, 				TO(1), 			KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 				KC_NO,
    												_______, 		_______, 		_______, 				KC_DEL,      	KC_ENTER, 		LCTL(KC_BSPC)),
     /* L_NUM_L Layer
      *     ┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐
      *     │       │   *   │   1   │   2   │   3   │   -   │       │       │       │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │   /   │   4   │   5   │   6   │   +   │       │       │       │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │       │   7   │   8   │   9   │   0   │       │       │       │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
      *                               ┌───────┐                                   ┌───────┐
      *                               |       |                                   |       |
      *                               │       ├───────┐                   ┌───────┤       │
      *                               |       |       |                   |       |       |
      *                               └───────┤ Enter ├───────┐   ┌───────┤       ├───────┘
      *                                       |       |       |   |       |       |
      *                                       └───────┤   .   │   │       ├───────┘
      *                                               |       |   |       |
      *                                               └───────┘   └───────┘
      */
    [L_NUM_L] = LAYOUT_split_3x6_3(
    	TO(0), 		KC_PAST, 		KC_1, 			KC_2, 			KC_3, 			KC_PMNS, 				KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 				KC_NO, 
    	KC_NO, 		KC_PSLS, 		KC_4,        	KC_5, 			KC_6,         	KC_PPLS, 				KC_NO, 			_______, 		_______, 		_______, 		_______,			KC_NO, 
    	KC_NO, 		KC_NO, 			KC_7, 			KC_8, 			KC_9, 			KC_0, 					KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 			KC_NO, 				KC_NO,
    												KC_NO, 			KC_ENTER, 		KC_DOT, 				KC_NO, 			KC_NO, 			KC_NO),
     /* L_NUM_R Layer
      *     ┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐
      *     │       │       │       │  up   │       │       │       │  Bsp  │   7   │   8   │   9   │   -   │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │       │ left  │  down │ right │       │       │       │   4   │   5   │   6   │   +   │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │       │       │       │       │       │       │       │   1   │   2   │   3   │   0   │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
      *                               ┌───────┐                                   ┌───────┐
      *                               |       |                                   |       |
      *                               │       ├───────┐                   ┌───────┤   .   │
      *                               |       |       |                   |       |       |
      *                               └───────┤       ├───────┐   ┌───────┤ Enter ├───────┘
      *                                       |       |       |   |       |       |
      *                                       └───────┤       │   │  Bsp  ├───────┘
      *                                               |       |   |       |
      *                                               └───────┘   └───────┘
      */
    [L_NUM_R] = LAYOUT_split_3x6_3(
    	TO(L_BASE), TO(L_BASE), 	TO(L_BASE), 	KC_UP, 			TO(L_BASE), 	TO(L_BASE), 			KC_BSPC,		KC_P7,			KC_P8, 			KC_P9,			KC_PMNS, 			KC_NO, 
    	TO(L_BASE), TO(L_BASE), 	KC_LEFT, 		KC_DOWN, 		KC_RGHT, 		TO(L_BASE), 			KC_NO,			KC_P4,			KC_P5,			KC_P6,			KC_PPLS, 			KC_NO, 
    	TO(L_BASE), TO(L_BASE), 	TO(L_BASE), 	TO(L_BASE), 	TO(L_BASE), 	TO(L_BASE), 			KC_NO, 			KC_P1, 			KC_P2, 			KC_P3, 			KC_P0, 				KC_NO,
    												TO(L_BASE), 	TO(L_BASE), 	TO(L_BASE), 			KC_BSPC,		KC_ENTER, 		KC_DOT),
     /* SYM Layer
      *     ┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐
      *     │   ^   │   ?   │   =   │   (   │   )   │   ~   │       │   "   │   &   │       │   |   │   +   │   ß   │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │   !   │   <   │   {   │   }   │   >   │       │   #   │       │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │       │       │   [   │   ]   │   \   │       │   /   │   *   │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
      *                               ┌───────┐                                   ┌───────┐
      *                               |       |                                   |       |
      *                               │       ├───────┐                   ┌───────┤       │
      *                               |       |       |                   |       |       |
      *                               └───────┤       ├───────┐   ┌───────┤       ├───────┘
      *                                       |       |       |   |       |       |
      *                                       └───────┤       │   │       ├───────┘
      *                                               |       |   |       |
      *                                               └───────┘   └───────┘
      */
    [L_SYM] = LAYOUT_split_3x6_3(
    	KC_CIRC, 	LSFT(KC_MINS),	LSFT(KC_0),		LSFT(KC_8),		LSFT(KC_9),		RALT(KC_RBRC),			LSFT(KC_2),		LSFT(KC_6),		KC_NO, 			RALT(KC_NUBS),	KC_RBRC, 			KC_MINS,
    	KC_NO,		LSFT(KC_1),		KC_NUBS,		RALT(KC_7),		RALT(KC_0),		RSFT(KC_NUBS),			KC_NUHS,		KC_NO,			KC_NO,			KC_NO,			KC_NO,				KC_NO,
    	KC_NO,		KC_NO,			KC_NO,			RALT(KC_8),		RALT(KC_9),		RALT(KC_MINS),			LSFT(KC_7),		LSFT(KC_RBRC),	KC_NO,			KC_NO,			KC_NO,				KC_NO,
    												KC_NO,			KC_NO,			KC_NO,					TO(0), 			KC_NO,			KC_NO),
    [L_F] = LAYOUT_split_3x6_3(
    	TO(0),		KC_NO,			KC_F8,			KC_F9,			KC_F10,			KC_F11,					KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_NO,				KC_NO,
    	KC_NO,		KC_NO,			KC_F4,			KC_F5,			KC_F6,			KC_F12,					KC_NO,			KC_NO,			KC_NO,			KC_NO,			KC_TRNS,			KC_NO,
    	KC_NO,		KC_NO,			KC_F1,			KC_F2,			KC_F3,			KC_NO,					KC_NO,			KC_TRNS,		KC_NO,			KC_NO,			KC_NO,				KC_NO,
    												KC_NO,			KC_NO,			KC_NO,					KC_NO,			KC_NO,			KC_NO),
};

enum combo_events {
    COM_NUM_R_ON,
    COM_NUM_R_OFF,
    COM_ENTER,
    COM_LEADER
};

const uint16_t PROGMEM numpad_off_combo[] =  {KC_P4, KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM numpad_on_combo[] = {RSFT_T(KC_J), LT(L_NUM_L,KC_K), RGUI_T(KC_L), COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_SPC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM leader_combo[] = {KC_LSFT, KC_ENTER, COMBO_END};

combo_t key_combos[] = {
	[COM_NUM_R_ON]  = COMBO_ACTION(numpad_on_combo),
	[COM_NUM_R_OFF] = COMBO_ACTION(numpad_off_combo),
	[COM_ENTER] = COMBO_ACTION(enter_combo),
	[COM_LEADER] = COMBO_ACTION(leader_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) 
    {
        case COM_NUM_R_ON:
        if (pressed) 
        {
            layer_on(L_NUM_R);
        }
        break;

        case COM_NUM_R_OFF:
        if (pressed) 
        {
            layer_off(L_NUM_R);
        }
        break;

        case COM_ENTER:
        if (pressed) 
        {
            tap_code(KC_ENTER);
        }
        break;

        case COM_LEADER:
        if (pressed) 
        {
            leader_start();
        }
        break;
    }
}

/* Needed to make fire combos only if they are tapped. Only working
 * if COMBO_MUST_TAP_PER_COMBO is defined. 
 */
bool get_combo_must_tap(uint16_t index, combo_t *combo)
{
	return true;
}

void keyboard_post_init_user(void) 
{
    /* tried sending Keycode here (for dealing with NUM_LOCK),
    but did not work */
}

/*  gets called everytime a key is pressed. Return value defines if
    keypress is further processed.
    See https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md#programming-the-behavior-of-any-keycode-idprogramming-the-behavior-of-any-keycode
    keyrecord_t is defined in action.h
    keyevent_t is defined in keyboard.h
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t key_timer;

    if (!host_keyboard_led_state().num_lock)
    {
        tap_code(KC_NUM_LOCK);
    }

    switch (keycode) {
    /*
    case LT_LEADER:
        if (record->event.pressed) {
            // Key was pressed
            key_timer = timer_read();
            layer_on(L_NAV); // Activate the layer immediately
        } else {
            // Key was released
            layer_off(L_NAV); // Deactivate the layer
            if (timer_elapsed(key_timer) < TAPPING_TERM) {
                // Tapped
                leader_start();
            }
        }
        return false; // Skip further processing of this key
    */
    default:
        return true; // Process all other keycodes normally
    }
}

/** gets called everytime a Led indicator FROM the host is changed
 * see https://github.com/qmk/qmk_firmware/blob/master/docs/feature_led_indicators.md 
 */
bool led_update_user(led_t led_state) {
    return true;
}

void leader_end_user(void) {

    if (leader_sequence_two_keys(KC_A, KC_T)) 
    {
        SEND_STRING("@");
    }
    else if (leader_sequence_two_keys(KC_D, KC_S)) 
    {
        SEND_STRING("./");
    }
    else if (leader_sequence_two_keys(KC_E, KC_X)) 
    {
        SEND_STRING("cd /home/lo/data/git_repos/extern/");
    }
    else if (leader_sequence_three_keys(KC_E, KC_X, KC_T))
    {
        SEND_STRING("/home/lo/data/git_repos/extern/extern.py");
        tap_code(KC_ENTER);
    }
    else if (leader_sequence_three_keys(KC_D, KC_E, KC_G)) 
    {
        register_code(KC_LSFT);
        tap_code(KC_GRV);
        unregister_code(KC_LSFT);
    }
    else if (leader_sequence_two_keys(KC_F, KC_T)) 
    {
        // front tick ´
        tap_code(KC_EQL);
        tap_code(KC_EQL);
    }
    else if (leader_sequence_two_keys(KC_F, KC_T)) 
    {
        // single quote '
        tap_code(KC_EQL);
        tap_code(KC_SPC);
    }
    else if (leader_sequence_two_keys(KC_B, KC_T)) 
    {
    	// Backtick
        SEND_STRING("`");
    }
    else if (leader_sequence_two_keys(KC_T, KC_B)) 
    {
    	// Triple Backtick
        SEND_STRING("```");
    }
    else if (leader_sequence_three_keys(KC_P, KC_E, KC_R)) 
    {
    	// Percent %
        register_code(KC_LSFT);
        tap_code(KC_5);
        unregister_code(KC_LSFT);
    }
    else if (leader_sequence_three_keys(KC_D, KC_O, KC_L)) 
    {
        SEND_STRING("$");
    }
    else if (leader_sequence_three_keys(KC_E, KC_U, KC_R)) 
    {
        register_code(KC_RALT);
        tap_code(KC_E);
        unregister_code(KC_RALT);
    }
    else if (leader_sequence_two_keys(KC_P, KC_M)) 
    {
        SEND_STRING(PRIVATE_MAIL);
    }
    else if (leader_sequence_two_keys(KC_W, KC_M)) 
    {
        SEND_STRING(WORK_MAIL);
    }
        else if (leader_sequence_two_keys(KC_C, KC_B)) 
    {
    	// Code Block
        SEND_STRING("```");
        tap_code(KC_ENTER);
        tap_code(KC_ENTER);
        SEND_STRING("```");
        tap_code(KC_UP);
    }
    else if (leader_sequence_two_keys(KC_D, KC_S)) 
    {
    	// double slash
        SEND_STRING("//");
    }
    else if (leader_sequence_two_keys(KC_C, KC_O)) 
    {
        // Comment out
        tap_code(KC_HOME);
        tap_code(KC_HOME);
            /* multiple times for some weird editors like sublime 
             * only jump to begin of whitespace or so */
        SEND_STRING("//");
    }
    else if (leader_sequence_two_keys(KC_D, KC_L)) 
    {
        // Delete Line
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        tap_code(KC_HOME);
        /* multiple times for some weird editors like sublime 
         * only jump to begin of whitespace or so */
        unregister_code(KC_LSFT);
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
    }
    else if (leader_sequence_two_keys(KC_C, KC_L)) 
    {
        // Clone Line
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        /* multiple times for some weird editors like sublime 
         * only jump to begin of whitespace or so */
        unregister_code(KC_LSFT);

        register_code(KC_LCTL);
        tap_code(KC_C);
        unregister_code(KC_LCTL);

        tap_code(KC_END);
        tap_code(KC_ENTER);

        register_code(KC_LCTL);
        tap_code(KC_V);
        unregister_code(KC_LCTL);
    }
    else if (leader_sequence_two_keys(KC_S, KC_S))
    {
    	// ß
        tap_code(KC_MINS);
    } 
    else if (leader_sequence_three_keys(KC_G, KC_R, KC_H))
    {
    	// git reset --hard
        SEND_STRING("git reset --hard");
    } 
    else if (leader_sequence_two_keys(KC_G, KC_C))
    {
    	// git reset --hard
        SEND_STRING("git checkout");
    }
    else if (leader_sequence_three_keys(KC_O, KC_M, KC_B))
    {
    	// obsidian math block
        SEND_STRING("$$");
        tap_code(KC_ENTER);
        SEND_STRING("\\begin{aligned}");
        tap_code(KC_ENTER);
        tap_code(KC_ENTER);
        SEND_STRING("\\end{aligned}");
        tap_code(KC_ENTER);
        SEND_STRING("$$");
        tap_code(KC_UP);
        tap_code(KC_UP);
    }    
    else if (leader_sequence_three_keys(KC_O, KC_M, KC_A))
    {
    	// obsidian math align
        SEND_STRING("\\begin{aligned}");
        tap_code(KC_ENTER);
        tap_code(KC_ENTER);
        SEND_STRING("\\end{aligned}");
        tap_code(KC_UP);
    }
    else if (leader_sequence_three_keys(KC_O, KC_M, KC_I))
    {
    	// obsidian math inline
        SEND_STRING("$$");
        SEND_STRING("$$");
        tap_code(KC_LEFT);
        tap_code(KC_LEFT);
    }
}
     /* empty Layer
      *     ┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     ├───────┼───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┼───────┤
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     │       │       │       │       │       │       │       │       │       │       │       │       │       │
      *     └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
      *                               ┌───────┐                                   ┌───────┐
      *                               |       |                                   |       |
      *                               │       ├───────┐                   ┌───────┤       │
      *                               |       |       |                   |       |       |
      *                               └───────┤       ├───────┐   ┌───────┤       ├───────┘
      *                                       |       |       |   |       |       |
      *                                       └───────┤       │   │       ├───────┘
      *                                               |       |   |       |
      *                                               └───────┘   └───────┘
      */