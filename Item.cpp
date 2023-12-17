//
// Created by Alessio on 14/11/2023.
//

#include "Item.h"

Item::Item(const string &n, const string &c, int q, float p):name(n),category(c),checked(false){
    try{
    if (q < 0 || p < 0) {
        throw invalid_argument("Quantity and price cannot have negative values!");
    }
    else{
        quantity = q;
        price = p;
    }
        }catch(const invalid_argument&e) {
                cout << "\nInvalid argument for " << getName() << "! Converted into absolute value..." << endl;
                quantity=abs(q);
                price=abs(p);

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
    try{
        if (quantity<0) {
            throw invalid_argument("Quantity cannot have negative values!");
        }
        else{
            Item::quantity = quantity;
        }
    }catch(const invalid_argument&e) {
        cout << "\nInvalid argument for " << getName() << "! Converted into absolute value..." << endl;
        Item::quantity = abs(quantity);    }
}

float Item::getPrice() const {
    return price;
}

void Item::setPrice(float price) {
    try{
        if (price<0) {
            throw invalid_argument("Price cannot have negative values!");
        }
        else{
            Item::price = price;
        }
    }catch(const invalid_argument&e) {
        cout << "\nInvalid argument for " << getName() << "! Converted into absolute value..." << endl;
        Item::price = abs(price);
    }
}

bool Item::isChecked() const {
    return checked;
}

void Item::setChecked(bool checked) {
    Item::checked = checked;
}


