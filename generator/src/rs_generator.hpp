#pragma once

#include<iostream>
#include<string>
#include "lfsr.hpp"

using namespace std;

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

class L20 final:public rs_generator{
private:
    uint32_t seed;
    lfsr_32 lr;
public:
    void set_seed(uint32_t seed);
    uint8_t clock();
};

class L89 final:public rs_generator{
private:
    uint128_t seed;
    lfsr_128 lr;
public:
    void set_seed(uint128_t seed);
    uint8_t clock();
};

class Geffe final:public rs_generator{
private:
    uint32_t seed_r1;
    uint32_t seed_r2;
    uint32_t seed_r3;
public:
    void set_seed(uint32_t r1, uint32_t r2, uint32_t r23);
    uint8_t clock();
};

class Wolfram final:public rs_generator{
private:
    uint32_t seed;
    uint32_t state;
public:
    void set_seed(uint32_t seed);
    uint8_t clock();
};

class Librarian final:public rs_generator{
private:
    //file name!
    string seed;
public:
    void set_seed(string seed);
    uint8_t clock();
};