#include <gtk/gtk.h>

int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *spin;
    GtkWidget *box;
    GtkWidget *label;
    GtkObject *adjustment;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    box = gtk_hbox_new(FALSE, 10);
    gtk_container_add(GTK_CONTAINER(window), box);

    adjustment=gtk_adjustment_new(2007, 1900, 2100, 1, 1, 0);
    spin = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment), 0.5, 0);
    gtk_box_pack_start(GTK_BOX(box), spin, TRUE, TRUE, 5);

    label = gtk_label_new("年");
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();
}
