/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

#define LAYER_CANVAS_HEIGHT 20
#define LAYER_CANVAS_WIDTH 68

struct zmk_widget_layer_status
{
    sys_snode_t node;
    lv_obj_t *canvas;
    lv_color_t cbuf[LAYER_CANVAS_WIDTH * LAYER_CANVAS_HEIGHT];
    lv_color_t cbuf_rot[LAYER_CANVAS_WIDTH * LAYER_CANVAS_HEIGHT];
    lv_draw_label_dsc_t layer_label_dsc;
};

int zmk_widget_layer_status_init(struct zmk_widget_layer_status *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_layer_status_obj(struct zmk_widget_layer_status *widget);