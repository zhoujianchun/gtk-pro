#include <gtk/gtk.h>
void button_event(GtkWidget *widget, gpointer data)
{
    g_print("button event : %s \n", data);
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL); 

    button = gtk_toggle_button_new_with_label("TOGGLE BUTTON");
    g_signal_connect(G_OBJECT(button), "pressed", G_CALLBACK(button_event), "pressed");
    g_signal_connect(G_OBJECT(button), "released", G_CALLBACK(button_event), "released");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_event), "clicked");
    g_signal_connect(G_OBJECT(button), "enter", G_CALLBACK(button_event), "enter");
    g_signal_connect(G_OBJECT(button), "leave", G_CALLBACK(button_event), "leave");
    g_signal_connect(G_OBJECT(button), "toggled", G_CALLBACK(button_event), "toggled");

    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show(button);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

