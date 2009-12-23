#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *notebook;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *lb;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    notebook = gtk_notebook_new();
    //gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_BOTTOM);
    //gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_LEFT);
    //gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_RIGHT);
    gtk_container_add(GTK_CONTAINER(window), notebook);

    box = gtk_hbox_new(FALSE, 0);
    label = gtk_label_new("Common");
    lb = gtk_label_new("This is a common page");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box, label);
    gtk_box_pack_start(GTK_BOX(box), lb, FALSE, FALSE, 10);

    box = gtk_hbox_new(FALSE, 0);
    label = gtk_label_new("Advanced");
    lb = gtk_label_new("This is an anvanced  page");
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box, label);
    gtk_box_pack_start(GTK_BOX(box), lb, FALSE, FALSE, 10);
    
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

