#include QMK_KEYBOARD_H
#include "version.h"
#include "shavian.h"

extern keyboard_config_t keyboard_config;

// Basic categories:
//   Alphas
//     Must be usable with either hand
//   Numerics
//   Symbols
//     Often paired with numerics
//   Navigation
//   Functions
//   Mouse
//     If I'm using the mouse here, I probably have a free right hand
//     Causes problems- unsuitable for home-row mods
//   Misc
//   Media
//     Doesn't need modifiers
//   Internal keyboard functions
//     Doesn't need modifiers save shift
//   Extra functions
// One-handed categories:
//   Alphas on two layers
//   Assume it's only for left-handed use
//   Anything with an existing left-hand with one-handed modifiers can be reused
//   Supplement missing modifiers by using a mod-hold layer
//   Fit for the other hand using the swap hands feature
// Suggested layers:
//   Forced whole-board layers: GA, DV, QT, SHV, ST, STC
//   Supplemental two-handed layers: SY/NU, NA/FN, ME/FN2, MI/MS
//   Supplemental one-handed layers: NU, FN, FN2, MS
//   One-handed layers: OH, OHA, OHM
//   Management layers: HUB

typedef enum layer_t {
  L_GA,   // gaming
  L_DV,   // dvorak
  L_QT,   // qwerty
  L_SHV,  // shavian
  L_OH,   // one-handed
  L_OHA,  // one-handed alt
  L_OHM,  // one-handed modifiers
  L_ST,   // stenotype
  L_STC,  // stenotype comfort
  L_XSN,  // symbols/numbers
  L_XNF,  // navigation/functions
  L_XMF,  // media/functions 2
  L_XMM,  // misc/mouse
  L_GAN, // gaming lower
  L_GAF, // gaming raise
  L_GAX, // gaming adjust
  // layers below this point cannot be used in LT macros
  L_NP,   // number pad
  L_MS,   // mouse
  L_FN,   // functions
  L_HUB,  // hub
  L_SYS,  // system
  L_MAX,
} layer_t;

typedef enum custom_keycode_t { // {{{
  LED_CYC = SAFE_RANGE,         // cycle led level
  RGB_SLD,                      // pause LED animation
  G_SPC,                        // gaming space bar
  G_S_CY,                       // gaming space bar cycle
} custom_keycode_t;             // }}}

// {{{ unicode defs
typedef enum unicode_names {
  SHAVIAN_UNICODE_NAMES()
} unicode_names;

const uint32_t PROGMEM unicode_map[] = {
  SHAVIAN_UNICODE_MAP()
};
// }}}

// {{{ layout key defs
#define RGB_TLC TOGGLE_LAYER_COLOR

#define KA_SPC (LT(L_XMM, KC_SPC))
#define KA_LWR (LT(L_XSN, KC_LBRC))
#define KA_RAI (LT(L_XNF, KC_RBRC))

#define KA_OSPC (LT(L_OHA, KC_SPC))
#define KA_OLWR (LT(L_XSN, KC_TAB))
#define KA_ORAI (LT(L_XNF, KC_ENT))

#define KA_GLWR (MO(L_GAN))
#define KA_GRAI (MO(L_GAF))

#define LG(kc) (MT(MOD_LGUI, kc))
#define LA(kc) (MT(MOD_LALT, kc))
#define LS(kc) (MT(MOD_LSFT, kc))
#define LC(kc) (MT(MOD_LCTL, kc))
#define RC(kc) (MT(MOD_RCTL, kc))
#define RS(kc) (MT(MOD_RSFT, kc))
#define RA(kc) (MT(MOD_RALT, kc))
#define RG(kc) (MT(MOD_RGUI, kc))

#define OSM_SFT (OSM(MOD_LSFT))
#define OSM_CTL (OSM(MOD_LCTL))
#define OSM_ALT (OSM(MOD_LALT))
#define OSM_GUI (OSM(MOD_LGUI))
#define OSM_RAL (OSM(MOD_RALT))
#define OSM_HYP (OSM(MOD_HYPR))
#define OSM_MEH (OSM(MOD_MEH))

#define LG_ESC  (MT(MOD_LGUI, KC_ESC))
#define LC_BSPC (MT(MOD_LCTL, KC_BSPC))
#define LS_TAB  (MT(MOD_LSFT, KC_TAB))

