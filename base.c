#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_opacity(window, 0.7);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), "pressed");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

