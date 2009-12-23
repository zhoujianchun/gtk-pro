#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *button;
    GtkWidget *box;
    GSList *group = NULL;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    frame = gtk_frame_new("Sex");
    //frame = gtk_aspect_frame_new("Sex", 0.1, 0.1, 3, FALSE);
    gtk_container_add(GTK_CONTAINER(window), frame);

    box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(frame), box);

    button = gtk_radio_button_new_with_label(group, "Male");
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(button));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 5);

    button = gtk_radio_button_new_with_label(group, "Female");
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 5);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

