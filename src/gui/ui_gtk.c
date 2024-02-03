#include "./ui_gtk.h"

ui_layout layout;
GtkWidget *entry;
GtkWidget *graph_area;
GtkBuilder *builder;

void get_input(char *input_str) {
    if (input_str) {
	    strcpy(input_str, gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(entry))));
    }
}

ui_layout Init_UI_layout() {
    ui_layout result;
	result.grid_nums = NULL;
    result.box_left = GTK_WIDGET(gtk_builder_get_object(builder, "box_left"));
    result.box_center = GTK_WIDGET(gtk_builder_get_object(builder, "box_center"));
	result.frame_right = GTK_WIDGET(gtk_builder_get_object(builder, "frame_right"));
    result.b_7 = GTK_WIDGET(gtk_builder_get_object(builder, "b_7"));
    result.b_4 = GTK_WIDGET(gtk_builder_get_object(builder, "b_4"));
    result.b_1 = GTK_WIDGET(gtk_builder_get_object(builder, "b_1"));
    result.b_0 = GTK_WIDGET(gtk_builder_get_object(builder, "b_0"));
    result.b_eql = GTK_WIDGET(gtk_builder_get_object(builder, "b_eql"));
    result.b_8 = GTK_WIDGET(gtk_builder_get_object(builder, "b_8"));
    result.b_5 = GTK_WIDGET(gtk_builder_get_object(builder, "b_5"));
    result.b_2 = GTK_WIDGET(gtk_builder_get_object(builder, "b_2"));
    result.b_dot = GTK_WIDGET(gtk_builder_get_object(builder, "b_dot"));
	result.b_clear = GTK_WIDGET(gtk_builder_get_object(builder, "b_clear"));
	result.b_clear_all = GTK_WIDGET(gtk_builder_get_object(builder, "b_clear_all"));
    result.b_9 = GTK_WIDGET(gtk_builder_get_object(builder, "b_9"));
    result.b_6 = GTK_WIDGET(gtk_builder_get_object(builder, "b_6"));
    result.b_3 = GTK_WIDGET(gtk_builder_get_object(builder, "b_3"));
    result.b_div = GTK_WIDGET(gtk_builder_get_object(builder, "b_div"));
    result.b_mul =  GTK_WIDGET(gtk_builder_get_object(builder, "b_mul"));
    result.b_min = GTK_WIDGET(gtk_builder_get_object(builder, "b_min"));
    result.b_plus = GTK_WIDGET(gtk_builder_get_object(builder, "b_plus"));
    result.b_p = GTK_WIDGET(gtk_builder_get_object(builder, "b_P"));
    result.b_sin = GTK_WIDGET(gtk_builder_get_object(builder, "b_sin"));
    result.b_cos = GTK_WIDGET(gtk_builder_get_object(builder, "b_cos"));
    result.b_tan = GTK_WIDGET(gtk_builder_get_object(builder, "b_tan"));
    result.b_asin = GTK_WIDGET(gtk_builder_get_object(builder, "b_asin"));
    result.b_acos = GTK_WIDGET(gtk_builder_get_object(builder, "b_acos"));
    result.b_atan = GTK_WIDGET(gtk_builder_get_object(builder, "b_atan"));
    result.b_scale = GTK_WIDGET(gtk_builder_get_object(builder, "b_scale"));
    result.b_ln = GTK_WIDGET(gtk_builder_get_object(builder, "b_ln"));
    result.b_log = GTK_WIDGET(gtk_builder_get_object(builder, "b_log"));
	result.b_x = GTK_WIDGET(gtk_builder_get_object(builder, "b_x"));
	result.canvas_tgl_list = GTK_WIDGET(gtk_builder_get_object(builder, "canvas_tgl_list"));
    result.canvas_stack = GTK_WIDGET(gtk_builder_get_object(builder, "canvas"));
    return result;
}

