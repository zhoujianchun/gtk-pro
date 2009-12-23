#include <gtk/gtk.h>
GtkWidget *create_menu_item(GtkWidget *MenuBar, char* test)
{
    GtkWidget *MenuItem;
    MenuItem = gtk_menu_item_new_with_label(test);
    gtk_menu_shell_append(GTK_MENU_SHELL(MenuBar), MenuItem);
    gtk_widget_show(MenuItem);
    return MenuItem;
}
int main(int argc, char** argv)
{
    GtkWidget *window;
    GtkWidget *MenuBar;
    GtkWidget *box;
    GtkWidget *menu;
    GtkWidget *menuitem;
    GtkWidget *exit;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 400, 200);
    g_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    box = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);
    MenuBar = gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(box), MenuBar, FALSE, TRUE, 0);

    menuitem = create_menu_item(MenuBar, "File");

    menu = gtk_menu_new();
    create_menu_item(menu, "New");
    create_menu_item(menu, "Open");
    create_menu_item(menu, "Save");
    exit = create_menu_item(menu, "Exit");
    g_signal_connect(G_OBJECT(exit), "activate", G_CALLBACK(gtk_main_quit), NULL);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
    gtk_widget_show(menu);

    create_menu_item(MenuBar, "Edit");
    create_menu_item(MenuBar, "View");
    create_menu_item(MenuBar, "Insert");
    create_menu_item(MenuBar, "Tool");
    
    gtk_widget_show(MenuBar);
    gtk_widget_show(box);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}

