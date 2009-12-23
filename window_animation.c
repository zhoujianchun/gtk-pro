#include <gtk/gtk.h>
gboolean timeout_cb(gpointer data)
{
	static int x = 0;
	static int y = 0;
	int pos_x, pos_y;
	GtkWidget* widget = GTK_WIDGET(data);

	gtk_window_move(GTK_WINDOW(widget), x++, y++);

	//gtk_window_get_position(GTK_WINDOW(widget), &pos_x, &pos_y);
	//printf("position of window is (%d, %d)\n", pos_x, pos_y);
	//if (894 == y)
		//x =0, y = 0;

}
int main(int argc, char** argv)
{
    GtkWidget *popup_window;
	GtkWidget *window;
	GtkWidget* pic;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window, 400, 300);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), "pressed");
    popup_window = gtk_window_new(GTK_WINDOW_POPUP);
    //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	//gtk_container_add(GTK_CONTAINER(frame), background);
	//gtk_container_add(GTK_CONTAINER(window), frame );
	pic = gtk_image_new_from_file("background.png");
	gtk_widget_set_size_request(pic, 20, 20);
	gtk_container_add(GTK_CONTAINER(popup_window), pic);
	g_timeout_add(10, timeout_cb, popup_window);

    gtk_widget_show_all(window);
    gtk_widget_show_all(popup_window);
    gtk_main();
    return 0;
}

