#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    // Initialisation de GTK
    gtk_init(&argc, &argv);

    // Création de la fenêtre principale
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Application GTK3");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 200);

    // Création d'un bouton
    GtkWidget *button = gtk_button_new_with_label("Cliquez-moi");

    // Chargement du fichier CSS
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "./style.css", NULL);

    // Application des styles au bouton
    GtkStyleContext *context = gtk_widget_get_style_context(button);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Ajout du bouton à la fenêtre
    gtk_container_add(GTK_CONTAINER(window), button);

    // Gestionnaire d'événements pour la fermeture de la fenêtre
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Affichage de la fenêtre et démarrage de la boucle principale
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
