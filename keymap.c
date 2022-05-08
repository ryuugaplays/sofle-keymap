
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
// define SET_INDICATORS(hsv) \ //
	 //{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \//
     //{35+0, 1, hsv}//
#define SET_UNDERGLOW(hsv) \
	{0, 6, hsv}, \
    {35, 6, hsv}
#define SET_NUMPAD(hsv)     \
	{52, 3, hsv}, \
	  {57, 3, hsv}, \
	  {62, 3, hsv}
      
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}


#define SET_OUTER_COL(hsv) \
	{6, 5, hsv}, \
	  {15, 2, hsv}, \
      {25, 2, hsv}, \
      {41, 5, hsv}, \
      {50, 2, hsv}, \
      {60, 2, hsv}

#define SET_THUMB_CLUSTER(hsv) 	\
      {50, 2, hsv}, \
      {60, 2, hsv}

#define SET_LAYER_ID(hsv) 	\
    {0, 6, hsv}, \
    {35, 6,hsv}, \
    {6, 5, hsv}, \
	  {15, 2, hsv}, \
      {25, 2, hsv}, \
      {41, 5, hsv}, \
      {50, 2, hsv}, \
      {60, 2, hsv}

	// {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \ //
    // {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \ // 



enum sofle_layers {
    _DEFAULTS = 0,
    _COLEMAKDH = 0,
    _GAMING,
    _NUMPAD,
    _NAV,
    _ADJUST,
    _SWITCH
};

enum custom_keycodes {
    KC_COLEMAKDH = SAFE_RANGE,
    KC_GAMING,
    KC_NUMPAD,
    KC_NAV,
    KC_ADJUST,
    KC_D_MUTE,
    KC_SWITCH, 
    GAM_ENT
    
};

uint16_t last_keycode;

#ifdef TAP_DANCE_ENABLE
enum {
    DOT_TD = 0,
    LANG_TD
};

#define TD_DOT TD(DOT_TD)
#define TD_LANG TD(LANG_TD)
#else
#define TD_DOT KC_DOT
#define TD_LANG KC_GRV
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F12 |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LALT |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |      |  /   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | WIN  |NUMPAD| LCTR | Space| /Enter  /       \Bspc  \  |LSHFT |      | NAV  |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAKDH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F12,  TD_LANG,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LALT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  XXXXXXX,    XXXXXXX, KC_K,   KC_H,   KC_COMM, TD_DOT,  XXXXXXX, KC_SLSH,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_LGUI, KC_NUMPAD, KC_LCTRL,  KC_SPC,  KC_ENT,   KC_BSPC, KC_LSFT,  XXXXXXX,  KC_NAV,  XXXXXXX
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/   
),

