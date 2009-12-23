#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
	GtkWidget* pic;
	GtkWidget* pic2;
	GtkWidget* fixed;
	int width, height;
    gtk_init(&argc, &argv);

	pic = gtk_image_new_from_file("background.png");
	gtk_widget_set_size_request(pic, 100, 100);



    gtk_widget_show(pic);
    gtk_main();
    return 0;
}

