#include QMK_KEYBOARD_H
#include "version.h"

typedef enum layer_t {
  L_ST,   // stenotype
  L_DV,   // dvorak
  L_XP,   // printables (symbols/numbers)
  L_XN,   // navigation (and functions)
  L_XD,   // media (and more functions)
  L_XM,   // mouse (and misc)
  L_OH,   // one-handed
  L_OHA,  // one-handed alt
  L_OHS,  // one-handed symbols
  L_OHN,  // one-handed numbers
  L_OHV,  // one-handed navigation
  L_OHF,  // one-handed functions
  L_NP,   // number pad
  L_MS,   // mouse
  L_MOD,  // modifiers
  L_HUB,  // hub
  L_MAX,
} layer_t;

// {{{ layout key defs
// outer column keys are indexed from bottom to top
// thumb row keys are indexed from inside to outside

// left modifiers
#define KA_L1 (LSFT_T(KC_TAB))
#define KA_L2 (LCTL_T(KC_BSPC))
#define KA_L3 (LT(L_HUB, KC_ESC))

// right modifiers
#define KA_R1 (RSFT_T(KC_ENT))
#define KA_R2 (RCTL_T(KC_DEL))
#define KA_R3 (LT(L_HUB, KC_TAB))

// left thumbs
#define KA_LT1 (LT(L_XM, KC_SPC))
#define KA_LT2 (LT(L_XP, KC_ENT))
#define KA_LT3 (LT(L_XN, KC_LBRC))

// right thumbs
#define KA_RT1 (LT(L_XM, KC_SPC))
#define KA_RT2 (LT(L_XN, KC_ESC))
#define KA_RT3 (LT(L_XD, KC_RBRC))

// one-handed modifiers
#define KA_O1 (KC_LSFT)
#define KA_O2 (LT(L_MOD, KC_BSPC))
#define KA_O3 (LT(L_HUB, KC_ESC))

// one-handed thumbs
#define KA_OT1 (LT(L_OHA, KC_SPACE))
#define KA_OT2 (LT(L_OHS, KC_TAB))
#define KA_OT3 (LT(L_OHN, KC_ENT))

// home-row macros
#define LG(kc) (MT(MOD_LGUI, kc))
#define LA(kc) (MT(MOD_LALT, kc))
#define LS(kc) (MT(MOD_LSFT, kc))
#define LC(kc) (MT(MOD_LCTL, kc))
#define RC(kc) (MT(MOD_RCTL, kc))
#define RS(kc) (MT(MOD_RSFT, kc))
#define RA(kc) (MT(MOD_RALT, kc))
#define RG(kc) (MT(MOD_RGUI, kc))

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
#define DF_OH (DF(L_OH))
#define DF_NP (DF(L_NP))
#define DF_MS (DF(L_MS))
#define MO_MOD (MO(L_MOD))
#define MO_HUB (MO(L_HUB))
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
    STN_PWR, STN_N2, STN_N3, STN_N4,  STN_N5, STN_N6,  STN_N7,  STN_N8, STN_N9, STN_NA, STN_NB, STN_NC,
    STN_FN,  STN_S1, STN_TL, STN_PL,  STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
    STN_FN,  STN_S2, STN_KL, STN_WL,  STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
                             STN_RE1, STN_A,  STN_O,   STN_E,   STN_U,  STN_RE2
  ), // }}}

  // {{{ dvorak
#define RA_COMM (MT(MOD_RALT, KC_COMM))
  [L_DV] = LAYOUT_3x6_3(
    KA_L3,    KC_QUOT,  RA_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     LA(KC_R), KC_L,     KA_R3,
    KA_L2,    LG(KC_A), LA(KC_O), LS(KC_E), LC(KC_U), KC_I,     KC_D,     RC(KC_H), RS(KC_T), RA(KC_N), RG(KC_S), KA_R2,
    KA_L1,    KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KA_R1,
                                  KA_LT3,   KA_LT2,   KA_LT1,   KA_RT1,   KA_RT2,   KA_RT3
  ), // }}}

  // {{{ printables (symbols/numbers)
  // RA_COMM is coincidentally already defined
#define LG_GRV  (MT(MOD_LGUI, KC_GRV))
#define LA_MINS (MT(MOD_LALT, KC_MINS))
#define LS_EQL  (MT(MOD_LSFT, KC_EQL))
#define LC_SLSH (MT(MOD_LCTL, KC_SLSH))
  [L_XP] = LAYOUT_3x6_3(
    KA_L3,    KC_QUOT,  RA_COMM,  KC_DOT,   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     LA(KC_3), XXXXXXX,  KA_R3,
    KA_L2,    LG_GRV,   LA_MINS,  LS_EQL,   LC_SLSH,  XXXXXXX,  XXXXXXX,  RC(KC_4), RS(KC_5), RA(KC_6), KC_RGUI,  KA_R2,
    KA_L1,    KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_RALT,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_0,     KA_R1,
                                  KA_LT3,   KA_LT2,   KA_LT1,   KA_RT1,   KA_RT2,   KA_RT3
  ), // }}}

  // {{{ navigation (and functions)
