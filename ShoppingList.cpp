//
// Created by Alessio on 14/11/2023.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(string n):name(n) {}

void ShoppingList::addItem(Item *item) {
    shoppingList.emplace(make_pair(item->getQuantity(), item));
    notify();
}
