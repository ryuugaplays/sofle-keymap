MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

CONSOLE_ENABLE = no
RGBLIGHT_ENABLE = no
ENCODER_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
COMMAND_ENABLE = no
MUSIC_ENABLE = no

ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += combos.c
endif