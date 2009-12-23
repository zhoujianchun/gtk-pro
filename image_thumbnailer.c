#include <gtk/gtk.h> 
static void put_pixel(GdkPixbuf *pixbuf, int x, int y, guchar alpha)
{
	guchar *pixels, *p;
	int rowstride, n_channels;

	n_channels = gdk_pixbuf_get_n_channels(pixbuf);
	rowstride = gdk_pixbuf_get_rowstride(pixbuf);
	pixels = gdk_pixbuf_get_pixels(pixbuf);
	p = pixels + y * rowstride + x * n_channels;
	p[3] = alpha;
}
int main(int argc, char** argv)
{
    GtkWidget *window;
	int x, y;

    gtk_init(&argc, &argv);

   /* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_opacity(window, 0.7);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), "pressed");
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_show(window);
    gtk_main();
	*/
	GdkPixbuf* photo = gdk_pixbuf_new_from_file_at_size("bluesky.jpg", 300, 200, NULL);
	//GdkPixbuf* image = gdk_pixbuf_new_from_data(photo,;
	//photo = gdk_pixbuf_flip(photo, FALSE);
	//gdk_pixbuf_fill(photo, 0xff00ff64);
	//gdk_pixbuf_rotate_simple(photo, GDK_PIXBUF_ROTATE_COUNTERCLOCKWISE);
	//gdk_pixbuf_save(photo, "thumbnail.png", "png", NULL, NULL);
	guchar *pixels, *p;
	int rowstride, n_channels, bits, width, height ;
	GdkColorspace cs;

	n_channels = gdk_pixbuf_get_n_channels(photo);
	rowstride = gdk_pixbuf_get_rowstride(photo);
	pixels = gdk_pixbuf_get_pixels(photo);
	bits = gdk_pixbuf_get_bits_per_sample(photo);
	cs = gdk_pixbuf_get_colorspace(photo);
	width = gdk_pixbuf_get_width(photo);
	height = gdk_pixbuf_get_height(photo);
	printf("n_channels %d\n", n_channels);
	printf("rowstride %d\n", rowstride);
	printf("bits %d\n", bits);
	printf("cs %d\n", cs);
	printf("width %d\n", width);
	printf("height %d\n", height);

	//photo = gdk_pixbuf_new_from_data(pixels, cs, TRUE, bits, width, height, rowstride, NULL, NULL);
	//gdk_pixbuf_add_alpha(photo, FALSE, 0, 0, 0);

	for(x = 0; x < width; x++)
	{
		for(y = 0; y < height; y++)
		{
			put_pixel(photo, x, y, 100);
		}
	}
	gdk_pixbuf_save(photo, "thumbnail.jpg", "jpeg", NULL, NULL);

    return 0;
}

