#include <iostream>
#include "ShoppingList.h"
#include "User.h"

int main() {
    shared_ptr<User>user1= make_shared<User>("Alice");
    shared_ptr<User>user2= make_shared<User>("Carl");

    shared_ptr<ShoppingList>list1= make_shared<ShoppingList>("Groceries");
    shared_ptr<ShoppingList>list2= make_shared<ShoppingList>("Household Item");
    shared_ptr<ShoppingList>list3= make_shared<ShoppingList>("Office Supplies");

    user1->addList(list1);
    user1->addList(list2);
    user2->addList(list2);
    user2->addList(list3);

    shared_ptr<Item> item1 = make_shared<Item>("Apples", "Fruits", 5, 1.5);
    shared_ptr<Item> item2 = make_shared<Item>("Bread", "Groceries", 2, 2.0);
    shared_ptr<Item> item3 = make_shared<Item>("Milk", "Dairy", 1, 3.0);
    shared_ptr<Item> item4 = make_shared<Item>("Pasta", "Groceries", 3, 1.2);
    shared_ptr<Item> item5 = make_shared<Item>("Cheese", "Dairy", 2, 4.5);
    shared_ptr<Item> item6 = make_shared<Item>("Orange Juice", "Beverages", 1, 2.2);
    shared_ptr<Item> item7 = make_shared<Item>("Chicken", "Meat", 1, 6.0);
    shared_ptr<Item> item8 = make_shared<Item>("Rice", "Cereals", 4, 2.5);
    shared_ptr<Item> item9 = make_shared<Item>("Yogurt", "Dairy", 3, 1.8);
    shared_ptr<Item> item10 = make_shared<Item>("Lettuce", "Vegetables", 2, 2.7);
    shared_ptr<Item> item11 = make_shared<Item>("Tomatoes", "Vegetables", 4, 1.0);
    shared_ptr<Item> item12 = make_shared<Item>("Mineral Water", "Beverages", 6, 0.8);
    shared_ptr<Item> item13 = make_shared<Item>("Chocolate", "Sweets", 2, 3.5);
    shared_ptr<Item> item14 = make_shared<Item>("Coffee", "Beverages", 1, 5.0);
    shared_ptr<Item> item15 = make_shared<Item>("Salmon", "Fish", 1, 8.0);
    
    user1->add(item1, list1);
    user1->add(item2, list1);
    user1->add(item3, list1);
    user1->add(item4, list1);
    user1->add(item5, list1);
    user2->add(item6, list2);
    user2->add(item7, list2);
    user2->add(item8, list2);
    user2->add(item9, list2);
    user2->add(item10, list2);
    user1->add(item11, list3);
    user1->add(item12, list3);
    user2->add(item13, list3);
    user2->add(item14, list3);
    user2->add(item15, list3);

    user1->remove(item1,list1);
    user2->remove(item7, list2);

    user1->filterList("Vegetables",list2);

    return 0;
}
