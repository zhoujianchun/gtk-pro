#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL); 
    button = gtk_button_new_with_label("BUTTON");
    gtk_widget_hide(button);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_set_sensitive(button, FALSE);
    gtk_widget_show(button);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

