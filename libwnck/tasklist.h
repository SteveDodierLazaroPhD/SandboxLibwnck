/* tasklist object */

/*
 * Copyright (C) 2001 Havoc Pennington
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef WNCK_TASKLIST_H
#define WNCK_TASKLIST_H

#include <gtk/gtk.h>
#include <libwnck/screen.h>

G_BEGIN_DECLS

#define WNCK_TYPE_TASKLIST              (wnck_tasklist_get_type ())
#define WNCK_TASKLIST(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), WNCK_TYPE_TASKLIST, WnckTasklist))
#define WNCK_TASKLIST_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), WNCK_TYPE_TASKLIST, WnckTasklistClass))
#define WNCK_IS_TASKLIST(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), WNCK_TYPE_TASKLIST))
#define WNCK_IS_TASKLIST_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), WNCK_TYPE_TASKLIST))
#define WNCK_TASKLIST_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), WNCK_TYPE_TASKLIST, WnckTasklistClass))

typedef struct _WnckTasklist        WnckTasklist;
typedef struct _WnckTasklistClass   WnckTasklistClass;
typedef struct _WnckTasklistPrivate WnckTasklistPrivate;

typedef enum {
  WNCK_TASKLIST_ALL,
  WNCK_TASKLIST_WORKSPACE,
  WNCK_TASKLIST_ALL_MINIMIZED,
  WNCK_TASKLIST_WORKSPACE_MINIMIZED
} WnckTasklistMode;

struct _WnckTasklist
{
  GtkContainer parent_instance;

  WnckTasklistPrivate *priv;
};

struct _WnckTasklistClass
{
  GtkContainerClass parent_class;
};

GType wnck_tasklist_get_type (void) G_GNUC_CONST;

GtkWidget *wnck_tasklist_new (WnckScreen *screen);

void wnck_tasklist_set_mode (WnckTasklist *tasklist,
			     WnckTasklistMode mode);

G_END_DECLS

#endif /* WNCK_TASKLIST_H */

