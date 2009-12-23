#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *arrow;
    GtkWidget *box;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box = gtk_hbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    button = gtk_button_new();
    arrow = gtk_arrow_new(GTK_ARROW_UP, GTK_SHADOW_OUT);
    gtk_container_add(GTK_CONTAINER(button), arrow);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, TRUE, 0);

    button = gtk_button_new();
    arrow = gtk_arrow_new(GTK_ARROW_DOWN, GTK_SHADOW_OUT);
    gtk_container_add(GTK_CONTAINER(button), arrow);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

