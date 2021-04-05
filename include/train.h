// Copyright 2020 Vadukk
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <ctime>


class Cage;

class Train {
 private:
    Cage* first;
    Cage* last;

 public:
    Train();
    explicit Train(size_t n);

    void add_new_cage(bool light = false);
    void print_cages_state();
    size_t len_of_train();
    void print_len();
    Cage* getFirst() {
        return first;
    }

    Cage* getLast() {
        return last;
    }
};

class Cage {
 private:
    bool light;

 public:
    Cage* next;
    Cage* prev;
    Cage() : light(false), next(nullptr), prev(nullptr) {}
    void on() { light = true; }
    void off() { light = false; }
    bool get() const { return light; }
};

#endif  // INCLUDE_TRAIN_H_
