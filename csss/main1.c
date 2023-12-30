#include <gtk/gtk.h>


static void load_css(void){
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;


    const gchar *css_style_file = "style.css";
    GFile *css_fp = g_file_new_for_path(css_style_file);
    GError *error = 0;

    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_file(provider, css_fp, &error);
    g_object_unref(provider);

}


int main(int argc, char *argv[]){

    GtkWidget *window;
    GtkWidget *button;


    gtk_init(&argc, &argv);
    
    load_css();

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_window_set_title(GTK_WINDOW(window), "sfsd");  
    gtk_window_set_default_size(GTK_WINDOW(window),300,300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20); // add window border
    // g_signal_connect(window, "delete_event",gtk_main_quit,NULL);

    button = gtk_button_new_with_label("Click me");
    gtk_widget_set_name(button, "button1");
    gtk_container_add(GTK_CONTAINER(window),button);
    // g_signal_connect(button,"clicked",gtk_main_quit,NULL);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;

}











