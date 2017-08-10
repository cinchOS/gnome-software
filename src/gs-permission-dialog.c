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

#include "config.h"

#include "gs-permission-dialog.h"

struct _GsPermissionDialog
{
	GtkDialog	 parent_instance;

	GsApp		*app;
};

G_DEFINE_TYPE (GsPermissionDialog, gs_permission_dialog, GTK_TYPE_DIALOG)

static void
gs_permission_dialog_init (GsPermissionDialog *dialog)
{
	gtk_widget_init_template (GTK_WIDGET (dialog));
}

static void
gs_permission_dialog_dispose (GObject *object)
{
	GsPermissionDialog *dialog = GS_PERMISSION_DIALOG (object);

	g_clear_object (&dialog->app);

	G_OBJECT_CLASS (gs_permission_dialog_parent_class)->dispose (object);
}

static void
gs_permission_dialog_class_init (GsPermissionDialogClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	object_class->dispose = gs_permission_dialog_dispose;

	gtk_widget_class_set_template_from_resource (widget_class, "/org/gnome/Software/gs-permission-dialog.ui");
}

GtkWidget *
gs_permission_dialog_new (GsApp *app)
{
	GsPermissionDialog *dialog;

	dialog = g_object_new (GS_TYPE_PERMISSION_DIALOG,
			       "use-header-bar", TRUE,
			       NULL);
	dialog->app = g_object_ref (app);

	return GTK_WIDGET (dialog);
}
