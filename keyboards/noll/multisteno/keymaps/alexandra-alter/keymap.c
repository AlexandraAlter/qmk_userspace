#include QMK_KEYBOARD_H
#include "version.h"

typedef enum layer_t {
  L_ST,   // stenotype
  L_DV,   // dvorak
  L_QT,   // qwerty
  L_XNM,  // navigation/mouse
  L_XSN,  // symbols/numbers
  L_XFE,  // functions/extras
  L_XFM,  // functions/media
  L_OH,   // one-handed
  L_OHA,  // one-handed alt
  L_OHS,  // one-handed symbols
  L_OHN,  // one-handed numbers
  L_OHV,  // one-handed navigation
  L_OHM,  // one-handed modifiers
  L_NP,   // number pad
  L_MS,   // mouse
  L_HUB,  // hub
  L_MAX,
} layer_t;

// {{{ layout key defs
// outer column keys are indexed from bottom to top
// thumb row keys are indexed from inside to outside

// to assign: symbols, functions, numbers, extras, mouse, alt, ctl, super, media

// left modifiers
#define KA_L3 (LT(L_HUB, KC_ESC))
#define KA_L2 (LCTL_T(KC_BSPC))
#define KA_L1 (LGUI_T(KC_TAB))

// left thumbs
#define KA_LT3 (LT(L_XFE, KC_LBRC))
#define KA_LT2 (LT(L_XSN, KC_ENT))
#define KA_LT1 (LT(L_XNM, KC_SPC))

// right modifiers
#define KA_R3 (LT(L_HUB, KC_TAB))
#define KA_R2 (RCTL_T(KC_DEL))
#define KA_R1 (RGUI_T(KC_ENT))

// right thumbs
#define KA_RT3 (RALT_T(KC_RBRC))
#define KA_RT2 (LALT_T(KC_ESC))
#define KA_RT1 (KC_RSFT)

// one-handed modifiers
#define KA_O3 (LT(L_HUB, KC_ESC))
#define KA_O2 (LT(L_OHM, KC_BSPC))
#define KA_O1 (KC_LSFT)

// one-handed thumbs
#define KA_OT3 (LT(L_OHN, KC_ENT))
#define KA_OT2 (LT(L_OHS, KC_TAB))
#define KA_OT1 (LT(L_OHA, KC_SPACE))

// one-shot modifiers
#define OSM_SFT (OSM(MOD_LSFT))
#define OSM_CTL (OSM(MOD_LCTL))
#define OSM_ALT (OSM(MOD_LALT))
#define OSM_GUI (OSM(MOD_LGUI))
#define OSM_RAL (OSM(MOD_RALT))
#define OSM_HYP (OSM(MOD_HYPR))
#define OSM_MEH (OSM(MOD_MEH))

// layers switching
#define DF_ST (DF(L_ST))
#define DF_DV (DF(L_DV))
#define DF_QT (DF(L_QT))
#define DF_OH (DF(L_OH))
#define DF_NP (DF(L_NP))
#define DF_MS (DF(L_MS))
// }}}

// {{{ layout convenience defs
// clang-format off
#define LAYOUT_3x6_3_mirrored(                                  \
  k00, k01, k02, k03, k04, k05,                                 \
  k10, k11, k12, k13, k14, k15,                                 \
  k20, k21, k22, k23, k24, k25,                                 \
                 k30, k31, k32)                                 \
LAYOUT_3x6_3(                                                   \
  k00, k01, k02, k03, k04, k05,   k05, k04, k03, k02, k01, k00, \
  k10, k11, k12, k13, k14, k15,   k15, k14, k13, k12, k11, k10, \
  k20, k21, k22, k23, k24, k25,   k25, k24, k23, k22, k21, k20, \
                 k30, k31, k32,   k32, k31, k30)

#define LAYOUT_3x6_3_mirrored_outer(                            \
  k00, k01, k02, k03, k04, k05,                                 \
  k10, k11, k12, k13, k14, k15,                                 \
  k20, k21, k22, k23, k24, k25,                                 \
                 k30, k31, k32)                                 \
