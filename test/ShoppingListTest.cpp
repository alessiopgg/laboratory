//
// Created by Alessio on 17/11/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"


TEST(ShoppingListTest, ConstructorTest) { //test costruttore
    shared_ptr<ShoppingList> shoppingList = make_shared<ShoppingList>("Shopping List");
    ASSERT_EQ(shoppingList->getName(), "Shopping List");
}

TEST(ShoppingListTest, AddItemTest) {
    shared_ptr<ShoppingList> shoppingList = make_shared<ShoppingList>("name");
    shared_ptr<Item> item = make_shared<Item>("nameItem", "categoryItem", 4, 3);

    shoppingList->addItem(item);

    ASSERT_EQ(shoppingList->getUncheckedPriceList(), 12);
    ASSERT_EQ(shoppingList->getCheckedPriceList(), 0);
    ASSERT_EQ(shoppingList->getTotalPriceList(), 12);

    //test con valori limite
    shared_ptr<Item> item1 = make_shared<Item>("nameItem", "categoryItem", 0, 0);
    shoppingList->addItem(item1);

    ASSERT_EQ(shoppingList->getUncheckedPriceList(), 12);
    ASSERT_EQ(shoppingList->getCheckedPriceList(), 0);
    ASSERT_EQ(shoppingList->getTotalPriceList(), 12);

    //test con valori negativi
    shared_ptr<Item> item2 = make_shared<Item>("nameItem", "categoryItem", -2, -9);
    shoppingList->addItem(item2);

    ASSERT_EQ(shoppingList->getUncheckedPriceList(), 30);
    ASSERT_EQ(shoppingList->getCheckedPriceList(), 0);
    ASSERT_EQ(shoppingList->getTotalPriceList(), 30);

}

TEST(ShoppingListTest, RemoveItemTest) {
    shared_ptr<ShoppingList> shoppingList = make_shared<ShoppingList>("name");
    shared_ptr<Item> item = make_shared<Item>("nameItem", "categoryItem", 4, 3);

    shoppingList->addItem(item);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(), 12);
    shoppingList->removeItem(item);
    EXPECT_EQ(shoppingList->getTotalPriceList(), 12);
    EXPECT_EQ(shoppingList->getUncheckedPriceList(), 0);
    EXPECT_EQ(shoppingList->getCheckedPriceList(), 12);

    //test su item non presente nella lista
    shared_ptr<Item> item1 = make_shared<Item>("nameItem", "categoryItem", 4, 3);
    shoppingList->removeItem(item1);
    EXPECT_EQ(shoppingList->getTotalPriceList(), 12);
    EXPECT_EQ(shoppingList->getUncheckedPriceList(), 0);
    EXPECT_EQ(shoppingList->getCheckedPriceList(), 12);


}