#include <iostream>
#include "ShoppingList.h"
#include "User.h"

int main() {
    User user1("Alice");
    User user2("Bob");

    ShoppingList list1("Groceries");
    ShoppingList list2("Household Items");
    ShoppingList list3("Office Supplies");

    user1.addList(&list1);
    user1.addList(&list2);
    user2.addList(&list2);
    user2.addList(&list3);

    Item item1("Apples", "Fruits", 5, 1.5);
    Item item2("Bread", "Groceries", 2, 2.0);
    Item item3("Milk", "Dairy", 1, 3.0);
    Item item4("Pasta", "Groceries", 3, 1.2);
    Item item5("Cheese", "Dairy", 2, 4.5);
    Item item6("Orange Juice", "Beverages", 1, 2.2);
    Item item7("Chicken", "Meat", 1, 6.0);
    Item item8("Rice", "Cereals", 4, 2.5);
    Item item9("Yogurt", "Dairy", 3, 1.8);
    Item item10("Lettuce", "Vegetables", 2, 2.7);
    Item item11("Tomatoes", "Vegetables", 4, 1.0);
    Item item12("Mineral Water", "Beverages", 6, 0.8);
    Item item13("Chocolate", "Sweets", 2, 3.5);
    Item item14("Coffee", "Beverages", 1, 5.0);
    Item item15("Salmon", "Fish", 1, 8.0);

    user1.add(&item1, &list1);
    user1.add(&item2, &list1);
    user1.add(&item3, &list1);
    user1.add(&item4, &list1);
    user1.add(&item5, &list1);
    user2.add(&item6, &list2);
    user2.add(&item7, &list2);
    user2.add(&item8, &list2);
    user2.add(&item9, &list2);
    user2.add(&item10, &list2);
    user1.add(&item11, &list3);
    user1.add(&item12, &list3);
    user2.add(&item13, &list3);
    user2.add(&item14, &list3);
    user2.add(&item15, &list3);

    user1.remove(&item1,&list1);
    

    return 0;
}
