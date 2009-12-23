#include <gtk/gtk.h>
void combo_selected(GtkWidget *widget, gpointer window)
{
    gchar *text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
    g_print("%s\n",text);
    g_free(text);
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *combo;
    GList *glist = NULL;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    combo = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Please Choose");
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Apple");
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Orange");
    gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Pear");
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);

    g_signal_connect(G_OBJECT(combo), "changed", G_CALLBACK(combo_selected), NULL);

    gtk_container_add(GTK_CONTAINER(window), combo);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

