#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *fixed;
GtkWidget *button;

gboolean time_out_cb(gpointer data)
{
    static int x = 0;
    static int y = 0;
    gtk_fixed_move(GTK_FIXED(fixed), button, ++x, ++y);
    return TRUE;
}
int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    fixed = gtk_fixed_new();
    button = gtk_button_new_with_label("BUTTON");
    gtk_fixed_put(GTK_FIXED(fixed), button, 10, 10);
    g_timeout_add(100, time_out_cb, NULL);
    gtk_container_add(GTK_CONTAINER(window), fixed);
    
    gtk_widget_show(button);
    gtk_widget_show(fixed);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

