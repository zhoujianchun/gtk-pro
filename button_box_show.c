#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button_box;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 300, 50);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    button_box = gtk_hbutton_box_new();
    gtk_hbutton_box_set_spacing_default(5);
    gtk_hbutton_box_set_layout_default(GTK_BUTTONBOX_SPREAD);
    gtk_container_add(GTK_CONTAINER(window), button_box);

    button = gtk_button_new_with_label("Open");
    gtk_container_add(GTK_CONTAINER(button_box), button);

    button = gtk_button_new_with_label("Close");
    gtk_container_add(GTK_CONTAINER(button_box), button);

    button = gtk_button_new_with_label("Help");
    gtk_container_add(GTK_CONTAINER(button_box), button);
    
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

