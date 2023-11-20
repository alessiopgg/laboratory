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
    int totalQuantity;
    float totalPrice;
    multimap<string,Item *>shoppingList;
    multimap<string,IObserver *>userList;
public:
    ShoppingList(string n);

    void addItem(Item *item);
    void removeItem(Item *item);
    int totalQuantityList();
    float totalPriceList();
    void infoShoppingList();

    void registerObserver(IObserver *observer) override;
    void unregisterObserver(IObserver *observer) override;
    void notify() override;
    void printUserList();
    int userListSize();

    const string &getName() const;
    void setName(const string &name);
    int getTotalQuantity() const;
    void setTotalQuantity(int totalQuantity);
    float getTotalPrice() const;
    void setTotalPrice(float totalPrice);
    const multimap<string, IObserver *> &getUserList() const;
    void setUserList(const multimap<string, IObserver *> &userList);

    const multimap<string, Item *> &getShoppingList() const;

    void setShoppingList(const multimap<string, Item *> &shoppingList);
};

#endif //LABORATORY_SHOPPINGLIST_H
