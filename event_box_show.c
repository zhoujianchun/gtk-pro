#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *event_box;
    GtkWidget *label;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 200, 100);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    event_box = gtk_event_box_new();
    gtk_container_add(GTK_CONTAINER(window), event_box);
    gtk_widget_show(event_box);

    label = gtk_label_new("Click Here To Quit");
    gtk_container_add(GTK_CONTAINER(event_box), label);
    gtk_widget_show(label);

    g_signal_connect(G_OBJECT(event_box), "button_press_event", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

