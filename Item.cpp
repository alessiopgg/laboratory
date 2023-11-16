//
// Created by Alessio on 14/11/2023.
//

#include "Item.h"

Item::Item(string n, string c, int q, float p):name(n),category(c),quantity(q),price(p){}

void Item::infoItem() {
    cout<<getName()<<" ("<<getCategory()<<", "<<getQuantity()<<", "<<getPrice()<<") "<<endl;
}

const string &Item::getName() const {
    return name;
}

void Item::setName(const string &name) {
    Item::name = name;
}

const string &Item::getCategory() const {
    return category;
}

void Item::setCategory(const string &category) {
    Item::category = category;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int quantity) {
    Item::quantity = quantity;
}

float Item::getPrice() const {
    return price;
}

void Item::setPrice(float price) {
    Item::price = price;
}


