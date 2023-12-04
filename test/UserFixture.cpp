//
// Created by Alessio on 20/11/2023.
//

#include "gtest/gtest.h"
#include "../User.h"

class UserFixture:public :: testing::Test{
protected:
    User user;
    Item item1{"Apple", "Fruit", 3, 1.5};
    Item item2{"Milk", "Dairy", 2, 2.0};
    ShoppingList shoppingList;
    ShoppingList shoppingList1;

    UserFixture() : user("Alice"), shoppingList("Groceries") , shoppingList1("Food"){}


    virtual void SetUp() override {
        user.addList(&shoppingList);
    }


    virtual void TearDown()override{
        user.getUserShoppingList().empty();
    }
};

TEST_F(UserFixture,AddListTest){//delete
    ASSERT_EQ(user.getUserShoppingList().size(),1);
    user.addList(&shoppingList1);
    ASSERT_EQ(user.getUserShoppingList().size(),2);
}

TEST_F(UserFixture,AddTest){
    user.add(&item1,&shoppingList);
    ASSERT_EQ(shoppingList.getTotalQuantity(),3);
    ASSERT_EQ(shoppingList.getShoppingList().size(),1);
    user.add(&item2,&shoppingList);
    ASSERT_EQ(shoppingList.getTotalQuantity(),5);
    ASSERT_EQ(shoppingList.getShoppingList().size(),2);
}

TEST_F(UserFixture,RemoveTest){
    user.add(&item1,&shoppingList);
    user.remove(&item2,&shoppingList);
    ASSERT_EQ(shoppingList.getShoppingList().size(),1);
    user.remove(&item1,&shoppingList);
    ASSERT_EQ(shoppingList.getShoppingList().size(),0);

}



