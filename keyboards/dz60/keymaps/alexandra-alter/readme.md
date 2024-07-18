# Layers

Keys prefixed with 'l' enable other layers when held.
Keys prefixed with 'm' enable modifiers when held.
A value known as the tapping term determines how long it takes before the keyboard registers a hold.

Both can be forced to hold their on-tap-output by performing a rapid tap-hold.

A feature called permissive hold ensures that, even if it is within the tapping term, holding one key and tapping a second key before releasing the first will register as one hold, one tap.
This helps reduce the amount of time you need to linger on a key before the hold becomes active.

```
Typing
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
│ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
│ Tab │ Q │mW │ E │ R │ T │ Y │ U │ I │mO │ P │ [ │ ] │  \  │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
│lCaps │mA │mS │mD │mF │ G │ H │mJ │mK │mL │m; │ ' │ lEnter │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
│Ctrl│GUI │Alt │          lSpc          │ Alt│ GUI│Menu│Ctrl│
└────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
```

```
Navigation
Symbols (access by holding Space)
(Hom, Esc, Lft, Dwn, Rgt are also modifiers)
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
│Esc│ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│  Del  │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
│ Tab │   │Hom│Up │End│PgU│   │   │Ins│Alt│Psc│Pau│Brk│  \  │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
│lCaps │Esc│Lft│Dwn│Rgt│PgD│   │Ctl│Sft│Alt│GUI│   │ lEnter │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
│ Shift  │Ent│Bsp│   │Del│App│   │   │   │   │   │    Shift │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
│Ctrl│GUI │Alt │          lSpc          │ Alt│ GUI│Menu│Ctrl│
└────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
```

```
Symbols (access by holding Caps/Enter)
(MPr, =, -, `, ;, ] are also modifiers)
M__ represents Media
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
│Esc│ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│  Del  │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
│ Tab │MSt│MPr│MNx│MPl│MVu│   │ \ │ [ │ ] │ ' │ [ │ ] │  \  │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
│lCaps │GUI│Alt│Sft│Ctl│MVd│   │ = │ - │ ` │ ; │ ' │ lEnter │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
│ Shift  │MSl│MRw│MFf│   │MMt│   │   │ , │ . │ / │    Shift │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
│Ctrl│GUI │Alt │          lSpc          │ Alt│ GUI│Menu│Ctrl│
└────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
```

```
Extras (access by holding Space and Caps/Enter)
R__ represents RGB
B__ represents Backlight
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
│Esc│ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│  Del  │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
│ Tab │RMd│RHI│RSI│RVI│BSt│Syr│   │Ins│   │Psc│Pau│Brk│  \  │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
│lCaps │RTg│RHD│RSD│RVD│BTg│   │   │Cap│Scl│   │   │ lEnter │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
│ Shift  │   │   │   │   │RBT│Num│   │   │   │   │    Shift │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
│Ctrl│GUI │Alt │          lSpc          │ Alt│ GUI│Menu│Ctrl│
└────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
```
