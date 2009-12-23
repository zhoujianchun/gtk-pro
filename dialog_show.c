#include <gtk/gtk.h>
void destroy(GtkWidget *widget, gpointer data)
{
    gtk_widget_destroy(GTK_WIDGET(data));
}
void button_event(GtkWidget *widget, gpointer data)
{
    GtkWidget *button;
    GtkWidget *dialog;

    dialog = gtk_dialog_new();

    button = gtk_button_new_with_label("Yes");
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->action_area), button, TRUE, TRUE, 0);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(gtk_main_quit), NULL);

    button = gtk_button_new_with_label("No");
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->action_area), button, TRUE, TRUE, 0);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(destroy), dialog);
    
    gtk_widget_show_all(dialog);
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 200, 100);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL); 

    button = gtk_button_new_with_label("EXIT");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_event), NULL);

    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

