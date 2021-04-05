// Copyright 2021 Vadukk
#include <gtest/gtest.h>
#include <string>
#include <ctime>
#include "train.h"

TEST(CreateTest, test1) {
    Train test_train_1;
    EXPECT_EQ(0, test_train_1.len_of_train());
    Train test_train_2(5);
    EXPECT_EQ(5, test_train_2.len_of_train());
}

TEST(AddCageTest, test2) {
    Train test_train;
    test_train.add_new_cage(true);
    EXPECT_EQ(1, test_train.len_of_train());
    test_train.add_new_cage(false);
    EXPECT_EQ(true, test_train.getFirst()->get());
}

TEST(RoundTest, test3) {
    Train test_train(5);
    Cage* iter = test_train.getLast();
    if (iter->next == test_train.getFirst()) {
        EXPECT_EQ(1, 1);
    } else {
        EXPECT_EQ(0, 1);
    }
}

TEST(FindLenTest, test4) {
    unsigned int seed = std::time(NULL);
    size_t num_train = rand_r(&seed) % 1000;
    Train test_train(num_train);
    EXPECT_EQ(num_train, test_train.len_of_train());
}

TEST(LightTest, test5) {
    Train test_train;
    test_train.add_new_cage(true);
    EXPECT_EQ(true, test_train.getFirst()->get());
    test_train.getFirst()->off();
    EXPECT_EQ(false, test_train.getFirst()->get());
}
