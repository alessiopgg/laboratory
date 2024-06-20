//
// Created by Alessio on 14/11/2023.
//

#include "Item.h"

Item::Item(const string &n, const string &c, int q, float p) : name(n), category(c), checked(false), quantity(q),
                                                               price(p) {
    if (q < 0 || p < 0) {
        quantity = abs(q);
        price = abs(p);
    }
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
        if (quantity<0) {
            quantity = abs(quantity);
        }
    this->quantity = quantity;
}

float Item::getPrice() const {
    return price;
}

void Item::setPrice(float price) {
    if (price < 0) {
        price = abs(price);
    }
    this->price = price;
}

bool Item::isChecked() const {
    return checked;
}

void Item::setChecked(bool checked) {
    Item::checked = checked;
}


