#include <gtk/gtk.h>
gboolean timeout_cb(gpointer data)
{
	static int i = 5;
	gtk_widget_set_size_request(GTK_WIDGET(data), 25 + i, 25);
	i = i + 5;
	return TRUE;
}
int main(int argc, char** argv)
{
    GtkWidget *window;
	GtkWidget* pic;
	GtkWidget* pic2;
	GtkWidget* fixed;
	int width, height;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 800, 450);
	gtk_window_get_size(GTK_WINDOW(window), &width, &height);
	printf("window size is (%d, %d)\n", width, height);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), "pressed");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	//pic = gtk_image_new_from_file("background.png");
	//gtk_widget_set_size_request(pic, 100, 100);

	pic2 = gtk_image_new_from_file("process.png");
	gtk_widget_set_size_request(pic2, 25, 25);

	fixed = gtk_fixed_new();
	
	gtk_container_add(GTK_CONTAINER(window), pic2);
	//gtk_container_add(GTK_CONTAINER(fixed), pic);
	//gtk_container_add(GTK_CONTAINER(fixed), pic);
	//gtk_fixed_put(GTK_FIXED(fixed), pic, 0, 0);
	//gtk_fixed_put(GTK_FIXED(fixed), pic2 , 0, 0);

    gtk_widget_show_all(window);
	//gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
	///g_timeout_add_seconds(1, timeout_cb, pic2);
    gtk_main();
    return 0;
}