#define RG_TAB  (MT(MOD_RGUI, KC_TAB))
#define RC_DEL  (MT(MOD_RCTL, KC_DEL))
#define RS_ENT  (MT(MOD_RSFT, KC_ENT))
#define LA_RGHT (MT(MOD_LALT, KC_RIGHT))
#define RG_UP   (MT(MOD_RGUI, KC_UP))
#define RC_DOWN (MT(MOD_RCTL, KC_DOWN))
#define RA_LEFT (MT(MOD_RALT, KC_LEFT))

#define MO_MS  (MO(L_MS))
#define MO_HUB (MO(L_HUB))
#define MO_SYS (MO(L_SYS))

#define DF_GA  (DF(L_GA))
#define DF_DV  (DF(L_DV))
#define DF_QT  (DF(L_QT))
#define DF_SHV (DF(L_SHV))
#define DF_OH  (DF(L_OH))
#define DF_ST  (DF(L_ST))
#define DF_STC (DF(L_STC))
#define DF_NP  (DF(L_NP))
#define DF_MS  (DF(L_MS))
#define DF_FN  (DF(L_FN))
// }}}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DV] = LAYOUT_planck_grid( // {{{ dvorak
    LG_ESC,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     LA(KC_R), KC_L,     RG_TAB,
    LC_BSPC,  LG(KC_A), LA(KC_O), LS(KC_E), LC(KC_U), KC_I,     KC_D,     RC(KC_H), RS(KC_T), RA(KC_N), RG(KC_S), RC_DEL,
    LS_TAB,   KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     RS_ENT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   RA_LEFT,  RC_DOWN,  RG_UP,    LA_RGHT
  ), // }}}

#define RG_SCLN (MT(MOD_RGUI, KC_SCLN))
  [L_QT] = LAYOUT_planck_grid( // {{{ qwerty
    LG_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     LA(KC_O), KC_P,     RG_TAB,
    LC_BSPC,  LG(KC_A), LA(KC_S), LS(KC_D), LC(KC_F), KC_G,     KC_H,     RC(KC_J), RS(KC_K), RA(KC_L), RG_SCLN,  RC_DEL,
    LS_TAB,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RS_ENT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   RA_LEFT,  RC_DOWN,  RG_UP,    LA_RGHT
  ), // }}}

  [L_SHV] = LAYOUT_planck_grid( // {{{ shavian
    LG_ESC,   SHV_1_0,  SHV_1_1,  SHV_1_2,  SHV_1_3,  SHV_1_4,  SHV_1_5,  SHV_1_6,  SHV_1_7,  SHV_1_8,  SHV_1_9,  RG_TAB,
    LC_BSPC,  SHV_2_0,  SHV_2_1,  SHV_2_2,  SHV_2_3,  SHV_2_4,  SHV_2_5,  SHV_2_6,  SHV_2_7,  SHV_2_8,  SHV_2_9,  RC_DEL,
    LS_TAB,   SHV_3_0,  SHV_3_1,  SHV_3_2,  SHV_3_3,  SHV_3_4,  SHV_3_5,  SHV_3_6,  SHV_3_7,  SHV_3_8,  SHV_3_9,  RS_ENT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   RA_LEFT,  RC_DOWN,  RG_UP,    LA_RGHT
  ), // }}}

  [L_OH] = LAYOUT_planck_grid( // {{{ one-handed
    LG_ESC,   KC_L,     RA(KC_R), KC_C,     KC_G,     KC_F,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    LC_BSPC,  LG(KC_A), LA(KC_O), LS(KC_E), LC(KC_U), KC_I,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    LS_TAB,   KC_S,     KC_N,     KC_T,     KC_H,     KC_D,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  KA_OLWR,  KA_OSPC,  KA_OSPC,  KA_ORAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ), // }}}

