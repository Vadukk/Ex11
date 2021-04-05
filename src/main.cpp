// Copyright 2020 Vadukk
#include <iostream>
#include <string>

#include "train.h"

int main() {
    unsigned int seed = std::time(NULL);
    size_t num_train = rand_r(&seed) % 1000;
    Train MyTrain(num_train);

    MyTrain.print_cages_state();
    MyTrain.print_len();
    std::cout << std::endl;
    std::cout << "Gen len = " << num_train << std::endl;
    return 0;
}
