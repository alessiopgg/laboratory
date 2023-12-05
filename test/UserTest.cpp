//
// Created by Alessio on 17/11/2023.
//

#include "gtest/gtest.h"
#include "../User.h"

TEST(UserTest,ConstructorTest) {
    shared_ptr<User> user = make_shared<User>("userName");
    ASSERT_EQ(user->getUsername(), "userName");
}