#define RA_COMM (MT(MOD_RALT, KC_COMM))
  [L_OHA] = LAYOUT_planck_grid( // {{{ one-handed alt
    _______,  KC_QUOT,  RA_COMM,  KC_DOT,   KC_P,     KC_Y,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  LG(KC_Z), LA(KC_V), LS(KC_W), LC(KC_M), KC_B,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    MO_HUB,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ), // }}}

  [L_OHM] = LAYOUT_planck_grid( // {{{ one-handed modifiers
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  OSM_GUI,  OSM_ALT,  OSM_SFT,  OSM_CTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  OSM_RAL,  OSM_HYP,  OSM_MEH,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    MO_HUB,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ), // }}}

  [L_ST] = LAYOUT_planck_grid( // {{{ stenotype
    STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,   STN_N6,   STN_N7,   STN_N8,   STN_N9,   STN_NA,   STN_NB,   STN_NC,
    STN_FN,   STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,  STN_ST3,  STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
    STN_FN,   STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,  STN_ST4,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,
    MO_HUB,   STN_PWR,  STN_RE1,  STN_A,    STN_O,    MO_MS,    MO_MS,    STN_E,    STN_U,    STN_RE2,  STN_PWR,  MO_MS
  ), // }}}

  [L_STC] = LAYOUT_planck_grid( // {{{ stenotype comfort
    STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,   STN_N6,   STN_N7,   STN_N8,   STN_N9,   STN_NA,   STN_NB,   STN_NC,
    STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,  STN_FN,   STN_ST3,  STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR,
    STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,  STN_FN,   STN_ST4,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR,
    MO_HUB,   STN_PWR,  STN_RE1,  STN_A,    STN_O,    STN_E,    STN_E,    STN_U,    STN_RE2,  STN_RE2,  STN_PWR,  MO_MS
  ), // }}}

  [L_GA] = LAYOUT_planck_grid( // {{{ gaming
    KC_ESC,   KC_TAB,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  KC_GRV,   KC_PSLS,  KC_P1,    KC_P2,    KC_P3,    KC_PMNS,
    KC_LCTL,  KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  KC_BSLS,  KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
    KC_LSFT,  KC_DEL,   KC_ENT,   KC_MINS,  KC_EQL,   KC_SLSH,  KC_LBRC,  KC_RBRC,  KC_P7,    KC_P8,    KC_P9,    KC_PENT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  KA_GLWR,  G_SPC,    G_SPC,    KA_GRAI,  KC_P0,    XXXXXXX,  KC_PDOT,  XXXXXXX
  ), // }}}

  [L_GAN] = LAYOUT_planck_grid( // {{{ gaming alpha/numbers
    KC_LGUI,  KC_L,     KC_R,     KC_C,     KC_G,     KC_F,     XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,
    _______,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     XXXXXXX,  XXXXXXX,  KC_4,     KC_5,     KC_6,     XXXXXXX,
    _______,  KC_S,     KC_N,     KC_T,     KC_H,     KC_D,     XXXXXXX,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_0,
    MO_HUB,   _______,  _______,  _______,  KA_GLWR,  XXXXXXX,  XXXXXXX,  KA_GRAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ), // }}}

  [L_GAF] = LAYOUT_planck_grid( // {{{ gaming alpha/functions
    KC_LGUI,  KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,
    _______,  KC_Z,     KC_V,     KC_W,     KC_M,     KC_B,     XXXXXXX,  XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,
    _______,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     XXXXXXX,  XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,
    MO_HUB,   _______,  _______,  _______,  KA_GLWR,  XXXXXXX,  XXXXXXX,  KA_GRAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ), // }}}

  [L_GAX] = LAYOUT_planck_grid( // {{{ gaming extras
    KC_LGUI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  G_S_CY,   XXXXXXX,  KC_NUM,   XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    MO_HUB,   _______,  _______,  _______,  KA_GLWR,  XXXXXXX,  XXXXXXX,  KA_GRAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ), // }}}

#define LG_GRV  (MT(MOD_LGUI, KC_GRV))
#define LA_MINS (MT(MOD_LALT, KC_MINS))
#define LS_EQL  (MT(MOD_LSFT, KC_EQL))
#define LC_SLSH (MT(MOD_LCTL, KC_SLSH))
  [L_XSN] = LAYOUT_planck_grid( // {{{ symbols/numbers
    _______,  KC_QUOT,  KC_COMM,  KC_DOT,   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,  _______,
    _______,  LG_GRV,   LA_MINS,  LS_EQL,   LC_SLSH,  XXXXXXX,  XXXXXXX,  RC(KC_4), RS(KC_5), RA(KC_6), KC_RGUI,  _______,
    _______,  KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_RALT,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_0,     _______,
    MO_HUB,   _______,  _______,  _______,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   _______,  _______,  _______,  _______
  ), // }}}

