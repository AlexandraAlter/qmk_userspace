#include QMK_KEYBOARD_H

typedef enum layer_t {
  L_TY,   // typing
  L_NV,   // navigation
  L_SY,   // symbols
  L_XT,   // extras
  L_MAX,
} layer_t;

#define KA_SPC  (LT(L_NV, KC_SPC))
#define KA_BSPC (LT(L_SY, KC_BSPC))
#define KA_ENT  (LT(L_SY, KC_ENT))
#define KA_APP  (LT(L_XT, KC_APP))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* layout template
  // {{{ layer
  [L_] = LAYOUT_60_ansi(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ), // }}}
  */

  // {{{ typing
#define RA_W    (MT(MOD_RALT, KC_W))
#define LG_A    (MT(MOD_LGUI, KC_A))
#define LA_S    (MT(MOD_LALT, KC_S))
#define LS_D    (MT(MOD_LSFT, KC_D))
#define LC_F    (MT(MOD_LCTL, KC_F))
#define LA_O    (MT(MOD_LALT, KC_O))
#define RC_J    (MT(MOD_RCTL, KC_J))
#define RS_K    (MT(MOD_RSFT, KC_K))
#define RA_L    (MT(MOD_RALT, KC_L))
#define RG_SCLN (MT(MOD_RGUI, KC_SCLN))
  [L_TY] = LAYOUT_60_ansi(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    RA_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    LA_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KA_BSPC, LG_A,    LA_S,    LS_D,    LC_F,    KC_G,    KC_H,    RC_J,    RS_K,    RA_L,    RG_SCLN, KC_QUOT,          KA_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                            KA_SPC,                             KC_RALT, KC_RGUI, KA_APP,  KC_RCTL
  ), // }}}

  // {{{ navigation
#define LG_ESC  (MT(MOD_LGUI, KC_ESC))
#define LA_LEFT (MT(MOD_LALT, KC_LEFT))
#define LS_DOWN (MT(MOD_LSFT, KC_DOWN))
#define LC_RGHT (MT(MOD_LCTL, KC_RGHT))
#define RA_HOME (MT(MOD_RALT, KC_HOME))
  [L_NV] = LAYOUT_60_ansi(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, XXXXXXX, RA_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, XXXXXXX, KC_INS,  KC_LALT, KC_PSCR, KC_PAUS, KC_BRK,  _______,
    _______, LG_ESC,  LA_LEFT, LS_DOWN, LC_RGHT, KC_PGDN, XXXXXXX, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, XXXXXXX,          _______,
    _______, KC_ENT,  KC_BSPC, XXXXXXX, KC_DEL,  KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ), // }}}

  // {{{ symbols
#define RA_MPRV (MT(MOD_RALT, KC_MPRV))
#define LA_RBRC (MT(MOD_LALT, KC_RBRC))
#define RC_EQL  (MT(MOD_RCTL, KC_EQL))
#define RS_MINS (MT(MOD_RSFT, KC_MINS))
#define RA_GRV  (MT(MOD_RALT, KC_GRV))
#define RG_SCLN (MT(MOD_RGUI, KC_SCLN))
  [L_SY] = LAYOUT_60_ansi(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, KC_MSTP, RA_MPRV, KC_MNXT, KC_MPLY, KC_VOLU, XXXXXXX, KC_BSLS, KC_LBRC, LA_RBRC, KC_QUOT, KC_LBRC, KC_RBRC, _______,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_VOLD, XXXXXXX, RC_EQL,  RS_MINS, RA_GRV,  RG_SCLN, KC_QUOT,          _______,
    _______, KC_MSEL, KC_MRWD, KC_MFFD, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH,                   _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ), // }}}

  [L_XT] = LAYOUT_60_ansi( // {{{ extras
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, BL_STEP, KC_SYRQ, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR, KC_PAUS, KC_BRK,  _______,
    _______, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, BL_TOGG, XXXXXXX, XXXXXXX, KC_CAPS, KC_SCRL, XXXXXXX, XXXXXXX,          _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, KC_NUM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ), // }}}
};

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  state = update_tri_layer_state(state, L_NV, L_SY, L_XT);

  return state;
} // }}}


/* vim: set foldmethod=marker shiftwidth=2 : */
