#include <gtk/gtk.h>
static gboolean transparent_expose(GtkWidget *widget, GdkEventExpose *event)
{
	cairo_t *cr;
	cr = gdk_cairo_create(widget->window);
	cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
	gdk_cairo_region(cr, event->region);
	cairo_fill(cr);
	cairo_destroy(cr);
	return FALSE;
}
static gboolean window_expose_event(GtkWidget *widget, GdkEventExpose *event)
{
	GdkRegion *region;
	GtkWidget *child;
	cairo_t *cr;
	child = gtk_bin_get_child(GTK_BIN(widget));
	cr = gdk_cairo_create(widget->window);
	gdk_cairo_set_source_pixmap(cr, child->window, child->allocation.x, child->allocation.y);
	region = gdk_region_rectangle(&child->allocation);
	gdk_region_intersect(region, event->region);
	gdk_cairo_region(cr, region);
	cairo_clip(cr);
	cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
	cairo_paint_with_alpha(cr, 0.5);
	cairo_destroy(cr);
	return FALSE;

}
int main(int argc, char** argv)
{
	GtkWidget *window, *event, *button;
	GdkScreen *screen;
	GdkColormap *rgba;
	GdkColor red;

	gtk_init(&argc, &argv);

	button = gtk_button_new_with_label("A Button");
	event = gtk_event_box_new();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 400, 300);
	g_signal_connect(G_OBJECT(window), "destroy", gtk_main_quit, NULL);
	gdk_color_parse("red", &red);
	gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &red);

	screen = gtk_widget_get_screen(event);
	rgba = gdk_screen_get_rgba_colormap(screen);
	gtk_widget_set_colormap(event, rgba);
	gtk_widget_set_app_paintable(GTK_WIDGET(event), TRUE);
	g_signal_connect(event, "expose-event", G_CALLBACK(transparent_expose), NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	gtk_container_add(GTK_CONTAINER(window), event);
	gtk_container_add(GTK_CONTAINER(event), button);
	gtk_widget_show_all(window);
	gdk_window_set_composited(event->window, TRUE);
	g_signal_connect_after(window, "expose-event", G_CALLBACK(window_expose_event), NULL);
	gtk_main();
	return 0;
}
