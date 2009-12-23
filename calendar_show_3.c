#include <gtk/gtk.h>

GtkWidget *calendar;
void button_event(GtkWidget *widget, gpointer data)
{
    guint year;
    guint month;
    guint day;
    gtk_calendar_get_date(GTK_CALENDAR(calendar), &year, &month, &day);
    g_print("Year: %d, Month: %d, Day: %d\n", year, month, day);
}

int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box = gtk_vbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(window), box);

    calendar = gtk_calendar_new();
    gtk_calendar_display_options(GTK_CALENDAR(calendar), GTK_CALENDAR_SHOW_HEADING|GTK_CALENDAR_SHOW_DAY_NAMES|
	    GTK_CALENDAR_SHOW_WEEK_NUMBERS|GTK_CALENDAR_WEEK_START_MONDAY);
    gtk_calendar_select_month(GTK_CALENDAR(calendar),8,1985);
    gtk_calendar_select_day(GTK_CALENDAR(calendar),8);
    gtk_box_pack_start(GTK_BOX(box), calendar, TRUE, TRUE, 5);

    button = gtk_button_new_with_label("OK");
    gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 5);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_event), NULL);

    gtk_widget_show_all(window);
    gtk_main();
}

