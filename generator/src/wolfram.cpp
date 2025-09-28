#include "rs_generator.hpp"

using namespace std;

Wolfram::Wolfram(uint32_t s):seed(s){
    state = seed;
};

void Wolfram::set_seed(uint32_t s){
    seed = s;
    state = seed;
}

uint32_t Wolfram::right_c_shift_1(){
    return (state>>1)|(state<<31);
}

uint32_t Wolfram::left_c_shift_1(){
    return (state<<1)|(state>>31);
}

uint8_t Wolfram::clock(){
    uint8_t res = 0;
    for(int i = 7; i >= 0; i--){
        state = left_c_shift_1()^(state|right_c_shift_1());        
        res ^= (static_cast<uint8_t>(state&1)<<i);
    }
    return res;
}