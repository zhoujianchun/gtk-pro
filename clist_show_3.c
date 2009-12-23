#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *clist;
    gchar* text1[3] = {"刘备","男","23"};
    gchar* text2[3] = {"张飞","男","18"};
    gchar* text3[3] = {"关羽","男","16"};
    gchar* text4[3] = {"孙二娘","女","25"};
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 150, 100);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    clist =  gtk_clist_new(3);
    gtk_clist_set_column_title(GTK_CLIST(clist), 0, "Name");
    gtk_clist_set_column_title(GTK_CLIST(clist), 1, "Sex");
    gtk_clist_set_column_title(GTK_CLIST(clist), 2, "Age");
    
    gtk_clist_column_titles_show(GTK_CLIST(clist));
    gtk_clist_append(GTK_CLIST(clist), text1);
    gtk_clist_append(GTK_CLIST(clist), text2);
    gtk_clist_append(GTK_CLIST(clist), text3);
    gtk_clist_prepend(GTK_CLIST(clist), text4);

    gtk_container_add(GTK_CONTAINER(window), clist);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

