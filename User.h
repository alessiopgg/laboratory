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
    User(string n);

    void addList(shared_ptr<ShoppingList>shoppingList);
    void update(float u,float c,float t, string n, int un)override;
    void add(shared_ptr<Item>item,shared_ptr<ShoppingList>shoppingList);
    void remove(shared_ptr<Item>item,shared_ptr<ShoppingList>shoppingList);


    string getUsername();
    void setUsername(const string &username);
    const multimap<string, shared_ptr<ShoppingList>> &getUserShoppingList() const;
    void setUserShoppingList(const multimap<string, shared_ptr<ShoppingList>> &userShoppingList);

};

#endif //LABORATORY_USER_H
