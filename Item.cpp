//
// Created by Alessio on 14/11/2023.
//

#include "Item.h"

Item::Item(string n, string c, int q, float p):name(n),category(c),checked(false){
    try {
        if (q >= 0)
            quantity = q;
        else
            throw invalid_argument("quantity cannot have a negative value!");
        if (p >= 0)
            price = p;
        else
            throw invalid_argument("price cannot have a negative value!");
    }catch(const invalid_argument&e){
        cerr<<"Error creating "<<getName()<<": "<<e.what()<<endl;
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
    Item::quantity = quantity;
}

float Item::getPrice() const {
    return price;
}

void Item::setPrice(float price) {
    Item::price = price;
}

bool Item::isChecked() const {
    return checked;
}

void Item::setChecked(bool checked) {
    Item::checked = checked;
}


