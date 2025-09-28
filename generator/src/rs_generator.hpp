#pragma once

#include<iostream>

class rs_generator{
public:
    uint8_t clock();
};

class lehmer_32 final:public rs_generator{
private:
    uint32_t seed_a;
    uint32_t seed_c;
    bool low = true;
public:
    void set_seed(uint32_t a, uint32_t c);
    void change_mode();
    uint8_t clock();
};