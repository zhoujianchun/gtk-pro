#include <gtk/gtk.h>
void pack_new_button(GtkWidget *box, char *label)
{
    GtkWidget *button;
    button = gtk_button_new_with_label(label);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);
    gtk_widget_show(button);
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *box;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    box = gtk_vbox_new(FALSE, 0);

    pack_new_button(box, "BUTTON1");
    pack_new_button(box, "BUTTON2");
    pack_new_button(box, "BUTTON3");
    pack_new_button(box, "BUTTON4");
    pack_new_button(box, "BUTTON5");

    gtk_container_add(GTK_CONTAINER(window), box);
    
    gtk_widget_show(box);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

