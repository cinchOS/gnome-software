/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2017 Canonical Ltd.
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GS_PERMISSION_SWITCH_H
#define GS_PERMISSION_SWITCH_H

#include <gtk/gtk.h>

#include "gnome-software-private.h"

G_BEGIN_DECLS

#define GS_TYPE_PERMISSION_SWITCH (gs_permission_switch_get_type ())

G_DECLARE_FINAL_TYPE (GsPermissionSwitch, gs_permission_switch, GS, PERMISSION_SWITCH, GtkSwitch)

GsPermissionSwitch *gs_permission_switch_new (GsPermission *permission);

GsPermission *gs_permission_switch_get_permission (GsPermissionSwitch *sw);

G_END_DECLS

#endif /* GS_PERMISSION_SWITCH_H */
