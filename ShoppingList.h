//
// Created by Alessio on 14/11/2023.
//

#ifndef LABORATORY_SHOPPINGLIST_H
#define LABORATORY_SHOPPINGLIST_H

#include<iostream>
#include "Item.h"
#include "ISubject.h"
#include<map>


class ShoppingList: public ISubject{
private:
    string name;
    multimap<int,Item *>shoppingList;
    multimap<string,IObserver *>userList;
public:
    ShoppingList(string n);

    void addItem(Item *item);


};


#endif //LABORATORY_SHOPPINGLIST_H
