//
// Created by Alessio on 15/11/2023.
//

#include "User.h"

User::User(string n) : username(n) {}

void User::addList(ShoppingList *shoppingList) {
    userShoppingList.emplace(make_pair(shoppingList->getName(),shoppingList));
    shoppingList->registerObserver(this);
}

void User::update(int q,float p,string n) {
    cout<<"\n("<<getUsername()<<") Notice! "<<n<<" changed."<<endl;
    for(auto l:userShoppingList){
        if(n==l.first)
            l.second->infoShoppingList();
    }
}

void User::add(Item *item, ShoppingList *shoppingList) {
    for(auto s:userShoppingList){
        if(s.first==shoppingList->getName())
            shoppingList->addItem(item);
    }
}

void User::remove(Item *item, ShoppingList *shoppingList) {
    for(auto s:userShoppingList){
        if(s.first==shoppingList->getName())
            shoppingList->removeItem(item);
    }
}

string User::getUsername() {
    return username;
}

void User::setUsername(const string &username) {
    User::username = username;
}

const multimap<string, ShoppingList *> &User::getUserShoppingList() const {
    return userShoppingList;
}

void User::setUserShoppingList(const multimap<string, ShoppingList *> &userShoppingList) {
    User::userShoppingList = userShoppingList;
}

