#include <gtk/gtk.h>

GtkWidget *label;
void button_event(GtkWidget *widget, gpointer *data)
{
    gtk_label_set_text(GTK_LABEL(label), (char*)data);
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;
    GSList *group = NULL;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    label = gtk_label_new("Please Check");
    box = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_widget_show(label);

    button = gtk_radio_button_new_with_label(group, "Radio Button One");
    g_signal_connect(G_OBJECT(button), "pressed", G_CALLBACK(button_event), "You Checked Button One");

    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(button));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);
    gtk_widget_show(button);

    button = gtk_radio_button_new_with_label(group, "Radio Button Two");
    g_signal_connect(G_OBJECT(button), "pressed", G_CALLBACK(button_event), "You Checked Button Two");
    group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(button));
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);
    gtk_widget_show(button);

    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_show(box);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