#define LG_ESC  (MT(MOD_LGUI, KC_ESC))
#define LA_LEFT (MT(MOD_LALT, KC_LEFT))
#define LS_DOWN (MT(MOD_LSFT, KC_DOWN))
#define LC_RGHT (MT(MOD_LCTL, KC_RGHT))
#define RA_HOME (MT(MOD_RALT, KC_HOME))
  [L_XN] = LAYOUT_3x6_3(
    KA_L3,    KC_TAB,   RA_HOME,  KC_UP,    KC_END,   KC_PGUP,  XXXXXXX,  KC_F1,     KC_F2,     LA(KC_F3), KC_F4,     KA_R3,
    KA_L2,    LG_ESC,   LA_LEFT,  LS_DOWN,  LC_RGHT,  KC_PGDN,  XXXXXXX,  RC(KC_F5), RS(KC_F6), RA(KC_F7), RG(KC_F8), KA_R2,
    KA_L1,    KC_ENT,   KC_BSPC,  XXXXXXX,  KC_DEL,   KC_APP,   XXXXXXX,  KC_F9,     KC_F10,    KC_F11,    KC_F12,    KA_R1,
                                  KA_LT3,   KA_LT2,   KA_LT1,   KA_RT1,   KA_RT2,    KA_RT3
  ), // }}}

  // {{{ media (and more functions)
#define RA_MPRV (MT(MOD_RALT, KC_MPRV))
#define LA_F15  (MT(MOD_LALT, KC_F15))
#define RC_F17  (MT(MOD_RCTL, KC_F17))
#define RS_F18  (MT(MOD_RSFT, KC_F18))
#define RA_F19  (MT(MOD_RALT, KC_F19))
#define RG_F20  (MT(MOD_RGUI, KC_F20))
  [L_XD] = LAYOUT_3x6_3(
    KA_L3,    KC_MSTP,  RA_MPRV,  KC_MNXT,  KC_MPLY,  KC_VOLU,  XXXXXXX,  KC_F13,   KC_F14,   LA_F15,   KC_F16,   KA_R3,
    KA_L2,    KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  KC_VOLD,  XXXXXXX,  RC_F17,   RS_F18,   RA_F19,   RG_F20,   KA_R2,
    KA_L1,    KC_MSEL,  KC_MRWD,  KC_MFFD,  XXXXXXX,  KC_MUTE,  XXXXXXX,  KC_F21,   KC_F22,   KC_F23,   KC_F24,   KA_R1,
                                  KA_LT3,   KA_LT2,   KA_LT1,   KA_RT1,   KA_RT2,   KA_RT3
  ), // }}}

  [L_XM] = LAYOUT_3x6_3( // {{{  mouse (and misc)
    KA_L3,    XXXXXXX,  KC_RALT,  KC_BRK,   KC_PSCR,  KC_SYRQ,  KC_BTN3,  KC_BTN4,  KC_MS_U,  KC_BTN5,  KC_WH_U,  KA_R3,
    KA_L2,    KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  KC_INS,   KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  KA_R2,
    KA_L1,    XXXXXXX,  KC_SCRL,  KC_NUM,   KC_CAPS,  KC_PAUS,  KC_BTN2,  KC_WH_L,  XXXXXXX,  KC_WH_R,  KC_ACL2,  KA_R1,
                                  KA_LT3,   KA_LT2,   KA_LT1,   KA_RT1,   KA_RT2,   KA_RT3
  ), // }}}

  [L_OH] = LAYOUT_3x6_3_mirrored( // {{{ one-handed
    KA_O3,    KC_L,     KC_R,     KC_C,     KC_G,     KC_F,
    KA_O2,    KC_A,     KC_O,     KC_E,     KC_U,     KC_I,
    KA_O1,    KC_S,     KC_N,     KC_T,     KC_H,     KC_D,
                                  KA_OT3,   KA_OT2,   KA_OT1
  ), // }}}

  [L_OHA] = LAYOUT_3x6_3_mirrored( // {{{ one-handed alt
    _______,  KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,
    _______,  KC_Z,     KC_V,     KC_W,     KC_M,     KC_B,
    KC_LSFT,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,
                                  _______,  _______,  _______
  ), // }}}

  [L_OHS] = LAYOUT_3x6_3_mirrored( // {{{ one-handed symbols
    _______,  KC_QUOT,  KC_COMM,  KC_DOT,   XXXXXXX,  XXXXXXX,
    _______,  KC_GRV,   KC_MINS,  KC_EQL,   KC_SLSH,  XXXXXXX,
    KC_LSFT,  KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,  XXXXXXX,
                                  _______,  _______,  _______
  ), // }}}

  [L_OHN] = LAYOUT_3x6_3_mirrored_outer( // {{{ one-handed numbers
    _______,  XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,
    _______,  XXXXXXX,  KC_4,     KC_5,     KC_6,     XXXXXXX,
    KC_LSFT,  KC_0,     KC_7,     KC_8,     KC_9,     KC_0,
                                  _______,  _______,  _______
  ), // }}}

  // {{{ one-handed navigation
  // accessed through L_OHA + L_OHS
  // all modifiers are coincidentally already defined
  [L_OHV] = LAYOUT_3x6_3_mirrored_outer(
    _______,  KC_TAB,   RA_HOME,  KC_UP,    KC_END,   KC_PGUP,
    _______,  LG_ESC,   LA_LEFT,  LS_DOWN,  LC_RGHT,  KC_PGDN,
    KC_LSFT,  KC_ENT,   KC_BSPC,  XXXXXXX,  KC_DEL,   KC_APP,
                                  _______,  _______,  _______
  ), // }}}

  // {{{ one-handed functions
  // accessed through L_OHS + L_OHN
  [L_OHF] = LAYOUT_3x6_3(
    _______,   KC_F1,     RA(KC_F2), KC_F3,     KC_F4,     XXXXXXX,   XXXXXXX,   KC_F1,     KC_F2,     RA(KC_F3), KC_F4,     _______,
    _______,   LG(KC_F5), LA(KC_F6), LS(KC_F7), LC(KC_F8), XXXXXXX,   XXXXXXX,   LC(KC_F5), LS(KC_F6), LA(KC_F7), LG(KC_F8), _______,
    KC_LSFT,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    XXXXXXX,   XXXXXXX,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_RSFT,
                                     _______,   _______,   _______,   _______,   _______,   _______
  ), // }}}

  [L_NP] = LAYOUT_3x6_3_mirrored_outer( // {{{ number pad
    KA_L3,    KC_PSLS,  KC_P1,    KC_P2,    KC_P3,    KC_PMNS,
    MO_MOD,   KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
    KC_LSFT,  KC_PENT,  KC_P7,    KC_P8,    KC_P9,    KC_P0,
                                  KC_NUM,   KC_ENT,   KC_SPC
  ), // }}}

  [L_MS] = LAYOUT_3x6_3_mirrored_outer( // {{{ mouse
    KA_L3,    KC_WH_U,  KC_BTN4,  KC_MS_U,  KC_BTN5,  KC_RALT,
    MO_MOD,   KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_LCTL,
    KC_LSFT,  KC_ACL2,  KC_WH_L,  XXXXXXX,  KC_WH_R,  KC_LALT,
                                  KC_BTN3,  KC_BTN2,  KC_BTN1
  ), // }}}

  [L_MOD] = LAYOUT_3x6_3_mirrored( // {{{ modifiers
    KA_L3,    XXXXXXX,  OSM_RAL,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  OSM_GUI,  OSM_ALT,  OSM_SFT,  OSM_CTL,  OSM_GUI,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  OSM_HYP,  OSM_MEH,  XXXXXXX,
                                  OSM_RAL,  OSM_ALT,  OSM_SFT
  ), // }}}

  [L_HUB] = LAYOUT_3x6_3_mirrored( // {{{ hub
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  DF_NP,    DF_MS,    XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  DF_OH,    DF_DV,    DF_ST
  ), // }}}
};
// clang-format on

