#include <gtk/gtk.h>
void button_event(GtkWidget *widget, gpointer data)
{
    GtkWidget *fc;
    fc = gtk_file_chooser_dialog_new("Open File", NULL, GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
    if(gtk_dialog_run(GTK_DIALOG(fc)) == GTK_RESPONSE_ACCEPT)
    {
	gchar* filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fc));
	g_print("You have choosed file : %s\n", filename);
    }
    gtk_widget_destroy(fc);
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    button = gtk_button_new_with_label("Open File");
    g_signal_connect(GTK_OBJECT(button), "clicked", G_CALLBACK(button_event), NULL);
    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

