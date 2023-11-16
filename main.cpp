#include <iostream>
#include "ShoppingList.h"
#include "User.h"


int main() {
// Creazione degli utenti
    User user1("Alice");
    User user2("Bob");

    // Creazione di alcune liste della spesa
    ShoppingList list1("ListaSpesaA");
    ShoppingList list2("ListaSpesaB");
    ShoppingList list3("ListaSpesaC");

    // Aggiunta delle liste agli utenti
    user1.addList(&list1);
    user1.addList(&list2);
    user2.addList(&list3);

    // Creazione di alcuni oggetti da acquistare
    Item item1("Mela", "Frutta", 5, 1.5);
    Item item2("Pane", "Alimenti", 2, 2.0);
    Item item3("Latte", "Latticini", 1, 3.0);
    Item item4("Pasta", "Alimenti", 3, 1.2);
    Item item5("Formaggio", "Latticini", 2, 4.5);
    Item item6("Succo d'arancia", "Bevande", 1, 2.2);
    Item item7("Pollo", "Carne", 1, 6.0);
    Item item8("Riso", "Cereali", 4, 2.5);
    Item item9("Yogurt", "Latticini", 3, 1.8);
    Item item10("Insalata", "Verdure", 2, 2.7);
    Item item11("Pomodori", "Verdure", 4, 1.0);
    Item item12("Acqua minerale", "Bevande", 6, 0.8);
    Item item13("Cioccolato", "Dolci", 2, 3.5);
    Item item14("Caffè", "Bevande", 1, 5.0);
    Item item15("Salmone", "Pesce", 1, 8.0);

    // Aggiunta degli oggetti alle liste della spesa
    user1.add(&item1,&list1);

    // Stampa delle informazioni sulle liste della spesa


    // Rimozione di un oggetto dalla lista
    list1.removeItem(&item1);



    return 0;

}
