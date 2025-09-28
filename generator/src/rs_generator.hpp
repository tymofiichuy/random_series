#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include "lfsr.hpp"

using boost::multiprecision::uint256_t;
using boost::multiprecision::uint512_t;
using boost::multiprecision::powm;
// using namespace std;

class rs_generator{
public:
    virtual uint8_t clock() = 0;
};

class lehmer_32 final:public rs_generator{
private:
    uint32_t a;
    uint32_t c;
    uint32_t state;
    bool low = true;
public:
    void set_seed(uint32_t st);
    void change_mode();
    uint8_t clock();

    lehmer_32(uint32_t st);
};

class L20 final:public rs_generator{
private:
    uint32_t seed;
    lfsr_32 lr;
public:
    void set_seed(uint32_t s);
    uint8_t clock();

    L20(uint32_t s);
};

class L89 final:public rs_generator{
private:
    uint128_t seed;
    lfsr_128 lr;
public:
    void set_seed(uint128_t s);
    uint8_t clock();

    L89(uint128_t s);
};

class Geffe final:public rs_generator{
private:
    uint32_t seed_r11;
    uint32_t seed_r9;
    uint32_t seed_r10;

    lfsr_32 r11;
    lfsr_32 r9;
    lfsr_32 r10;
public:
    void set_seed(uint32_t s11, uint32_t s9, uint32_t s10);
    uint8_t clock();

    Geffe(uint32_t s11, uint32_t s9, uint32_t s10);
};

class Wolfram final:public rs_generator{
private:
    uint32_t seed;
    uint32_t state;

    uint32_t right_c_shift_1();
    uint32_t left_c_shift_1();
public:
    void set_seed(uint32_t s);
    uint8_t clock();

    Wolfram(uint32_t s);
};

class Librarian final:public rs_generator{
private:
    //file name!
    std::string seed;
    std::ifstream str;
public:
    void set_seed(std::string s);
    void init();

    uint8_t clock();

    Librarian(std::string s);
};

class BM_generator final:public rs_generator{
private:
    uint256_t seed;
    uint256_t state;

    uint256_t mod;
    uint256_t base;
    uint256_t cmp;
public:
    void set_seed(uint256_t s);
    uint8_t clock();

    BM_generator(uint256_t s);
};

//0x37682f6947aaab110517c20b76df64781da78b3e87eb58379085d3395793bdb9d9
class BBS_generator final:public rs_generator{
private:
    uint512_t seed;
    uint512_t state;
    
    uint512_t mod;
public:
    void set_seed(uint512_t s);
    uint8_t clock();

    BBS_generator(uint512_t s);
};