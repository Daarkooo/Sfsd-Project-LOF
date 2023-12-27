#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GtkWidget* window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Set the title of the window
    gtk_widget_set_name(window, "First Window");
    gtk_window_set_title(GTK_WINDOW(window), "My First GTK+ Window");
    // Set the size of the window
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    //close the gtk window
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //show the gtk window
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