// LG_ESC is coincidentally already defined
#define LA_LEFT (MT(MOD_LALT, KC_LEFT))
#define LS_DOWN (MT(MOD_LSFT, KC_DOWN))
#define LC_RGHT (MT(MOD_LCTL, KC_RGHT))
#define RC_F5   (MT(MOD_RCTL, KC_F5))
#define RS_F6   (MT(MOD_RSFT, KC_F6))
#define RA_F7   (MT(MOD_RALT, KC_F7))
#define RG_F8   (MT(MOD_RALT, KC_F8))
  [L_XNF] = LAYOUT_planck_grid( // {{{ navigation/functions
    _______,  KC_TAB,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,
    _______,  LG_ESC,   LA_LEFT,  LS_DOWN,  LC_RGHT,  KC_PGDN,  XXXXXXX,  RC_F5,    RS_F6,    RA_F7,    RG_F8,    _______,
    _______,  KC_ENT,   KC_BSPC,  XXXXXXX,  KC_DEL,   KC_APP,   XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
    MO_HUB,   _______,  _______,  _______,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   _______,  _______,  _______,  _______
  ), // }}}

  [L_XMM] = LAYOUT_planck_grid( // {{{ misc/mouse
    _______,  XXXXXXX,  XXXXXXX,  KC_BRK,   KC_PSCR,  KC_SYRQ,  KC_BTN3,  KC_BTN4,  KC_MS_U,  KC_BTN5,  KC_WH_U,  _______,
    _______,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  KC_INS,   KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,
    _______,  XXXXXXX,  KC_SCRL,  KC_NUM,   KC_CAPS,  KC_PAUS,  KC_BTN2,  KC_WH_L,  XXXXXXX,  KC_WH_R,  KC_ACL2,  _______,
    MO_HUB,   _______,  _______,  _______,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   _______,  _______,  _______,  _______
  ), // }}}

#define RC_F17  (MT(MOD_RCTL, KC_F17))
#define RS_F18  (MT(MOD_RSFT, KC_F18))
#define RA_F19  (MT(MOD_RALT, KC_F19))
#define RG_F20  (MT(MOD_RALT, KC_F20))
  [L_XMF] = LAYOUT_planck_grid( // {{{ media/functions 2
    _______,  KC_MSTP,  KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_VOLU,  XXXXXXX,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   _______,
    _______,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  KC_VOLD,  XXXXXXX,  RC_F17,   RS_F18,   RA_F19,   RG_F20,   _______,
    _______,  KC_MSEL,  KC_MRWD,  KC_MFFD,  XXXXXXX,  KC_MUTE,  XXXXXXX,  KC_F21,   KC_F22,   KC_F23,   KC_F24,   _______,
    MO_HUB,   _______,  _______,  _______,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   _______,  _______,  _______,  _______
  ), // }}}

  [L_NP] = LAYOUT_planck_grid( // {{{ number pad
    _______,  XXXXXXX,  KC_1,     KC_2,     KC_3,     XXXXXXX,  KC_PSLS,  KC_P1,    KC_P2,    KC_P3,    KC_PMNS,  _______,
    _______,  XXXXXXX,  KC_4,     KC_5,     KC_6,     XXXXXXX,  KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  _______,
    _______,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    KC_PENT,  _______,
    MO_HUB,   _______,  _______,  _______,  KA_LWR,   KA_SPC,   KA_SPC,   KA_RAI,   _______,  _______,  _______,  _______
  ), // }}}

  [L_MS] = LAYOUT_planck_grid( // {{{ mouse
    LG_ESC,   KC_ACL0,  KC_BTN4,  KC_MS_U,  KC_BTN5,  KC_WH_U,  XXXXXXX,  XXXXXXX,  KC_WH_U,  XXXXXXX,  KC_BTN6,  RG_TAB,
    LC_BSPC,  KC_ACL1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  XXXXXXX,  KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_BTN7,  RC_DEL,
    LS_TAB,   KC_ACL2,  KC_WH_L,  XXXXXXX,  KC_WH_R,  XXXXXXX,  XXXXXXX,  KC_ACL2,  KC_ACL1,  KC_ACL0,  KC_BTN8,  RS_ENT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  KC_BTN2,  KC_BTN1,  KC_BTN1,  KC_BTN3,  RA_LEFT,  RC_DOWN,  RG_UP,    LA_RGHT
  ), // }}}

  [L_FN] = LAYOUT_planck_grid( // {{{ functions
    LG_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RG_TAB,
    LC_BSPC,  RC_F5,    RS_F6,    RA_F7,    RG_F8,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RC_DEL,
    LS_TAB,   KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RS_ENT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  KC_BTN2,  KC_BTN1,  KC_BTN1,  KC_BTN3,  RA_LEFT,  RC_DOWN,  RG_UP,    LA_RGHT
  ), // }}}

  [L_HUB] = LAYOUT_planck_grid( // {{{ hub
    KC_LGUI,  XXXXXXX,  DF_NP,    DF_SHV,   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BRIU,  KC_BRID,  XXXXXXX,  LED_CYC,  KC_RGUI,
    KC_LCTL,  XXXXXXX,  DF_OH,    DF_DV,    DF_ST,    DF_GA,    XXXXXXX,  RGB_TLC,  RGB_TOG,  RGB_SAI,  RGB_HUI,  KC_RCTL,
    KC_LSFT,  XXXXXXX,  DF_MS,    DF_QT,    DF_STC,   XXXXXXX,  XXXXXXX,  RGB_SLD,  RGB_MOD,  RGB_SPI,  RGB_VAI,  KC_RSFT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  XXXXXXX,  MO_SYS,   MO_SYS,   XXXXXXX,  KC_RALT,  KC_RCTL,  KC_RGUI,  XXXXXXX
  ), // }}}

  [L_SYS] = LAYOUT_planck_grid( // {{{ system
    KC_LGUI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PWR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,  XXXXXXX,  KC_LGUI,
    KC_LCTL,  AU_TOGG,  XXXXXXX,  XXXXXXX,  KC_SLEP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  NK_TOGG,  XXXXXXX,  KC_LCTL,
    KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_WAKE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RSFT,
    MO_HUB,   KC_LGUI,  KC_LCTL,  KC_LALT,  XXXXXXX,  MO_SYS,   MO_SYS,   XXXXXXX,  KC_RALT,  KC_RCTL,  KC_RGUI,  XXXXXXX
  ), // }}}
};
// clang-format on