LAYOUT_3x6_3(                                                   \
  k00, k01, k02, k03, k04, k05,   k05, k02, k03, k04, k01, k00, \
  k10, k11, k12, k13, k14, k15,   k15, k12, k13, k14, k11, k10, \
  k20, k21, k22, k23, k24, k25,   k25, k22, k23, k24, k21, k20, \
                 k30, k31, k32,   k32, k31, k30)
// }}}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_ST] = LAYOUT_3x6_3( // {{{ stenotype
    KA_L3,   STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_PWR,
    STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    STN_FN,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                               STN_RE1, STN_A,   STN_O,   STN_E,   STN_U,   STN_RE2
  ), // }}}

  [L_DV] = LAYOUT_3x6_3( // {{{ dvorak
    KA_L3,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KA_R3,
    KA_L2,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KA_R2,
    KA_L1,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KA_R1,
                               KA_LT3,  KA_LT2,  KA_LT1,  KA_RT1,  KA_RT2,  KA_RT3
  ), // }}}

  [L_QT] = LAYOUT_3x6_3( // {{{ qwerty
    KA_L3,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KA_R3,
    KA_L2,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KA_R2,
    KA_L1,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KA_R1,
                               KA_LT3,  KA_LT2,  KA_LT1,  KA_RT1,  KA_RT2,  KA_RT3
  ), // }}}

  [L_XNM] = LAYOUT_3x6_3( // {{{ navigation/mouse
    KA_L3,   KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_BTN3, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, KA_R3,
    KA_L2,   KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KA_R2,
    KA_L1,   KC_ENT,  KC_BSPC, XXXXXXX, KC_DEL,  KC_APP,  KC_BTN2, KC_WH_L, XXXXXXX, KC_WH_R, KC_ACL2, KA_R1,
                               KA_LT3,  KA_LT2,  KA_LT1,  KA_RT1,  KA_RT2,  KA_RT3
  ), // }}}

  [L_XSN] = LAYOUT_3x6_3( // {{{ symbols/numbers
    KA_L3,   KC_QUOT, KC_COMM, KC_DOT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, KA_R3,
    KA_L2,   KC_GRV,  KC_MINS, KC_EQL,  KC_SLSH, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, KA_R2,
    KA_L1,   KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_RALT, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    KA_R1,
                               KA_LT3,  KA_LT2,  KA_LT1,  KA_RT1,  KA_RT2,  KA_RT3
  ), // }}}

  [L_XFE] = LAYOUT_3x6_3( // {{{ functions/extras
    KA_L3,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_SYRQ, XXXXXXX, XXXXXXX, KC_CAPS, KC_SCRL, XXXXXXX, KA_R3,
    KA_L2,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM,  KC_PSCR, KA_R2,
    KA_L1,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_BRK,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KA_R1,
                               KA_LT3,  KA_LT2,  KA_LT1,  KA_RT1,  KA_RT2,  KA_RT3
  ), // }}}

  [L_XFM] = LAYOUT_3x6_3( // {{{ functions/media
    KA_L3,   KC_F13,  KC_F14,  KC_F15,  KC_F16,  XXXXXXX, KC_BRIU, KC_VOLU, KC_MPRV, KC_MNXT, KC_MSEL, KC_PWR,
    KA_L2,   KC_F17,  KC_F18,  KC_F19,  KC_F20,  XXXXXXX, KC_BRID, KC_VOLD, KC_MSTP, KC_MPLY, XXXXXXX, KC_SLEP,
    KA_L1,   KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, XXXXXXX, KC_MUTE, KC_MRWD, KC_MFFD, XXXXXXX, KC_WAKE,
                               KA_LT3,  KA_LT2,  KA_LT1,  KA_RT1,  KA_RT2,  KA_RT3
  ), // }}}

  [L_OH] = LAYOUT_3x6_3_mirrored( // {{{ one-handed
    KA_O3,   KC_L,    KC_R,    KC_C,    KC_G,    KC_F,
    KA_O2,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
    KA_O1,   KC_S,    KC_N,    KC_T,    KC_H,    KC_D,
                               KA_OT3,  KA_OT2,  KA_OT1
  ), // }}}

  [L_OHA] = LAYOUT_3x6_3_mirrored( // {{{ one-handed alt
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,
    _______, KC_Z,    KC_V,    KC_W,    KC_M,    KC_B,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,
                               _______, _______, _______
  ), // }}}

  [L_OHS] = LAYOUT_3x6_3_mirrored( // {{{ one-handed symbols
    _______, KC_QUOT, KC_COMM, KC_DOT,  XXXXXXX, XXXXXXX,
    _______, KC_GRV,  KC_MINS, KC_EQL,  KC_SLSH, XXXXXXX,
    KC_LSFT, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
                               _______, _______, _______
  ), // }}}

  [L_OHN] = LAYOUT_3x6_3_mirrored_outer( // {{{ one-handed numbers
    _______, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX,
    _______, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,
    KC_LSFT, KC_0,    KC_7,    KC_8,    KC_9,    KC_0,
                               _______, _______, _______
  ), // }}}

  [L_OHV] = LAYOUT_3x6_3_mirrored( // {{{ one-handed navigation
    _______, KC_TAB,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,
    _______, KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    KC_LSFT, KC_ENT,  KC_BSPC, XXXXXXX, KC_DEL,  KC_APP,
                               _______, _______, _______
  ), // }}}

  [L_OHM] = LAYOUT_3x6_3_mirrored( // {{{ one-handed modifiers
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, OSM_RAL, OSM_GUI, OSM_CTL, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, OSM_HYP, OSM_MEH, XXXXXXX,
                               XXXXXXX, OSM_ALT, OSM_SFT
  ), // }}}

  [L_MS] = LAYOUT_3x6_3_mirrored_outer( // {{{ mouse
    KA_L3,   KC_WH_U, KC_BTN4, KC_MS_U, KC_BTN5, KC_BTN3,
    KC_LCTL, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
    KC_LGUI, KC_ACL2, KC_WH_L, XXXXXXX, KC_WH_R, KC_BTN2,
                               KC_RALT, KC_LALT, KC_LSFT
  ), // }}}

  [L_NP] = LAYOUT_3x6_3_mirrored_outer( // {{{ number pad
    KA_L3,   KC_PSLS, KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
    KC_LCTL, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_LSFT, KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_P0,
                               KC_RALT, KC_LALT, KC_LSFT
  ), // }}}

  [L_HUB] = LAYOUT_3x6_3_mirrored( // {{{ hub
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, XXXXXXX, DF_QT,   DF_NP,   DF_MS,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               DF_OH,   DF_DV,   DF_ST
  ), // }}}
};
// clang-format on

