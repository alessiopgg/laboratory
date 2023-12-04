//
// Created by Alessio on 14/11/2023.
//

#ifndef LABORATORY_SHOPPINGLIST_H
#define LABORATORY_SHOPPINGLIST_H

#include<iostream>
#include "Item.h"
#include "ISubject.h"
#include<map>
#include <memory>
#include "vector"

class ShoppingList: public ISubject{
private:
    string name;
    float totalPriceList=0;
    float uncheckedPriceList=0;
    float checkedPriceList=0;
    multimap<string,shared_ptr<Item>>shoppingList;
    multimap<string,IObserver *>userList;
    vector<shared_ptr<Item>>checkedList;

public:
    ShoppingList(string n);

    void addItem(shared_ptr<Item> item);
    void removeItem(shared_ptr<Item> item);
    void infoShoppingList();
    void registerObserver(IObserver *observer) override;
    void unregisterObserver(IObserver *observer) override;
    void notify() override;
    void printUserList();
    void filterCategory(string c);

    const string &getName() const;
    void setName(const string &name);
    const multimap<string, IObserver *> &getUserList() const;
    void setUserList(const multimap<string, IObserver *> &userList);
    const multimap<string, shared_ptr<Item> > &getShoppingList() const;
    void setShoppingList(const multimap<string, shared_ptr<Item>> &shoppingList);
    float getTotalPriceList() const;
    float getUncheckedPriceList() const;
    void setUncheckedPriceList(float uncheckedPriceList);
    float getCheckedPriceList() const;
    void setCheckedPriceList(float checkedPriceList);
    void setTotalPriceList(float totalPriceList);
};

#endif //LABORATORY_SHOPPINGLIST_H
