#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget* pic;
GtkWidget* pic2;
GtkWidget* fixed;

gboolean timeout_cb(gpointer data)
{
	static int x = 50;
	static int y = 50;

	//static int px = 375;
	//static int py = 375;

	//gtk_fixed_move(GTK_FIXED(fixed), pic, px--, py--);
	gtk_widget_set_size_request(pic, x++, y++);
	if(x == 300)
	{
		x = 50, y = 50;
		return FALSE;
	}
	return TRUE;
}

int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 800, 800);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), "pressed");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	pic = gtk_image_new_from_file("background.png");
	gtk_widget_set_size_request(pic, 50, 50);

//	pic2 = gtk_image_new_from_file("movie_logo.png");
//	gtk_widget_set_size_request(pic2, 100, 100);

	fixed = gtk_fixed_new();
	
	gtk_container_add(GTK_CONTAINER(window), fixed);
	//gtk_container_add(GTK_CONTAINER(fixed), pic);
	//gtk_container_add(GTK_CONTAINER(fixed), pic);
	gtk_fixed_put(GTK_FIXED(fixed), pic, 375, 375);
	//gtk_fixed_put(GTK_FIXED(fixed), pic2 , 100, 100);
	g_timeout_add(10, timeout_cb, NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

