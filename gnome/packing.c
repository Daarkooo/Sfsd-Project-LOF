#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data){
    g_print("Yoo\n");
}

static void activate (GtkApplication *app, gpointer user_data){
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button1;
    GtkWidget *button;

    // create a new window and set its title
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "sfsd");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // the container that will pack the buttons
    grid = gtk_grid_new();

    // pack the container in the window
    gtk_container_add(GTK_CONTAINER(window), grid);

    button = gtk_button_new_with_label("Button 1");
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

    // Place the first button in the grid cell (0, 0), and make it fill just 1 cell horizontally    and vertically 

    gtk_grid_attach(GTK_GRID(grid), button,0,0,1,1);

    button1 = gtk_button_new_with_label("Button 2");
    g_signal_connect(button1, "clicked", G_CALLBACK(print_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button1,1,0,1,1);

    button = gtk_button_new_with_label("Quit");
    // testing gtk_widget_destroy
    // g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy),button1)
    gtk_grid_attach(GTK_GRID(grid), button,0,1,2,1);

    //show them all in one go, by calling gtk_widget_show_all() on the window.  This call recursively calls gtk_widget_show() on all widgets that are contained in the window, directly or indirectly.
    gtk_widget_show_all(window);

}   

int main(int argc, char **argv){
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example",G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app,"activate",G_CALLBACK(activate),NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