typedef enum color_t { // {{{
  C_NONE,
  C_____ = C_NONE,
  C__ = C_NONE,

  // sunset (orange, red, purple, violet, blue)
  C_SU_1, C_SU_2, C_SU_3, C_SU_4, C_SU_5,

  // tomorrow (l. lime, l. orange, l. blue, l. red, l. purple)
  C_TO_1, C_TO_2, C_TO_3, C_TO_4, C_TO_5,

  // rubik's cube (green, red, yellow, blue, orange)
  C_RU_1, C_RU_2, C_RU_3, C_RU_4, C_RU_5,

  // desert sun (orange, yellow, l. yellow, white, blue)
  C_DS_1, C_DS_2, C_DS_3, C_DS_4, C_DS_5,

  // cosmic chocolate (brown, d. red, red, white, yellow)
  C_CC_1, C_CC_2, C_CC_3, C_CC_4, C_CC_5,

  // material (yellow, orange, d. pink, green, blue)
  C_MA_1, C_MA_2, C_MA_3, C_MA_4, C_MA_5,

  // solarized (yellow, orange, red, blue, l. blue)
  C_SO_1, C_SO_2, C_SO_3, C_SO_4, C_SO_5,

  // raspberry (red, l. red, l. yellow, l. brown, brown)
  C_RA_1, C_RA_2, C_RA_3, C_RA_4, C_RA_5,

  C_MAX,
} color_t; // }}}

