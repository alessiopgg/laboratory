//
// Created by Alessio on 15/11/2023.
//

#include "User.h"

User::User(const string &n) : username(n) {}

void User::addList(shared_ptr<ShoppingList>shoppingList) { //metodo con cui user può aggiungersi alla lista
    userShoppingList.emplace(make_pair(shoppingList->getName(),shoppingList));
    shoppingList->registerObserver(this);
}

void User::update() {
    cout<<"\n("<<getUsername()<<") Notice! "<<endl;
}

void User::add(shared_ptr<Item>item, shared_ptr<ShoppingList>shoppingList) { //metodo con cui user può aggiungere un item
    for(auto s:userShoppingList){
        if(s.first==shoppingList->getName())//verifica che sia iscritto alla lista
            shoppingList->addItem(item);
    }
}

void User::remove(shared_ptr<Item>item, shared_ptr<ShoppingList>shoppingList) { //metodo per rimuovere un item
    for(auto s:userShoppingList){
        if(s.first==shoppingList->getName()) {
            shoppingList->removeItem(item);
        }
    }
}

void User::filterList(string c, shared_ptr<ShoppingList> shoppingList) {
    for (auto s: userShoppingList) {
        if (s.first == shoppingList->getName()) {
            shoppingList->filterCategory(c,getUsername());
        }
    }
}
void User::printList(shared_ptr<ShoppingList> shoppingList) {
    for (auto s: userShoppingList) {
        if (s.first == shoppingList->getName()) {
            shoppingList->infoShoppingList(getUsername());
        }
    }
}

void User::setUsername(const string &username) {
    User::username = username;
}

const multimap<string, shared_ptr<ShoppingList>> &User::getUserShoppingList() const {
    return userShoppingList;
}

void User::setUserShoppingList(const multimap<string, shared_ptr<ShoppingList>> &userShoppingList) {
    User::userShoppingList = userShoppingList;
}

const string &User::getUsername() const {
    return username;
}




