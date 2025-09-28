#pragma once

#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::uint128_t;

class lfsr{
private:
    int length;
public:
    virtual bool clock();
};

class lfsr_32 final:public lfsr{
private:
    uint32_t l_register = 0;
    uint32_t polynom;
    int length;
public:
    void set_register(uint32_t reg);
    bool clock();

    lfsr_32(int len, uint32_t poly);
};

class lfsr_128 final:public lfsr{
private:
    uint128_t l_register = 0;
    uint128_t polynom;
    int length;
public:
    void set_register(uint128_t reg);
    bool clock();

    lfsr_128(int len, uint128_t poly);
};