//
// Created by Alessio on 15/11/2023.
//

#ifndef LABORATORY_USER_H
#define LABORATORY_USER_H
#include "ShoppingList.h"
#include <vector>

class User:public IObserver{
private:
    vector<ShoppingList*>userShoppingList;
    string name;
public:
    User(string n);

    void addList(ShoppingList *shoppingList);
    void update(int q,float p,string n)override;

    const string &getName() const;

    void setName(const string &name);
};


#endif //LABORATORY_USER_H
