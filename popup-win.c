#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_POPUP);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), "pressed");
    gtk_window_move(GTK_WINDOW(window), 0, 0);
	gtk_widget_set_size_request(window, 700,200);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

