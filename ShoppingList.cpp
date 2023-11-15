//
// Created by Alessio on 14/11/2023.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(string n):name(n) {}

void ShoppingList::addItem(Item *item) {
    shoppingList.emplace(make_pair(item->getQuantity(), item));
    notify();
}
int ShoppingList::totalQuantityList() {
    setTotalQuantity(0);
    for (auto item:shoppingList) {
        setTotalQuantity(getTotalQuantity()+item.second->getQuantity());
    }
    return getTotalQuantity();
}

float ShoppingList::totalPriceList() {
    setTotalPrice(0);
    for (auto item:shoppingList) {
        setTotalPrice(getTotalPrice()+item.second->getPrice());
    }
    return getTotalPrice();
}


void ShoppingList::registerObserver(IObserver *observer) {
    userList.insert(make_pair(observer->getUsername(), observer));
}

void ShoppingList::unregisterObserver(IObserver *observer) {
    userList.erase(observer->getUsername());

}

void ShoppingList::notify() {
    auto i=userList.end();
    for(auto o: userList)
        o.second->update(totalQuantityList(),totalPriceList(),getName());

}

const string &ShoppingList::getName() const {
    return name;
}

void ShoppingList::setName(const string &name) {
    ShoppingList::name = name;
}

int ShoppingList::getTotalQuantity() const {
    return totalQuantity;
}

void ShoppingList::setTotalQuantity(int totalQuantity) {
    ShoppingList::totalQuantity = totalQuantity;
}

float ShoppingList::getTotalPrice() const {
    return totalPrice;
}

void ShoppingList::setTotalPrice(float totalPrice) {
    ShoppingList::totalPrice = totalPrice;
}



