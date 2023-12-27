#include <gtk/gtk.h>


void Hello_World(GtkWidget* window) {
    printf("Hello Adel, you clicked!\n");
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);
    // Create a button with the label "Click me"
    GtkWidget* button = gtk_button_new_with_label("Click me");
    /* Connect the 'clicked' signal to our callback function */
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(Hello_World), NULL);

    //put the button in the window container
    gtk_container_add(GTK_CONTAINER(window), button);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //show the gtk window
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