const uint8_t PROGMEM color_map[C_MAX][3] = { // {{{
    [C_NONE] = {0, 0, 0},

    // sunset
    [C_SU_1] = {14, 222, 242},
    [C_SU_2] = {255, 220, 201},
    [C_SU_3] = {233, 218, 217},
    [C_SU_4] = {205, 255, 255},
    [C_SU_5] = {180, 255, 233},

    // tomorrow
    [C_TO_1] = {50, 153, 244},
    [C_TO_2] = {20, 177, 225},
    [C_TO_3] = {154, 86, 255},
    [C_TO_4] = {252, 119, 255},
    [C_TO_5] = {195, 61, 255},

    // rubik's cube
    [C_RU_1] = {105, 255, 255},
    [C_RU_2] = {249, 228, 255},
    [C_RU_3] = {35, 255, 255},
    [C_RU_4] = {154, 255, 255},
    [C_RU_5] = {14, 255, 255},

    // desert sun
    [C_DS_1] = {14, 255, 255},
    [C_DS_2] = {33, 255, 255},
    [C_DS_3] = {30, 96, 255},
    [C_DS_4] = {0, 0, 255},
    [C_DS_5] = {141, 255, 233},

    // cosmic chocolate
    [C_CC_1] = {15, 166, 195},
    [C_CC_2] = {0, 205, 155},
    [C_CC_3] = {0, 183, 238},
    [C_CC_4] = {0, 0, 255},
    [C_CC_5] = {31, 255, 255},

    // material
    [C_MA_1] = {32, 176, 255},
    [C_MA_2] = {10, 225, 255},
    [C_MA_3] = {243, 222, 234},
    [C_MA_4] = {85, 203, 158},
    [C_MA_5] = {134, 255, 213},

    // solarized
    [C_SO_1] = {32, 255, 234},
    [C_SO_2] = {12, 225, 241},
    [C_SO_3] = {1, 204, 255},
    [C_SO_4] = {168, 120, 255},
    [C_SO_5] = {145, 224, 255},

    // raspberry
    [C_RA_1] = {252, 199, 190},
    [C_RA_2] = {248, 159, 255},
    [C_RA_3] = {28, 126, 255},
    [C_RA_4] = {16, 97, 236},
    [C_RA_5] = {16, 177, 169},
}; // }}}