typedef struct layer_leds_t {
  bool red;
  bool green;
} layer_leds_t;

static void set_leds(layer_state_t state) { // {{{
  layer_leds_t leds;

  switch (get_highest_layer(state)) {
    case (L_ST):
    case (L_MOD):
      leds = (layer_leds_t){false, true};
      break;
    case (L_DV):
    case (L_NP):
    case (L_MS):
    case (L_OHA):
    case (L_OHS):
    case (L_OHN):
    case (L_OHV):
    case (L_OHF):
      leds = (layer_leds_t){true, false};
      break;
    case (L_OH):
    case (L_XP):
    case (L_XN):
    case (L_XD):
    case (L_XM):
      leds = (layer_leds_t){true, true};
      break;
    case (L_HUB):
    default:
      leds = (layer_leds_t){false, false};
  }

  if (leds.red)
    gpio_write_pin_high(A0);
  else
    gpio_write_pin_low(A0);

  if (leds.green)
    gpio_write_pin_high(A1);
  else
    gpio_write_pin_low(A1);
} // }}}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, L_OHA, L_OHS, L_OHV);
  state = update_tri_layer_state(state, L_OHS, L_OHN, L_OHF);

  set_leds(state | default_layer_state);

  return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  layer_clear();

  set_leds(layer_state | state);

  return state;
}

// Depends on Gemini PR being the active protocol
bool send_steno_chord_user(steno_mode_t mode, uint8_t chord[MAX_STROKE_SIZE]) {
  // (pwr) to jump to the hub
  bool k_hub = (chord[0] == 0) && (chord[1] == 0) && (chord[2] == 0) &&
    (chord[3] == 0b01000000) && (chord[4] == 0) && (chord[5] == 0);
  if (k_hub) {
    default_layer_set(1 << L_HUB);
    layer_clear();
    return false;
  }

  return true;
}

void keyboard_post_init_user(void) {
  default_layer_set(1 << L_ST);
  layer_clear();
}

/* vim: set foldmethod=marker shiftwidth=2 : */
