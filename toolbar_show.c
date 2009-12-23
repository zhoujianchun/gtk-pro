#include <gtk/gtk.h>
void button_event(GtkWidget *widget, gpointer data)
{
    g_print("%s\n", data);
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *toolbar;
    GtkWidget *image;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    box = gtk_vbox_new(FALSE, 0);
    toolbar = gtk_toolbar_new();
    gtk_box_pack_start(GTK_BOX(box), toolbar, FALSE, TRUE, 5);

    image = gtk_image_new_from_file("earth.png");
    gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "earth", "Our beautiful earth", NULL, image, (GtkSignalFunc)button_event, "Our beautiful earth");
    image = gtk_image_new_from_file("lock.png");
    gtk_toolbar_append_item(GTK_TOOLBAR(toolbar), "lock", "Lock your heart", NULL, image, (GtkSignalFunc)button_event, "lock your heart");

    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

