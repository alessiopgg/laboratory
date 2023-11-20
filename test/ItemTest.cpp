//
// Created by Alessio on 20/11/2023.
//

#include "gtest/gtest.h"
#include "../Item.h"

TEST(ItemTest,ConstructorTest){
    Item item("name","category",5,7);
    EXPECT_EQ(item.getName(),"name");
    EXPECT_EQ(item.getCategory(),"category");
    EXPECT_EQ(item.getQuantity(),5);
    EXPECT_EQ(item.getPrice(),7);

}

TEST(ItemTest,SetTest){
    Item item("name","category",5,7);

    item.setName("apple");
    EXPECT_EQ(item.getName(),"apple");

    item.setCategory("fruit");
    EXPECT_EQ(item.getCategory(),"fruit");

    item.setQuantity(23);
    EXPECT_EQ(item.getQuantity(),23);

    item.setPrice(29);
    EXPECT_EQ(item.getPrice(),29);

}