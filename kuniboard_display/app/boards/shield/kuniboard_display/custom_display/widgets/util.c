/*
 *
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 *
 */

#include <zephyr/kernel.h>
#include "util.h"

// static lv_color_t cbuf_tmp[CANVAS_SIZE * CANVAS_SIZE];

void rotate_canvas(lv_obj_t *canvas, lv_color_t cbuf[], lv_color_t cbuf_rot[], uint8_t width,
                   uint8_t height) {

#if CONFIG_KUNIBOARD_CUSTOM_DISPLAY_ROTATE_CLOCKWISE
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cbuf_rot[i * height + (height - 1 - j)] = cbuf[i + j * width];
        }
    }
#else
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cbuf_rot[(width - i - 1) * height + j] = cbuf[i + j * width];
        }
    }
#endif

    lv_canvas_set_buffer(canvas, cbuf_rot, height, width, LV_IMG_CF_TRUE_COLOR);
}

void init_label_dsc(lv_draw_label_dsc_t *label_dsc, lv_color_t color, const lv_font_t *font,
                    lv_text_align_t align) {
    lv_draw_label_dsc_init(label_dsc);
    label_dsc->color = color;
    label_dsc->font = font;
    label_dsc->align = align;
}

void init_rect_dsc(lv_draw_rect_dsc_t *rect_dsc, lv_color_t bg_color) {
    lv_draw_rect_dsc_init(rect_dsc);
    rect_dsc->bg_color = bg_color;
}