#include "lfsr.hpp"
#include <intrin.h>

using namespace std;

lfsr_32::lfsr_32(int len, uint32_t poly):length(len),polynom(poly){}

void lfsr_32::set_register(uint32_t reg){
    l_register = reg;
}

bool lfsr_32::clock(){
    uint32_t mask;
    bool res;
    res = ((l_register>>(length-1))&1);
    mask = l_register&polynom;
    l_register = (l_register<<1)^(__popcnt(mask)&0x1);
    return res;
}