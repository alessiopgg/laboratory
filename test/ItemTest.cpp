//
// Created by Alessio on 20/11/2023.
//

#include "gtest/gtest.h"
#include "../Item.h"
#include <memory>

TEST(ItemTest,ConstructorTest){ //test costruttore
    shared_ptr<Item>item=make_shared<Item>("name","category",5,7);
    EXPECT_EQ(item->getName(),"name");
    EXPECT_EQ(item->getCategory(),"category");
    EXPECT_EQ(item->getQuantity(),5);
    EXPECT_EQ(item->getPrice(),7);
    EXPECT_EQ(item->isChecked(), false);

    //test per valori negativi
    shared_ptr<Item>item1=make_shared<Item>("name","category",-5,-7);
    EXPECT_EQ(item1->getQuantity(),5);
    EXPECT_EQ(item1->getPrice(),7);

}

TEST(ItemTest,SetTest){ //test setMethod
    shared_ptr<Item>item=make_shared<Item>("name","category",5,7);

    item->setName("apple");
    EXPECT_EQ(item->getName(),"apple");

    item->setCategory("fruit");
    EXPECT_EQ(item->getCategory(),"fruit");

    item->setQuantity(23);
    EXPECT_EQ(item->getQuantity(),23);

    item->setPrice(29);
    EXPECT_EQ(item->getPrice(), 29);

    //test con valori negativi
    item->setQuantity(-23);
    EXPECT_EQ(item->getQuantity(), 23);

    item->setPrice(-29);
    EXPECT_EQ(item->getPrice(), 29);

    item->setQuantity(-5);
    EXPECT_EQ(item->getQuantity(), 5);

    item->setQuantity(0);
    EXPECT_EQ(item->getQuantity(), 0);

    item->setPrice(0);
    EXPECT_EQ(item->getPrice(), 0);

    item->setChecked(true);
    EXPECT_EQ(item->isChecked(), true);

}