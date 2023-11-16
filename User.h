//
// Created by Alessio on 15/11/2023.
//

#ifndef LABORATORY_USER_H
#define LABORATORY_USER_H
#include "ShoppingList.h"

class User:public IObserver{
private:
    multimap<string,ShoppingList*>userShoppingList;
    string username;
public:
    User(string n);

    void addList(ShoppingList *shoppingList);
    void update(int q,float p,string n)override;
    void add(Item *item,ShoppingList *shoppingList);

    string getUsername() override;
    void setUsername(const string &username);

};

#endif //LABORATORY_USER_H