// clang-format off
const color_t PROGMEM ledmap[L_MAX][RGB_MATRIX_LED_COUNT] = {
  [L_DV] = { // {{{ dvorak
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_1, C_SU_2, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_QT] = { // {{{ querty
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_1, C_DS_2, C_DS_4,
    C_DS_4, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_2, C_DS_2, C_DS_1, C_DS_1, C_DS_1, C_DS_1, C_DS_4,
    C_DS_4, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_2, C_DS_4,
    C_DS_5, C_DS_4, C_DS_4, C_DS_4, C_DS_5,     C_DS_5,     C_DS_5, C_DS_4, C_DS_4, C_DS_4, C_DS_4
  }, // }}}

  [L_SHV] = { // {{{ shavian
    C_RA_4, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_4,
    C_RA_4, C_RA_1, C_RA_1, C_RA_1, C_RA_1, C_RA_2, C_RA_2, C_RA_1, C_RA_1, C_RA_1, C_RA_1, C_RA_4,
    C_RA_4, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_2, C_RA_4,
    C_RA_5, C_RA_4, C_RA_4, C_RA_4, C_RA_5,     C_RA_5,     C_RA_5, C_RA_4, C_RA_4, C_RA_4, C_RA_4
  }, // }}}

  [L_OH] = { // {{{ one-handed
    C_SU_4, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_____, C_____, C_____, C_____
  }, // }}}

  [L_OHA] = { // {{{ one-handed alts
    C_SU_4, C_SU_3, C_SU_1, C_SU_3, C_SU_2, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_3, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_____, C_____, C_____, C_____
  }, // }}}

  [L_OHM] = { // {{{ one-handed modifiers
    C_SU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_4, C_____, C_SU_1, C_SU_2, C_SU_2, C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_____, C_____, C_____, C_____
  }, // }}}

  [L_ST] = { // {{{ stenotype
    C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_4, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_5, C_MA_4, C_MA_3, C_MA_1, C_MA_1,     C_MA_5,     C_MA_1, C_MA_1, C_MA_3, C_MA_4, C_MA_5
  }, // }}}

  [L_STC] = { // {{{ stenotype comfort
    C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3, C_MA_3,
    C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_4, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_2, C_MA_4, C_MA_2, C_MA_1, C_MA_1, C_MA_1, C_MA_1, C_MA_1,
    C_MA_5, C_MA_4, C_MA_3, C_MA_1, C_MA_1,     C_MA_1,     C_MA_1, C_MA_3, C_MA_3, C_MA_4, C_MA_5
  }, // }}}

  [L_GA] = { // {{{ gaming
    C_RU_2, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_RU_2, C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2,
    C_RU_4, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_RU_3, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2,
    C_RU_4, C_RU_2, C_RU_2, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_3, C_RU_1, C_RU_1, C_RU_1, C_RU_3,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_1, C_____, C_RU_1, C_____
  }, // }}}

  [L_GAN] = { // {{{ gaming alpha/numbers
    C_RU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_RU_2, C_RU_2, C_RU_2, C_____,
    C_RU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____, C_____, C_RU_2, C_RU_2, C_RU_2, C_____,
    C_RU_4, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_RU_2, C_RU_2, C_RU_2, C_RU_2,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4
  }, // }}}

  [L_GAF] = { // {{{ gaming alpha/functions
    C_RU_2, C_SU_3, C_SU_3, C_SU_3, C_SU_2, C_SU_2, C_____, C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____, C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_4, C_SU_3, C_SU_2, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_RU_3, C_RU_3, C_RU_3, C_RU_3,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4
  }, // }}}

  [L_GAX] = { // {{{ gaming extras
    C_RU_2, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_RU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_RU_1, C_____, C_RU_1, C_____, C_____,
    C_RU_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____,
    C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_5,     C_RU_2,     C_RU_5, C_RU_4, C_RU_4, C_RU_4, C_RU_4
  }, // }}}

  [L_XSN] = { // {{{ symbols/numbers
    C_SU_4, C_SU_2, C_SU_2, C_SU_2, C_____, C_____, C_____, C_SU_3, C_SU_3, C_SU_3, C_____, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_SU_3, C_SU_3, C_SU_3, C_SU_4, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_4, C_____, C_SU_3, C_SU_3, C_SU_3, C_SU_3, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_XNF] = { // {{{ navigation/functions
    C_SU_4, C_SU_2, C_SU_2, C_SU_1, C_SU_2, C_SU_2, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_2, C_SU_1, C_SU_1, C_SU_1, C_SU_2, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_2, C_SU_2, C_____, C_SU_2, C_SU_1, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_XMM] = { // {{{ misc/mouse
    C_SU_4, C_____, C_____, C_SU_1, C_SU_1, C_SU_1, C_TO_2, C_TO_2, C_TO_1, C_TO_2, C_TO_3, C_SU_4,
    C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_1, C_TO_2, C_TO_1, C_TO_1, C_TO_1, C_TO_3, C_SU_4,
    C_SU_4, C_____, C_SU_2, C_SU_2, C_SU_2, C_SU_1, C_TO_2, C_TO_3, C_____, C_TO_3, C_TO_4, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_XMF] = { // {{{ media/functions
    C_SU_4, C_RU_3, C_RU_2, C_RU_2, C_RU_1, C_RU_2, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_SU_4, C_RU_2, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_4, C_RU_1, C_RU_3, C_RU_3, C_____, C_RU_1, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_NP] = { // {{{ number pad
    C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_SU_4,
    C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_2, C_RU_1, C_RU_1, C_RU_1, C_RU_2, C_SU_4,
    C_SU_4, C_____, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_RU_1, C_RU_1, C_RU_1, C_RU_3, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_5,     C_SU_5,     C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_MS] = { // {{{ mouse
    C_TO_4, C_TO_4, C_TO_2, C_TO_3, C_TO_2, C_TO_1, C_____, C_____, C_TO_1, C_____, C_TO_2, C_TO_4,
    C_TO_4, C_TO_4, C_TO_3, C_TO_3, C_TO_3, C_TO_1, C_____, C_TO_1, C_TO_1, C_TO_1, C_TO_2, C_TO_4,
    C_TO_4, C_TO_4, C_TO_1, C_____, C_TO_1, C_____, C_____, C_TO_4, C_TO_4, C_TO_4, C_TO_2, C_TO_4,
    C_TO_5, C_TO_4, C_TO_4, C_TO_4, C_TO_2,     C_TO_2,     C_TO_2, C_TO_4, C_TO_4, C_TO_4, C_TO_4
  }, // }}}

  [L_FN] = { // {{{ functions
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_4, C_SU_1, C_SU_1, C_SU_1, C_SU_1, C_____, C_____, C_____, C_____, C_____, C_____, C_SU_4,
    C_SU_5, C_SU_4, C_SU_4, C_SU_4, C_____,     C_____,     C_____, C_SU_4, C_SU_4, C_SU_4, C_SU_4
  }, // }}}

  [L_HUB] = { // {{{ hub
    C_SO_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SO_4,
    C_SO_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SO_4,
    C_SO_4, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_____, C_SO_4,
    C_SO_5, C_SO_4, C_SO_4, C_SO_4, C_____,     C_SO_5,     C_____, C_SO_4, C_SO_4, C_SO_4, C_____
  }, // }}}

  [L_SYS] = { // {{{ system
    C_SO_4, C_____, C_____, C_____, C_SO_2, C_____, C_____, C_____, C_____, C_SO_1, C_____, C_SO_4,
    C_SO_4, C_SO_2, C_____, C_____, C_SO_2, C_____, C_____, C_____, C_____, C_SO_2, C_____, C_SO_4,
    C_SO_4, C_____, C_____, C_____, C_SO_2, C_____, C_____, C_____, C_____, C_____, C_____, C_SO_4,
    C_SO_5, C_SO_4, C_SO_4, C_SO_4, C_____,     C_SO_5,     C_____, C_SO_4, C_SO_4, C_SO_4, C_____
  }, // }}}
};
// clang-format on

