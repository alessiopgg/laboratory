//
// Created by Alessio on 17/11/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListFixture : public ::testing::Test{
protected:
    ShoppingList shoppingList;

    Item item1{"Apple", "Fruit", 3, 1.5};
    Item item2{"Milk", "Dairy", 2, 2};
    User user1{"Alice"};
    User user2{"Mario"};

    ShoppingListFixture() : shoppingList("Groceries") {
        shoppingList.registerObserver(&user1);
    }

    virtual void SetUp() override {
       shoppingList.addItem(&item1);
    }

    virtual void TearDown()override{
        shoppingList.removeItem(&item1);
    }
};

TEST_F(ShoppingListFixture ,RegisterObserverTest){
    shoppingList.registerObserver(&user2);
    ASSERT_EQ(shoppingList.userListSize(),2);
}

TEST_F(ShoppingListFixture ,UnRegisterObserverTest){
    shoppingList.unregisterObserver(&user2);
    ASSERT_EQ(shoppingList.userListSize(),1);
}

TEST_F(ShoppingListFixture,TotalQuantityTest){
    ASSERT_EQ(shoppingList.totalQuantityList(),3);
    shoppingList.addItem(&item2);
    ASSERT_EQ(shoppingList.totalQuantityList(),5);
}

TEST_F(ShoppingListFixture,TotalPriceTest){
    ASSERT_EQ(shoppingList.totalPriceList(),1.5);
    shoppingList.addItem(&item2);
    ASSERT_EQ(shoppingList.totalPriceList(),3.5);
}
