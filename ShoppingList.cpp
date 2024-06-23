//
// Created by Alessio on 14/11/2023.
//

#include <iomanip>
#include "ShoppingList.h"

ShoppingList::ShoppingList(const string &n) : name(n) {}

void ShoppingList::addItem(shared_ptr<Item> item) { //aggiunge un item alla lista
    shoppingList.emplace(make_pair(item->getName(), item));
    setTotalPriceList(getTotalPriceList() + item->getPrice() * item->getQuantity());
    setUncheckedPriceList(getUncheckedPriceList() + item->getPrice() * item->getQuantity());
    notify();
}

void ShoppingList::removeItem(shared_ptr<Item> item) { //rimuove un item dalla lista
    auto it = shoppingList.find(item->getName());
    if (it != shoppingList.end()) {
        shoppingList.erase(item->getName());
        item->setChecked(true);
        checkedList.push_back(item);//aggiungo alla lista degli spuntati
        setUncheckedPriceList(getUncheckedPriceList() - item->getPrice() * item->getQuantity());
        setCheckedPriceList(getCheckedPriceList() + item->getPrice() * item->getQuantity());
        notify();
    }
}


void ShoppingList::infoShoppingList() { //metodo per visualizzare la lista
    cout << "\n" << getName() << " [ ";
    for (const auto &user: userList) {
        cout << user->getUsername() << " ";
    }
    cout << "]" << endl << left << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << endl;

    cout << string(60, '-') << endl;

    for (const auto &item: shoppingList) {
        cout << setw(20) << item.second->getName()
             << setw(15) << item.second->getCategory()
             << setw(10) << item.second->getQuantity()
             << setw(10) << item.second->getPrice() * item.second->getQuantity() << endl;
    }
    cout << string(60, '-') << endl;

    cout << "Unchecked:" << getUncheckedPriceList() << setw(10) << "$" <<
         "Checked:" << getCheckedPriceList() << setw(10) << "$";
    cout << "Total price:" << getTotalPriceList() << "$" << endl << "\n";

    for (auto itemC: checkedList) {
        cout << "X ";
        cout << setw(20) << itemC->getName()
             << setw(15) << itemC->getCategory()
             << setw(10) << itemC->getQuantity()
             << setw(10) << itemC->getPrice() * itemC->getQuantity() << endl;
    }
    cout << "\n\n";

}

void ShoppingList::registerObserver(IObserver *observer) {
    userList.push_back(observer);
}

void ShoppingList::unregisterObserver(IObserver *observer) {
    userList.remove(observer);
}

void ShoppingList::notify() {
    auto i = userList.end(); //notifica tutti gli utenti iscritti alla lista
    for (auto o: userList)
        o->update();

}

void ShoppingList::filterCategory(const string &c) {
    cout << "\n" << getName() << " [ ";
    for (const auto &user: userList) {
        cout << user->getUsername() << " ";
    }
    cout << "]" << " Filter by " << c << ":" << endl << left << setw(20) << "Name"
         << setw(15) << "Category"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << endl;

    cout << string(60, '-') << endl;
    for (const auto &item: shoppingList) {
        if (item.second->getCategory() == c) {
            cout << setw(20) << item.second->getName()
                 << setw(15) << item.second->getCategory()
                 << setw(10) << item.second->getQuantity()
                 << setw(10) << item.second->getPrice() * item.second->getQuantity() << endl;
        }
    }
    for (auto itemC: checkedList) {
        if (itemC->getCategory() == c) {
            cout << "X ";
            cout << setw(20) << itemC->getName()
                 << setw(15) << itemC->getCategory()
                 << setw(10) << itemC->getQuantity()
                 << setw(10) << itemC->getPrice() * itemC->getQuantity() << endl;
        }
    }
    cout << string(60, '-') << endl;

}

const string &ShoppingList::getName() const {
    return name;
}

float ShoppingList::getTotalPriceList() const {
    return totalPriceList;
}

void ShoppingList::setTotalPriceList(float totalPriceList) {
    ShoppingList::totalPriceList = totalPriceList;
}

float ShoppingList::getUncheckedPriceList() const {
    return uncheckedPriceList;
}

void ShoppingList::setUncheckedPriceList(float uncheckedPriceList) {
    ShoppingList::uncheckedPriceList = uncheckedPriceList;
}

float ShoppingList::getCheckedPriceList() const {
    return checkedPriceList;
}

void ShoppingList::setCheckedPriceList(float checkedPriceList) {
    ShoppingList::checkedPriceList = checkedPriceList;
}

const list<IObserver *> &ShoppingList::getUserList() const {
    return userList;
}