void set_led_color(int led, color_t col) { // {{{
  HSV hsv = {
      .h = pgm_read_byte(&color_map[col][0]),
      .s = pgm_read_byte(&color_map[col][1]),
      .v = pgm_read_byte(&color_map[col][2]),
  };
  if (!hsv.h && !hsv.s && !hsv.v) {
    rgb_matrix_set_color(led, 0, 0, 0);
  } else {
    RGB rgb = hsv_to_rgb(hsv);
    float f = (float)rgb_matrix_get_val() / UINT8_MAX;
    rgb_matrix_set_color(led, f * rgb.r, f * rgb.g, f * rgb.b);
  }
} // }}}

bool rgb_matrix_indicators_user(void) { // {{{
  if (rgb_matrix_get_suspend_state() || keyboard_config.disable_layer_led)
    return false;

  layer_state_t layers = layer_state | default_layer_state;
  uint8_t layer = get_highest_layer(layers);
  const color_t *colors = ledmap[layer];

  for (uint8_t i = 0; i <= RGB_MATRIX_LED_COUNT; i++)
    set_led_color(i, colors[i]);

  return false;
} // }}}

layer_state_t layer_state_set_user(layer_state_t state) { // {{{
  state = update_tri_layer_state(state, L_XSN, L_XNF, L_XMF);
  state = update_tri_layer_state(state, L_GAN, L_GAF, L_GAX);

  if (IS_LAYER_ON_STATE(state, L_XSN))
    planck_ez_left_led_on();
  else
    planck_ez_left_led_off();
  if (IS_LAYER_ON_STATE(state, L_XNF))
    planck_ez_right_led_on();
  else
    planck_ez_right_led_off();

  return state;
} // }}}

static uint16_t g_spc_kc = KC_SPC;
static uint16_t g_spc_last = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // {{{
  switch (keycode) {

  case LED_CYC:
    if (record->event.pressed) {
      keyboard_config.led_level = (keyboard_config.led_level + 1) % 4;
      planck_ez_right_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
      planck_ez_left_led_level((uint8_t)keyboard_config.led_level * 255 / 4);
      layer_state_set_kb(layer_state);
    }
    return false;

  case RGB_SLD:
    if (record->event.pressed) {
      rgblight_mode(1);
    }
    return false;

  case G_SPC:
    if (record->event.pressed) {
      g_spc_last = g_spc_kc;
      register_code(g_spc_last);
    } else {
      if (g_spc_last != 0) {
        unregister_code(g_spc_last);
        g_spc_last = 0;
      }
    }
    return false;

  case G_S_CY:
    if (record->event.pressed) {
      if (g_spc_last != 0) {
        unregister_code(g_spc_last);
        g_spc_last = 0;
      }
      switch (g_spc_kc) {
      case KC_SPC:
        g_spc_kc = KC_UP;
        break;
      case KC_UP:
        g_spc_kc = KC_SPC;
        break;
      default:
        g_spc_kc = KC_SPC;
        break;
      }
    }
    return false;
  }

  return true;
} // }}}

layer_state_t default_layer_state_set_user(layer_state_t state) { // {{{
  layer_clear();

  return state;
} // }}}

void keyboard_post_init_user(void) { // {{{
  rgb_matrix_enable();
  steno_set_mode(STENO_MODE_GEMINI);
  default_layer_set(1 << L_DV);
  layer_clear();
} // }}}

/* vim: set foldmethod=marker shiftwidth=2 : */
