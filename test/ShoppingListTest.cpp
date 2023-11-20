//
// Created by Alessio on 17/11/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"


TEST(ShoppingListTest, ConstructorTest) { //test costruttore
    ShoppingList shoppingList("Shopping List");
    ASSERT_EQ(shoppingList.getName(),"Shopping List");
}

TEST(ShoppingListTest, AddItemTest){
    ShoppingList shoppingList("name");
    Item item("nameItem","categoryItem",4,3);

    shoppingList.addItem(&item);

    ASSERT_EQ(shoppingList.totalQuantityList(),4);
    ASSERT_EQ(shoppingList.totalPriceList(),3);
}

TEST(ShoppingListTest, RemoveItemTest){
    ShoppingList shoppingList("name");
    Item item("nameItem","categoryItem",4,3);

    shoppingList.addItem(&item);
    shoppingList.removeItem(&item);

    EXPECT_EQ(shoppingList.totalQuantityList(),0);
    EXPECT_EQ(shoppingList.totalPriceList(),0);
}