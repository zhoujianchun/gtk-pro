#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *calendar;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    calendar = gtk_calendar_new();
    gtk_calendar_display_options(GTK_CALENDAR(calendar), GTK_CALENDAR_SHOW_HEADING|GTK_CALENDAR_SHOW_DAY_NAMES|
	    GTK_CALENDAR_SHOW_WEEK_NUMBERS|GTK_CALENDAR_WEEK_START_MONDAY);
    gtk_calendar_select_month(GTK_CALENDAR(calendar),8,1985);
    gtk_calendar_select_day(GTK_CALENDAR(calendar),8);
    gtk_container_add(GTK_CONTAINER(window), calendar);

    gtk_widget_show_all(window);
    gtk_main();
}

