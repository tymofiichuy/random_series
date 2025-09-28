#include "rs_generator.hpp"

using namespace std;

lehmer_32::lehmer_32(uint32_t st, bool l):a(0x55555555),c(0x895), low(l),state(st){};

void lehmer_32::set_seed(uint32_t st){
    state = st;
}

void lehmer_32::change_mode(){
    low = !low;
}

uint8_t lehmer_32::clock(){
    state = a*state + c;
    if(low){
        return state&0xFF;
    }
    else{
        return state>>24;
    }
}