typedef struct layer_leds_t {
  bool red;
  bool green;
} layer_leds_t;

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  // layer handling

  state = update_tri_layer_state(state, L_XSN, L_XFE, L_XFM);
  state = update_tri_layer_state(state, L_OHA, L_OHS, L_OHV);

  // led handling
  layer_leds_t leds;
  switch (get_highest_layer(state)) {
    case (L_ST):
      leds = (layer_leds_t){false, true};
      break;
    case (L_QT):
    case (L_DV):
    case (L_OH):
      leds = (layer_leds_t){true, false};
      break;
    case (L_XNM):
    case (L_XSN):
    case (L_XFE):
    case (L_XFM):
    case (L_OHA):
    case (L_OHS):
    case (L_OHN):
    case (L_OHV):
    case (L_OHM):
      leds = (layer_leds_t){true, true};
      break;
    case (L_NP):
    case (L_MS):
    case (L_HUB):
    default:
      leds = (layer_leds_t){false, false};
  }

  if (leds.red)
    gpio_write_pin_high(A0);
  else
    gpio_write_pin_low(A0);

  if (leds.green)
    gpio_write_pin_low(A1);
  else
    gpio_write_pin_low(A1);

  return state;
} // }}}

layer_state_t default_layer_state_set_user(layer_state_t state) { // {{{
  layer_clear();

  return state;
} // }}}

void keyboard_post_init_user(void) { // {{{
  default_layer_set(1 << L_ST);
  layer_clear();
} // }}}

/* vim: set foldmethod=marker shiftwidth=2 : */
