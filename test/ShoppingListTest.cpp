//
// Created by Alessio on 17/11/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"


TEST(ShoppingListTest, ConstructorTest) { //test costruttore
    shared_ptr<ShoppingList> shoppingList=make_shared<ShoppingList>("Shopping List");
    ASSERT_EQ(shoppingList->getName(),"Shopping List");
}

TEST(ShoppingListTest, AddItemTest){
    shared_ptr<ShoppingList> shoppingList=make_shared<ShoppingList>("name");
    shared_ptr<Item> item=make_shared<Item>("nameItem","categoryItem",4,3);

    shoppingList->addItem(item);

    ASSERT_EQ(shoppingList->getUncheckedPriceList(),12);
    ASSERT_EQ(shoppingList->getCheckedPriceList(),0);
    ASSERT_EQ(shoppingList->getTotalPriceList(),12);
}

TEST(ShoppingListTest, RemoveItemTest){
    shared_ptr<ShoppingList> shoppingList=make_shared<ShoppingList>("name");
    shared_ptr<Item> item=make_shared<Item>("nameItem","categoryItem",4,3);

    shoppingList->addItem(item);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),12);
    shoppingList->removeItem(item);
    EXPECT_EQ(shoppingList->getTotalPriceList(),12);
    EXPECT_EQ(shoppingList->getUncheckedPriceList(),0);
    EXPECT_EQ(shoppingList->getCheckedPriceList(),12);
}