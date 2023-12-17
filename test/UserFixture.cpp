//
// Created by Alessio on 20/11/2023.
//

#include "gtest/gtest.h"
#include "../User.h"

class UserFixture:public :: testing::Test{
protected:
    shared_ptr<User> user= make_shared<User>("Alice");
    shared_ptr<Item> item1=make_shared<Item>("Apple", "Fruit", 3, 1.5);
    shared_ptr<Item> item2=make_shared<Item>("Milk", "Dairy", 2, 2.0);
    shared_ptr<ShoppingList> shoppingList=make_shared<ShoppingList>("Groceries");
    shared_ptr<ShoppingList> shoppingList1= make_shared<ShoppingList>("Food");

    void SetUp() override {
        user->addList(shoppingList);
    }

    void TearDown()override{
        user->getUserShoppingList().empty();
    }
};

TEST_F(UserFixture,AddTest){
    user->add(item1,shoppingList);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),3*1.5);
    ASSERT_EQ(shoppingList->getTotalPriceList(),3*1.5);
    user->add(item2,shoppingList);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),3*1.5+4);
    ASSERT_EQ(shoppingList->getTotalPriceList(),3*1.5+4);
}

TEST_F(UserFixture,RemoveTest){
    user->add(item1,shoppingList);
    user->add(item2,shoppingList);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),3*1.5+4);
    user->remove(item1,shoppingList);
    ASSERT_EQ(shoppingList->getCheckedPriceList(),3*1.5);
    ASSERT_EQ(shoppingList->getUncheckedPriceList(),4);

}



