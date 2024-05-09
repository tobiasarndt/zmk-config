/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

#define OUTPUT_CANVAS_HEIGHT 20
#define OUTPUT_CANVAS_WIDTH 68

struct zmk_widget_output_status
{
    sys_snode_t node;
    lv_obj_t *canvas;
    lv_color_t cbuf[OUTPUT_CANVAS_WIDTH * OUTPUT_CANVAS_HEIGHT];
    lv_color_t cbuf_rot[OUTPUT_CANVAS_WIDTH * OUTPUT_CANVAS_HEIGHT];
    lv_draw_label_dsc_t output_label_dsc;
};

int zmk_widget_output_status_init(struct zmk_widget_output_status *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_output_status_obj(struct zmk_widget_output_status *widget);