/*
 * GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   T  |   Q  |   W  |   E  |   R  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   G  |   A  |   S  |   D  |   F  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LALT  |   B  |   Z  |   X  |   C  |   V  |-------|    |-------|   N  |   M  |   ,  |   .  |   '  |  /   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |NUMPAD| LCTR | Space| /Enter  /       \Bspc  \  |LSHFT |      | NAV  |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GAMING] = LAYOUT( 
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_GRV, \
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------| 
  KC_TAB,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    XXXXXXX, \
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------| 
  XXXXXXX,  KC_G,   KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, XXXXXXX, \
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------| 
  KC_LALT  ,KC_B,   KC_Z,    KC_X,    KC_C,    KC_V,   XXXXXXX,   XXXXXXX,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_QUOT, KC_SLSH, \
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------| 
                 XXXXXXX, KC_NUMPAD,KC_LCTRL, KC_SPC,  KC_ENT,   KC_BSPC, KC_LSFT,  XXXXXXX,  KC_NAV, XXXXXXX \
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/  
),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |   \  |   *  |   -  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  &   |  (   |   @  |   {  |   }  |                    |   %  |   7  |   8  |   9  |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  !   |   ?  |   [  |   ]  |-------.    ,-------|   $  |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  |   |   #  |   ^  |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | WIN  |      | LCTR |  _   | /Enter  /       \Bspc  \  |  0   |  .   |ADJUST|   =  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_SLSH, KC_ASTR, KC_MINS,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, KC_AMPR, KC_LPRN, KC_AT,   KC_LCBR, KC_RCBR,                   KC_PERC, KC_P7,  KC_P8,   KC_P9,   KC_PLUS,  _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, KC_BSLS, KC_EXLM, KC_QUES, KC_LBRC, KC_RBRC,                   KC_DLR , KC_P4,  KC_P5,   KC_P6,   XXXXXXX,  XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, KC_PIPE, KC_HASH, KC_CIRC, XXXXXXX,_______,    _______,XXXXXXX,KC_P1,  KC_P2,   KC_P3,   XXXXXXX,  _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, XXXXXXX, _______, KC_UNDS,  _______,    _______,  KC_P0,    KC_PDOT, KC_ADJUST, KC_EQL
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),


/* NAV
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |  Esc |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | PWrd |  Up  | NWrd |      |                    | PSCR |      |      |      |      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Left | Down | Right| Caps |-------.    ,-------| INS  |< desk|      |desk >|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | HOME |      | END  |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | WIN  |SWITCH| LCTR | Space| /Enter  /       \Bspc  \  |LSHFT |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, _______ , _______ , _______ , _______ , _______,               _______,  _______  , _______,  _______ ,  _______ ,_______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, XXXXXXX, C(KC_LEFT), KC_UP, C(KC_RGHT), XXXXXXX,               KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,                 KC_INS,C(G(KC_LEFT)),XXXXXXX,C(G(KC_RGHT)), XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  XXXXXXX, KC_HOME, XXXXXXX, KC_END, XXXXXXX,_______,    _______,XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, XXXXXXX, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |EEP_RST|     |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |RGB_TOG|hue^ |sat ^ | bri ^|      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | mode |hue dn|sat d |bri dn|      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | WIN  |      | LCTR | Space| /Enter  /       \Bspc  \  |LSHFT |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RESET,   XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, XXXXXXX, _______, _______, _______,     _______, _______, _______, XXXXXXX, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),


/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |_COLEM|_GAME |_STENO|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RESET |      |      |      |      |      |                    |      |      |      |      |      |EEP_RST|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | WIN  |      | LCTR | Space| /Enter  /       \Bspc  \  |LSHFT |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RESET , XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, 	                  KC_NO,   XXXXXXX, KC_NO,   KC_NO,   KC_NO,   EEP_RST,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
   KC_NO,   KC_NO, XXXXXXX,   KC_NO,   KC_NO,   KC_NO, 		              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX,  KC_NO,  XXXXXXX,  KC_NO,   KC_NO,   KC_NO, KC_NO,	   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
		         KC_NO,    KC_NO,  KC_NO,   KC_NO,    KC_NO,       KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/

),




};


static void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {

        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LSHIFT));

            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

void sentence_end_finished (qk_tap_dance_state_t *state, void *user_data) {
    last_keycode = KC_DOT;
}


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Grave, twice for IME Change
    // Double tap the dot key to quickly flow from one sentence to another.
    [LANG_TD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, A(KC_GRV)),
    [DOT_TD]  = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, sentence_end_finished, NULL),

};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// COLEMAKDH,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);


// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	// SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE)

    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_colemakdh_lights,
	layer_num_lights,// overrides layer 1
    layer_numpad_lights,
	layer_symbol_lights,
    layer_command_lights,
	layer_switcher_lights  // Overrides other layers
	
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


	rgblight_set_layer_state(1, layer_state_cmp(state, _GAMING));
	rgblight_set_layer_state(2, layer_state_cmp(state, _NUMPAD));
	rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
	rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Ryuuga\nPlays"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {         
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CmkDH"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        
        case _COLEMAKDH:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
	    case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
	    case _GAMING:
            oled_write_P(PSTR("Game\n"), false);
            break;	        
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;        
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;

        //case KC_GAMING:
        //    if (record->event.pressed) {
        //        set_single_persistent_default_layer(_GAMING);
        //    }
        //    return false;/

        case KC_NUMPAD:
            if (record->event.pressed) {
                layer_on(_NUMPAD);
            } else {
                layer_off(_NUMPAD);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

        case KC_SWITCH:
            if (record->event.pressed) {
                layer_on(_SWITCH);
            } else {
                layer_off(_SWITCH);
            }
            return false;

        case GAM_ENT:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                layer_invert(_GAMING);
            }
            return false;

        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {				
				case _COLEMAKDH:
					if (clockwise) {
						tap_code(KC_PGDOWN);
					} else {
						tap_code(KC_PGUP);
					}
				break;
			case _NAV:
			case _NUMPAD:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
		}
    }
    return true;
}

#endif
