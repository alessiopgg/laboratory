//
// Created by Alessio on 17/11/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListFixture : public ::testing::Test{
protected:
    shared_ptr<ShoppingList> shoppingList= make_shared<ShoppingList>("Groceries");

    shared_ptr<Item> item1=make_shared<Item>("Apple", "Fruit", 3, 1.5);
    shared_ptr<Item> item2=make_shared<Item>("Milk", "Dairy", 2, 2);
    shared_ptr<User> user1=make_shared<User>("Alice");
    shared_ptr<User> user2=make_shared<User>("Mario");


    void SetUp() override {
        shoppingList->registerObserver(user1.get());
        shoppingList->addItem(item1);
    }

    void TearDown()override{
        shoppingList->removeItem(item1);
    }
};

TEST_F(ShoppingListFixture ,RegisterObserverTest){
    shoppingList->registerObserver(user2.get());
    ASSERT_EQ(shoppingList->getUserList().size(),2);
}

TEST_F(ShoppingListFixture ,UnRegisterObserverTest){
    shoppingList->registerObserver(user2.get());
    shoppingList->unregisterObserver(user2.get());
    ASSERT_EQ(shoppingList->getUserList().size(),1);
}

TEST_F(ShoppingListFixture,PriceTest){
    ASSERT_EQ(shoppingList->getTotalPriceList(),3*1.5);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),3*1.5);
    ASSERT_EQ(shoppingList->getCheckedPriceList(),0);

    shoppingList->addItem(item2);
    ASSERT_EQ(shoppingList->getTotalPriceList(),3*1.5+4);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),3*1.5+4);
    ASSERT_EQ(shoppingList->getCheckedPriceList(),0);

    shoppingList->removeItem(item2);
    ASSERT_EQ(shoppingList->getTotalPriceList(),3*1.5+4);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),3*1.5);
    ASSERT_EQ(shoppingList->getCheckedPriceList(),4);

}

