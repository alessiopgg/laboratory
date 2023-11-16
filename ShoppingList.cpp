//
// Created by Alessio on 14/11/2023.
//

#include <iomanip>
#include "ShoppingList.h"

ShoppingList::ShoppingList(string n):name(n) {}

void ShoppingList::addItem(Item *item) {
    shoppingList.emplace(make_pair(item->getName(), item));
    notify();
}

void ShoppingList::removeItem(Item *item) {
    shoppingList.erase(item->getName());
    notify();
}
int ShoppingList::totalQuantityList() {
    int s=0;
    for (auto item:shoppingList) {
        s+=item.second->getQuantity();
    }
    setTotalQuantity(s);
    return getTotalQuantity();
}

float ShoppingList::totalPriceList() {
    setTotalPrice(0);
    for (auto item:shoppingList) {
        setTotalPrice(getTotalPrice()+item.second->getPrice());
    }
    return getTotalPrice();
}

void ShoppingList::infoShoppingList() {
    cout<<"\n"<<getName()<<" [ ";
    printUserList();
    cout<<"]"<<endl << left << setw(20) << "Name"
              << setw(15) << "Category"
              << setw(10) << "Quantity"
              << setw(10) << "Price" << endl;

    cout << string(60, '-') <<endl;

    for (const auto& item : shoppingList) {
        cout << setw(20) << item.second->getName()
                  << setw(15) << item.second->getCategory()
                  << setw(10) << item.second->getQuantity()
                  << setw(10) << item.second->getPrice() << endl;
    }
    cout << string(60, '-') <<endl;

    cout<<"Total quantity: "<<setw(15)<<totalQuantityList();
    cout<<"Total price: "<<totalPriceList()<<"$"<<endl<<"\n\n";


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

void ShoppingList::printUserList() {
    for(auto u:userList)
        cout<<u.first<<" ";
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
