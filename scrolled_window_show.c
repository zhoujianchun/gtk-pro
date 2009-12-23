#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *scrolled;
    GtkWidget *text;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled);

    text = gtk_text_view_new();
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scrolled), text);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

