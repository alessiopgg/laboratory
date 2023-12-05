//
// Created by Alessio on 14/11/2023.
//

#ifndef LABORATORY_ITEM_H
#define LABORATORY_ITEM_H

#include<iostream>
using namespace std;
//classe che rappresenta un elemento
class Item {
private:
    string name;
    string category;
    int quantity=0;
    float price=0;
    bool checked;
public:
    Item(string n, string c, int q, float p);

    const string &getName() const;
    void setName(const string &name);
    const string &getCategory() const;
    void setCategory(const string &category);
    int getQuantity() const;
    void setQuantity(int quantity);
    float getPrice() const;
    void setPrice(float price);
    bool isChecked() const;
    void setChecked(bool checked);
};

#endif //LABORATORY_ITEM_H