void activate (GtkApplication* app) {
    gtk_init();
	GtkCssProvider *css_provider;
	GdkDisplay *display;

	css_provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(css_provider, "./src/gui/style.css");

	display = gdk_display_get_default();
    gtk_style_context_add_provider_for_display(display, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

	builder = gtk_builder_new_from_file("/home/timothey/Repositories/SmartCalc/src/gui/smc_2.ui");
	layout = Init_UI_layout();
	graph_area = GTK_WIDGET(gtk_builder_get_object(builder, "graph_area"));

	GtkWidget *window;
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
	gtk_application_add_window(app, GTK_WINDOW(window));
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

	entry = GTK_WIDGET(gtk_builder_get_object(builder, "main_entry"));

	marking();
	add_signals();

	gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(graph_area), callback_draw, NULL, NULL);
	gtk_widget_queue_draw(graph_area);

    gtk_widget_set_visible(window, true);
	g_object_unref (css_provider);
    g_object_unref (display);
}

void marking() {
	GtkRequisition *rq_nat = gtk_requisition_new();
	gtk_widget_get_preferred_size(gtk_widget_get_parent(graph_area), NULL, rq_nat);
	gtk_widget_set_size_request(entry, BUTTON_WIDTH * 9.8, 0);
	gtk_widget_set_size_request(graph_area, BUTTON_WIDTH * 6, BUTTON_HEIGHT * 7);
	gtk_widget_set_size_request(layout.box_left, BUTTON_WIDTH * 1, BUTTON_HEIGHT * 5);
	gtk_widget_set_size_request(layout.box_center, BUTTON_WIDTH * 3, BUTTON_HEIGHT * 5);
	gtk_widget_set_size_request(layout.frame_right, BUTTON_WIDTH * 7, BUTTON_HEIGHT * 8);
	gtk_widget_set_size_request(layout.b_7, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_4, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_1, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_0, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_8, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_9, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_eql, BUTTON_WIDTH * 3, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_min, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_plus, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_mul, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_div, BUTTON_WIDTH, BUTTON_HEIGHT);
	gtk_widget_set_size_request(layout.b_x, BUTTON_WIDTH * 0.95, BUTTON_HEIGHT * 0.95);
}

void add_signals() {
	g_signal_connect(G_OBJECT(layout.b_0), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_1), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_2), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_3), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_4), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_5), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_6), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_7), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_8), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_9), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_dot), "clicked", G_CALLBACK(callback_nums), NULL);
	g_signal_connect(G_OBJECT(layout.b_x), "clicked", G_CALLBACK(callback_nums), NULL);

	g_signal_connect(G_OBJECT(layout.b_plus), "clicked", G_CALLBACK(callback_op), NULL);
	g_signal_connect(G_OBJECT(layout.b_min), "clicked", G_CALLBACK(callback_op), NULL);
	g_signal_connect(G_OBJECT(layout.b_div), "clicked", G_CALLBACK(callback_op), NULL);
	g_signal_connect(G_OBJECT(layout.b_mul), "clicked", G_CALLBACK(callback_op), NULL);

	g_signal_connect(G_OBJECT(layout.b_p), "clicked", G_CALLBACK(callback_p), NULL);
	g_signal_connect(G_OBJECT(layout.b_clear_all), "clicked", G_CALLBACK(callback_clear_all), NULL);
	
	g_signal_connect(G_OBJECT(layout.b_sin), "clicked", G_CALLBACK(callback_sin), NULL);
	g_signal_connect(G_OBJECT(layout.b_cos), "clicked", G_CALLBACK(callback_cos), NULL);
	g_signal_connect(G_OBJECT(layout.b_tan), "clicked", G_CALLBACK(callback_tan), NULL);
	g_signal_connect(G_OBJECT(layout.b_asin), "clicked", G_CALLBACK(callback_asin), NULL);
	g_signal_connect(G_OBJECT(layout.b_acos), "clicked", G_CALLBACK(callback_acos), NULL);
	g_signal_connect(G_OBJECT(layout.b_atan), "clicked", G_CALLBACK(callback_atan), NULL);

	g_signal_connect(G_OBJECT(layout.b_scale), "clicked", G_CALLBACK(callback_scale), NULL);
	g_signal_connect(G_OBJECT(layout.b_log), "clicked", G_CALLBACK(callback_log), NULL);
	g_signal_connect(G_OBJECT(layout.b_ln), "clicked", G_CALLBACK(callback_ln), NULL);

	g_signal_connect(G_OBJECT(layout.b_eql), "clicked", G_CALLBACK(output), NULL);

	g_signal_connect(G_OBJECT(layout.canvas_tgl_list), "row-selected", G_CALLBACK(tgl_canvas), NULL);
}

