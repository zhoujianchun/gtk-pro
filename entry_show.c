#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *entry;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, 200, 100);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //entry = gtk_entry_new();
    entry = gtk_entry_new_with_max_length(10);
    //gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE);
    gtk_widget_show(entry);

    gtk_container_add(GTK_CONTAINER(window), entry);

    gtk_widget_show(window);
    gtk_main();
    return 0;
}

