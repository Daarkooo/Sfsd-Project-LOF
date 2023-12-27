#include <gtk/gtk.h>

int main(int argc, char *argv[]){

    GtkWidget *window;
    const gchar *const title = "SFSD";
    gint width, height;

    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_window_set_title(GTK_WINDOW(window), title);  // setting window title
    gtk_window_set_default_size(GTK_WINDOW(window),600,600);// set window size
    gtk_window_get_size(GTK_WINDOW(window), &width, &height);// get actual window size
    g_print("width: %d height: %d\n", width, height);

    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);// set window position
    gtk_window_get_position(GTK_WINDOW(window), &width, &height);// get window position
    g_print("width: %d height: %d\n", width, height);

    gtk_window_move(GTK_WINDOW(window),500,155); // move window

    gtk_container_set_border_width(GTK_CONTAINER(window), 20); // add window border

    g_signal_connect(window, "delete_event",gtk_main_quit,NULL);

    gtk_widget_show(window);

    gtk_main();
    return 0;

}