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
#include "list"

class ShoppingList : public ISubject {
private:
    string name;
    float totalPriceList = 0;
    float uncheckedPriceList = 0;
    float checkedPriceList = 0;
    multimap<string, shared_ptr<Item>> shoppingList;//contenitore per gli item
    list<IObserver *> userList;//lista utenti connessi alla lista
    vector<shared_ptr<Item>> checkedList;//lista item ultimati

public:
    ShoppingList(const string &n);

    void addItem(shared_ptr<Item> item);

    void removeItem(shared_ptr<Item> item);

    void infoShoppingList();

    void registerObserver(IObserver *observer) override;

    void unregisterObserver(IObserver *observer) override;

    void notify() override;

    void filterCategory(const string &c);

    const string &getName() const;
    float getTotalPriceList() const;
    float getUncheckedPriceList() const;
    void setUncheckedPriceList(float uncheckedPriceList);
    float getCheckedPriceList() const;
    void setCheckedPriceList(float checkedPriceList);
    void setTotalPriceList(float totalPriceList);
    const list<IObserver *> &getUserList() const;
};

#endif //LABORATORY_SHOPPINGLIST_H
