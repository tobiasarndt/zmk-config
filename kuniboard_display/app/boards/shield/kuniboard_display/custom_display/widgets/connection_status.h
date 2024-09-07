/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct zmk_widget_connection_status {
    sys_snode_t node;
    lv_obj_t *obj;
    lv_obj_t *art;
    lv_obj_t *not_connected;
};

int zmk_widget_connection_status_init(struct zmk_widget_connection_status *widget,
                                      lv_obj_t *parent);
lv_obj_t *zmk_widget_connection_status_obj(struct zmk_widget_connection_status *widget);