void callback_nums(GtkWidget *widget) {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	gtk_editable_insert_text(GTK_EDITABLE(entry), gtk_button_get_label(GTK_BUTTON(widget)), 1, &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos);
}

void callback_op(GtkWidget *widget) {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	gtk_editable_insert_text(GTK_EDITABLE(entry), gtk_button_get_label(GTK_BUTTON(widget)), 1, &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos);
}

void callback_p() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *P = " 3.1415926 ";
	gtk_editable_insert_text(GTK_EDITABLE(entry), P, strlen(P), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos);
}

void callback_clear_all() {
	gtk_editable_delete_text(GTK_EDITABLE(entry), 0, 256);
	gtk_editable_set_position(GTK_EDITABLE(entry), 0);
}

void callback_sin() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "sin()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void callback_cos() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "cos()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void callback_tan() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "tan()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void callback_asin() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "asin()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void callback_acos() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "acos()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void callback_atan() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "atan()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void callback_scale() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "^";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos);
}

void callback_log() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "log()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void callback_ln() {
	gint pos = gtk_editable_get_position(GTK_EDITABLE(entry));
	char *fun = "ln()";
	gtk_editable_insert_text(GTK_EDITABLE(entry), fun, strlen(fun), &pos);
	gtk_editable_set_position(GTK_EDITABLE(entry), pos - 1);
}

void tgl_canvas(GtkListBox *, GtkListBoxRow* row) {
	gint idx = gtk_list_box_row_get_index(row);
	if (idx == 0) {
		gtk_stack_set_visible_child_name(GTK_STACK(layout.canvas_stack), "graph_stack_page");
	} else if (idx == 1) {
		gtk_stack_set_visible_child_name(GTK_STACK(layout.canvas_stack), "credit_stack_page");
	} else if (idx == 2) {
		gtk_stack_set_visible_child_name(GTK_STACK(layout.canvas_stack), "deposit_stack_page");
	}
}

double f (double x) {
	return x * 2;
}

void callback_draw(GtkDrawingArea *widget, cairo_t *cr, int, int, void *) {
	gint width = gtk_widget_get_width(GTK_WIDGET(widget));
	gint height = gtk_widget_get_height(GTK_WIDGET(widget));

	gdouble step_x = 2.0, step_y = 2.0;
	gdouble x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;

	cairo_set_source_rgba(cr, 0, 0, 0, 0.85);
    cairo_rectangle(cr, 0, 0, width, height);
	cairo_fill(cr);

	cairo_translate(cr, width / 2, height / 2);
	cairo_scale(cr, 10.0, -10.0);

	cairo_device_to_user_distance(cr, &step_x, &step_y);
	cairo_clip_extents(cr, &x1, &y1, &x2, &y2);
	cairo_set_line_width(cr, step_x);

	cairo_set_source_rgb (cr, 0.4, 0.4, 1.0);
    cairo_move_to (cr, x1, 0.0);
    cairo_line_to (cr, x2, 0.0);
    cairo_move_to (cr, 0.0, y1);
    cairo_line_to (cr, 0.0, y2);
    cairo_stroke (cr);

	if (is_function) {
		for (gdouble x = x1; x < x2; x += step_x) {
			cairo_line_to(cr, x, calc(postfix, x));
		}
		cairo_set_source_rgba(cr, 1.0, 0.0, 0.0, 0.5);
		cairo_stroke(cr);
		is_function = false;
	}
}

void output() {
    char expression[IO_MAX_SIZE * 2] = {"\0"};
    get_input(expression);
    if (gtk_entry_get_text_length(GTK_ENTRY(entry))) {
		infix_to_postfix(expression);
        callback_clear_all();
        gint pos = 0;

        if (!is_function) {
            double result = calc(postfix, 0);
            char result_str[IO_MAX_SIZE] = {"\0"};
            sprintf(result_str, "%lf", result);
            gtk_editable_insert_text(GTK_EDITABLE(entry), result_str, strlen(result_str), &pos);
        } else if (is_function) {
			gtk_widget_queue_draw(graph_area);
		}
    }
}
