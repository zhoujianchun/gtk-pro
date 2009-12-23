#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *ruler;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 600, 100);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    box = gtk_vbox_new(FALSE, 0);
    ruler = gtk_hruler_new();
    gtk_ruler_set_metric(GTK_RULER(ruler), GTK_PIXELS);
    gtk_ruler_set_range(GTK_RULER(ruler), 0, 10, 0, 10);
    gtk_box_pack_start(GTK_BOX(box), ruler, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(window), box);
    
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

