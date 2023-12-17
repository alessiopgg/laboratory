//
// Created by Alessio on 15/11/2023.
//

#ifndef LABORATORY_USER_H
#define LABORATORY_USER_H
#include "ShoppingList.h"

class User:public IObserver{
private:
    multimap<string,shared_ptr<ShoppingList>>userShoppingList;
    string username;
public:
    User(const string &n);

    void addList(shared_ptr<ShoppingList>shoppingList);
    void update()override;
    void add(shared_ptr<Item>item,shared_ptr<ShoppingList>shoppingList);
    void remove(shared_ptr<Item>item,shared_ptr<ShoppingList>shoppingList);
    void filterList(string c,shared_ptr<ShoppingList>shoppingList);
    void printList(shared_ptr<ShoppingList>shoppingList);

    const string &getUsername() const;
    void setUsername(const string &username);
    const multimap<string, shared_ptr<ShoppingList>> &getUserShoppingList() const;
    void setUserShoppingList(const multimap<string, shared_ptr<ShoppingList>> &userShoppingList);

};

#endif //LABORATORY_USER_H
