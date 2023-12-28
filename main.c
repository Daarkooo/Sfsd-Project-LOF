#include <gtk/gtk.h>

// Structure pour représenter un nœud dans la liste
typedef struct Node {
    int data;
    struct Node* next;
} Node, *list;

// Fonction pour ajouter un nœud à la fin de la liste
void appendNode(list* head, int data) {
    list newNode = g_new(Node, 1);
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        list current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Fonction pour dessiner la liste chaînée
gboolean drawCallback(GtkWidget* widget, cairo_t* cr, gpointer data) {
    list head = (list)data;

    // Effacer le dessin précédent
    cairo_set_source_rgb(cr, 1, 1, 1); // Couleur de fond blanche
    cairo_paint(cr);

    // Dessiner la liste chaînée
    cairo_set_source_rgb(cr, 0, 0, 0); // Couleur du dessin noir
    cairo_set_line_width(cr, 2.0);

    list current = head;
    int x = 50, y = 50; // Position de départ
    while (current != NULL) {
        // Dessiner un cercle
        cairo_arc(cr, x, y, 20, 0, 2 * G_PI);
        cairo_fill(cr);

        // Dessiner une ligne vers le prochain nœud
        if (current->next != NULL) {
            x += 60; // Augmenter la position x pour le prochain nœud
            cairo_move_to(cr, x - 20, y);
            cairo_line_to(cr, x - 40, y);
            cairo_stroke(cr);
        }

        current = current->next;
    }

    return FALSE;
}

// Fonction de rappel pour ajouter un nœud
void addNodeCallback(GtkWidget* widget, gpointer data) {
    list* head = (list*)data;
    appendNode(head, rand() % 100); // Ajouter un nœud avec une donnée aléatoire
    gtk_widget_queue_draw(GTK_WIDGET(widget)); // Redessiner la liste
}

// Fonction de rappel pour supprimer un nœud
void removeNodeCallback(GtkWidget* widget, gpointer data) {
    list* head = (list*)data;
    if (*head != NULL) {
        list temp = *head;
        *head = (*head)->next;
        g_free(temp); // Libérer la mémoire du nœud supprimé
        gtk_widget_queue_draw(GTK_WIDGET(widget)); // Redessiner la liste
    }
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    list head = NULL; // La tête de la liste

    // Ajouter des éléments à la liste
    for (int i = 1; i <= 10; ++i) {
        appendNode(&head, i);
    }

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 400);
    gtk_window_set_title(GTK_WINDOW(window), "Liste Chaînée Interactive");

    GtkWidget* drawingArea = gtk_drawing_area_new();

    // Définir la fonction de rappel pour le dessin
    g_signal_connect(G_OBJECT(drawingArea), "draw", G_CALLBACK(drawCallback), head);

    // Bouton pour ajouter un nœud
    GtkWidget* addButton = gtk_button_new_with_label("Ajouter un nœud");
    g_signal_connect(G_OBJECT(addButton), "clicked", G_CALLBACK(addNodeCallback), &head);

    // Bouton pour supprimer un nœud
    GtkWidget* removeButton = gtk_button_new_with_label("Supprimer un nœud");
    g_signal_connect(G_OBJECT(removeButton), "clicked", G_CALLBACK(removeNodeCallback), &head);

    // Boîte horizontale pour les boutons
    GtkWidget* buttonBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(buttonBox), addButton, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(buttonBox), removeButton, TRUE, TRUE, 5);

    // Boîte verticale principale
    GtkWidget* mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(mainBox), drawingArea, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(mainBox), buttonBox, FALSE, FALSE, 5);

    gtk_container_add(GTK_CONTAINER(window), mainBox);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}