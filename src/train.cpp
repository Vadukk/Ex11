// Copyright 2020 Vadukk

#include <iostream>

#include "train.h"


Train::Train() {
    this->first = nullptr;
    this->last = nullptr;
}

Train::Train(size_t n) {
    this->first = nullptr;
    this->last = nullptr;

    unsigned int seed = std::time(NULL);

    for (size_t i = 0; i < n; i++) {
        Cage* current_cage = new Cage;

        int state = rand_r(&seed) % 2;
        if (state == 1) {
            this->add_new_cage(true);
        } else {
            this->add_new_cage();
        }
    }
}

void Train::add_new_cage(bool light) {
    Cage* current_cage = new Cage;
    if (light == true) {
        current_cage->on();
    } else {
        current_cage->off();
    }

    if (this->first == nullptr) {
        this->first = current_cage;
        this->last = current_cage;
    }
    if (this->first == this->last) {
        this->last = current_cage;
        this->first->next = current_cage;
        this->first->prev = current_cage;
        this->last->next = this->first;
        this->last->prev = this->first;
    } else {
        current_cage->prev = this->last;
        this->last->next = current_cage;
        this->last = current_cage;
        this->first->prev = this->last;
        this->last->next = this->first;
    }
}

void Train::print_cages_state() {
    Cage* iter = this->first;
    size_t count = 1;
    while (iter != this->last) {
        std::cout << "Cage " << count << " is state - "
            << iter->get() << std::endl;
        count++;
        iter = iter->next;
    }
    std::cout << "Cage " << count << " is state - " << iter->get() << std::endl;
}

size_t Train::len_of_train() {
    size_t step = 0;
    Cage* iter_cage = this->first;
    if (iter_cage == nullptr) return 0;
    iter_cage->off();

    step++;
    while (true) {
        for (size_t i = 1; i <= step; i++) {
            iter_cage = iter_cage->next;
            iter_cage->on();
        }

        for (size_t i = 1; i <= step; i++) {
            iter_cage = iter_cage->prev;
        }

        if (iter_cage->get() == true) break;
        step++;
    }

    return step;
}

void Train::print_len() {
    std::cout << "I think len of train = " << this->len_of_train();
}
