//
// Created by Alessio on 15/11/2023.
//

#include "User.h"

User::User(string n) : name(n) {}

void User::addList(ShoppingList *shoppingList) {
    userShoppingList.insert(userShoppingList.cend(),shoppingList);
}

void User::update(int q,float p,string n) {
    cout<<"\nNotify! "<<n<<" has undergone a change."<<endl;

}

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

