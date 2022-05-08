#include QMK_KEYBOARD_H
#ifdef COMBO_ENABLE
enum combo_events {
    /* 
    Symbols combo
    */
    
    SYM_EXLM,
    SYM_QUES,
    SYM_MINS,

    /*
    // Steno-lite combos
    // These let me type common words and n-grams
    // more quickly in one single stroke. Based on Plover finger patterns, not actual keys
    */
    STE_AND,
    STE_THIS,
    STE_ABOUT,
    STE_WILL,
    STE_FOR,
    STE_FROM,
    STE_HAVE,
    STE_EXPL,
    STE_WHY,
    STE_MENT,
    STE_DID,
    STE_ALRD,
    STE_ALRG,
    STE_ALSO,
    


    // This must be the last item in the enum.
    // This is used to automatically update the combo count.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM SYM_QUES_COMBO[]   = {KC_R,     KC_S,    KC_U,     KC_Y,     COMBO_END};
const uint16_t PROGMEM SYM_EXLM_COMBO[]   = {KC_W,     KC_F,    KC_E,     KC_I,     COMBO_END};
const uint16_t PROGMEM SYM_MINS_COMBO[]   = {KC_P,     KC_U,    KC_E,     COMBO_END};

const uint16_t PROGMEM STE_T_S_COMBO[]    = {KC_W,     KC_P,    COMBO_END};
const uint16_t PROGMEM STE_ABT_COMBO[]    = {KC_F,     KC_S,    COMBO_END};
const uint16_t PROGMEM STE_WIL_COMBO[]    = {KC_P,     KC_T,    COMBO_END};
const uint16_t PROGMEM STE_HV_COMBO[]     = {KC_A,     KC_T,    COMBO_END};
const uint16_t PROGMEM STE_DID_COMBO[]    = {KC_W,     KC_R,    COMBO_END};

const uint16_t PROGMEM STE_A_COMBO[]      = {KC_A,     KC_R,    KC_F,    COMBO_END};
const uint16_t PROGMEM STE_F_COMBO[]      = {KC_W,     KC_F,    KC_N,    COMBO_END};
const uint16_t PROGMEM STE_FRM_COMBO[]    = {KC_W,     KC_F,    KC_T,    COMBO_END};
const uint16_t PROGMEM STE_WHY_COMBO[]    = {KC_R,     KC_S,    KC_T,    COMBO_END};
const uint16_t PROGMEM STE_MENT_COMBO[]   = {KC_L,     KC_U,    KC_Y,    COMBO_END};
const uint16_t PROGMEM STE_ALRD_COMBO[]   = {KC_P,     KC_T,    KC_N,    COMBO_END};
const uint16_t PROGMEM STE_ALSO_COMBO[]   = {KC_P,     KC_T,    KC_O,    COMBO_END};

const uint16_t PROGMEM STE_EXPL_COMBO[]   = {KC_R,     KC_F,    KC_U,    KC_Y,       COMBO_END};
const uint16_t PROGMEM STE_ALRG_COMBO[]   = {KC_P,     KC_T,    KC_N,    KC_SCLN,    COMBO_END};


combo_t key_combos[] = {
    [SYM_EXLM]         = COMBO(SYM_EXLM_COMBO, KC_EXLM),
    [SYM_QUES]         = COMBO(SYM_QUES_COMBO, KC_QUES),
    [SYM_MINS]         = COMBO(SYM_MINS_COMBO, KC_MINS),

    [STE_THIS]        = COMBO_ACTION(STE_T_S_COMBO),
    [STE_AND]         = COMBO_ACTION(STE_A_COMBO),
    [STE_ABOUT]       = COMBO_ACTION(STE_ABT_COMBO),
    [STE_WILL]        = COMBO_ACTION(STE_WIL_COMBO),
    [STE_FOR]         = COMBO_ACTION(STE_F_COMBO),
    [STE_FROM]        = COMBO_ACTION(STE_FRM_COMBO),
    [STE_HAVE]        = COMBO_ACTION(STE_HV_COMBO),
    [STE_EXPL]        = COMBO_ACTION(STE_EXPL_COMBO),
    [STE_WHY]         = COMBO_ACTION(STE_WHY_COMBO),
    [STE_MENT]        = COMBO_ACTION(STE_MENT_COMBO),
    [STE_DID]         = COMBO_ACTION(STE_DID_COMBO),
    [STE_ALRD]         = COMBO_ACTION(STE_ALRD_COMBO),
    [STE_ALRG]         = COMBO_ACTION(STE_ALRG_COMBO),
    [STE_ALSO]         = COMBO_ACTION(STE_ALSO_COMBO)

};

void process_combo_event(uint16_t combo_index, bool pressed) {
    
    switch(combo_index) {

        case STE_AND:
            if (pressed) {
                SEND_STRING("and ");
            }
        break;

        case STE_THIS:
            if (pressed) {
                SEND_STRING("this ");
            }
        break;

        case STE_ABOUT:
            if (pressed) {
                SEND_STRING("about ");
            }
        break;

        case STE_WILL:
            if (pressed) {
                SEND_STRING("will ");
            }
        break;

        case STE_FOR:
            if (pressed) {
                SEND_STRING("for ");
            }
        break;

        case STE_FROM:
            if (pressed) {
                SEND_STRING("from ");
            }
        break;

        case STE_HAVE:
            if (pressed) {
                SEND_STRING("have ");
            }
        break; 

        case STE_EXPL:
            if (pressed) {
                SEND_STRING("example ");
            }
        break;

        case STE_WHY:
            if (pressed) {
                SEND_STRING("why ");
            }
        break;

        case STE_MENT:
            if (pressed) {
                SEND_STRING("ment "); 
            }
        break;

        case STE_DID:
            if (pressed) {
                SEND_STRING("did "); 
            }
        break;

        case STE_ALRD:
            if (pressed) {
                SEND_STRING("already "); 
            }
        break;

        case STE_ALRG:
            if (pressed) {
                SEND_STRING("alright "); 
            }
        break;

        case STE_ALSO:
            if (pressed) {
                SEND_STRING("also "); 
            }
        break;


    }
};

#endif