//
// Created by Alessio on 15/11/2023.
//

#ifndef LABORATORY_USER_H
#define LABORATORY_USER_H
#include "ShoppingList.h"

class User : public IObserver {
private:
    multimap<string, shared_ptr<ShoppingList>> userShoppingList;//container per le liste [nomeLista,Lista]
    string username;//nome dell'utente
public:
    User(const string &n);

    void addList(shared_ptr<ShoppingList> shoppingList);

    void update() override;

    void add(shared_ptr<Item> item, shared_ptr<ShoppingList> shoppingList);

    void remove(shared_ptr<Item> item, shared_ptr<ShoppingList> shoppingList);

    void filterList(string c, shared_ptr<ShoppingList> shoppingList);

    void printList(shared_ptr<ShoppingList> shoppingList);

    const string &getUsername() const override;

    const multimap<string, shared_ptr<ShoppingList>> &getUserShoppingList() const;

};

#endif //LABORATORY_USER_H
