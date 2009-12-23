#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	
    table = gtk_table_new(4, 4, FALSE);

    button = gtk_button_new_with_label("BUTTON1");
    gtk_table_attach(GTK_TABLE(table), button, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show(button);

    button = gtk_button_new_with_label("BUTTON2");
    gtk_table_attach(GTK_TABLE(table), button, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show(button);
    
    button = gtk_button_new_with_label("BUTTON3");
    gtk_table_attach(GTK_TABLE(table), button, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show(button);
    
    gtk_container_add(GTK_CONTAINER(window), table);
    gtk_widget_show(table);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

