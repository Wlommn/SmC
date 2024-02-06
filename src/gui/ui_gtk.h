#ifndef SRC_GUI_UI_GTK_H_
#define SRC_GUI_UI_GTK_H_

#include <gtk/gtk.h>
#include <stdio.h>
#include <locale.h>
#include <kplot.h>

#include "../common_def.h"

#define BUTTON_WIDTH 60
#define BUTTON_HEIGHT 45

typedef struct UI_LAYOUT {
  GtkWidget *grid_nums;
  GtkWidget *box_left;
  GtkWidget *box_center;
  GtkWidget *frame_right;
  GtkWidget *canvas_tgl_list;
  GtkWidget *canvas_stack;
  GtkWidget *scale_entry;
  GtkWidget *b_7;
  GtkWidget *b_4;
  GtkWidget *b_1;
  GtkWidget *b_0;
  GtkWidget *b_eql;
  GtkWidget *b_8;
  GtkWidget *b_5;
  GtkWidget *b_2;
  GtkWidget *b_dot;
  GtkWidget *b_clear;
  GtkWidget *b_clear_all;
  GtkWidget *b_9;
  GtkWidget *b_6;
  GtkWidget *b_3;
  GtkWidget *b_div;
  GtkWidget *b_mul;
  GtkWidget *b_min;
  GtkWidget *b_plus;
  GtkWidget *b_p;
  GtkWidget *b_sin;
  GtkWidget *b_cos;
  GtkWidget *b_tan;
  GtkWidget *b_asin;
  GtkWidget *b_acos;
  GtkWidget *b_atan;
  GtkWidget *b_sqrt;
  GtkWidget *b_scale;
  GtkWidget *b_ln;
  GtkWidget *b_log;
  GtkWidget *b_x;
} ui_layout;

void get_input(char *input_str);
ui_layout Init_UI_layout();

extern void activate(GtkApplication *app);
void marking();
void show_all();

void add_signals();
void callback_nums(GtkWidget *widget);
void callback_op(GtkWidget *widget);
void callback_p();
void callback_clear();
void callback_clear_all();
void callback_sin();
void callback_cos();
void callback_tan();
void callback_asin();
void callback_acos();
void callback_atan();
void callback_sqrt();
void callback_scale();
void callback_log();
void callback_ln();
void tgl_canvas(GtkListBox *, GtkListBoxRow *row);
void draw_axis(cairo_t* cr, guint width, guint height);
void callback_draw(GtkDrawingArea *widget, cairo_t *cr, int, int, void *);
void output();

#endif  //  SRC_GUI_UI_GTK_H_
