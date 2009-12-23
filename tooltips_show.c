#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkTooltips *tooltip;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    button = gtk_button_new_with_label("BUTTON");
    gtk_container_add(GTK_CONTAINER(window), button);
    tooltip = gtk_tooltips_new();
    gtk_tooltips_set_tip(GTK_TOOLTIPS(tooltip), button, "How old are you?", NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

