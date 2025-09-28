#include "lfsr.hpp"

using namespace std;

lfsr_128::lfsr_128(int len, uint128_t poly):length(len),polynom(poly){}

void lfsr_128::set_register(uint128_t reg){
    l_register = reg;
}

bool lfsr_128::clock(){
    uint128_t bit = 0x1;
    bool next = 0, res;
    for(int i = 0; i < length; i++){
        next ^= ((l_register&bit)!=0)&&((polynom&bit)!=0);
        bit <<= 1;
    }
    res = ((l_register&(0x1<<(length-1)))!=0);
    l_register <<= 1;
    l_register ^= static_cast<uint128_t>(next);
    return res;
}