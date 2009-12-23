#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget* pic1;
GtkWidget* pic2;
GtkWidget* bg;

GtkWidget *fixed;

GtkWidget* box;
GtkWidget* fixed_on_box;
gint timeout_id = 0;

GtkWidget* get_child_at_pos(GtkWidget* container, gfloat x, gfloat y)
{
	GList *children = gtk_container_get_children(GTK_CONTAINER(container));
	int len = g_list_length(children);
	int i;
	for(i =0; i < len; i++)
	{
		gint px, py, width, height;
		GdkWindow *w = gtk_widget_get_window(g_list_nth_data(children, i));
		gdk_window_get_position(w, &px, &py);
		gtk_widget_get_size_request(w, &width, &height);
		if(x >= px && x <= px + width && y >= py && y <= py + height)
			return w;
	}
	return NULL;
}

void on_pic2_released(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
}

gboolean time_out_cb(gpointer data)
{
    static int x = 0;
    static int y = 0;
    //gtk_fixed_move(GTK_FIXED(fixed), pic2, ++x, ++y);
    gtk_fixed_move(GTK_FIXED(fixed), pic1, ++x, ++y);
    //gtk_fixed_move(GTK_FIXED(fixed), box, ++x, ++y);
	if(x == 200)
	{
		timeout_id = 0;
		return FALSE;
	}
    return TRUE;
}
gboolean on_window_event(GtkWidget* window, GdkEvent *event, gpointer data)
{
	static guint32 press_time = 0;
	switch(event->type)
	{
		case GDK_MOTION_NOTIFY:
			///printf("GDK_MOTION_NOTIFY\n");
			break;
		case GDK_BUTTON_PRESS:
			//printf("GDK_BUTTON_PRESS %d\n", ((GdkEventButton*)event)->time);
			printf("GDK_BUTTON_PRESS at (%f, %f)\n", ((GdkEventButton*)event)->x, ((GdkEventButton*)event)->y);
			press_time = ((GdkEventButton*)event)->time;
			break;
		case GDK_BUTTON_RELEASE:
			printf("GDK_BUTTON_RELEASE at (%f, %f)\n", ((GdkEventButton*)event)->x, ((GdkEventButton*)event)->y);
			printf("----------------------------------------------------------\n");
			//printf("GDK_BUTTON_RELEASE %d\n", ((GdkEventButton*)event)->time);
			//printf("TIME %d\n", ((GdkEventButton*)event)->time - press_time);
			/*if(pic1 == gtk_container_get_focus_child(GTK_CONTAINER(window)))
				printf("pic2\n");
			else
				printf("unknown\n");
				*/
			/*if(((GdkEventButton*)event)->time - press_time < 200)
			{
				if(!timeout_id)
					timeout_id = g_timeout_add(5, time_out_cb, NULL);
			}*/
			//printf("%s\n", gtk_widget_get_name(get_child_at_pos(window, ((GdkEventButton*)event)->x,
			//				((GdkEventButton*)event)->y)));
			break;
		case GDK_DRAG_MOTION:
			printf("GDK_DRAG_MOTION\n");
			break;
	}
	return FALSE;
}

int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	fixed = gtk_fixed_new();
	gtk_widget_set_name(fixed, "fixed");
	fixed_on_box = gtk_fixed_new();

	gtk_widget_set_size_request(window, 800, 480);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), "pressed");
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | 
			GDK_POINTER_MOTION_MASK);
	g_signal_connect(G_OBJECT(window), "event", G_CALLBACK(on_window_event), NULL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	bg = gtk_image_new_from_file("background.png");
	gtk_widget_set_size_request(bg, 800, 480);
	gtk_fixed_put(GTK_FIXED(fixed), bg, 0, 0);

	//gtk_container_add(GTK_CONTAINER(fixed), fixed_on_box);

	pic1 = gtk_image_new_from_file("movie_logo.png");
	gtk_widget_set_name(pic1, "pic1");
	gtk_widget_set_size_request(pic1, 150, 150);

	pic2 = gtk_image_new_from_file("button_bg.png");
	gtk_widget_set_size_request(pic2, 50, 50);
	//g_signal_connect(G_OBJECT(window), "button-release-event", G_CALLBACK(on_pic2_released), NULL);

	gtk_fixed_put(GTK_FIXED(fixed), pic1, 10, 10);
	//gtk_fixed_put(GTK_FIXED(fixed_on_box), pic1, 10, 10);
	//gtk_fixed_put(GTK_FIXED(fixed_on_box), pic2, 60, 60);

	gtk_container_add(GTK_CONTAINER(window), fixed);

    //g_timeout_add(10, time_out_cb, NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

