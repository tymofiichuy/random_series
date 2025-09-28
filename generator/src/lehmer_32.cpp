#include "rs_generator.hpp"

using namespace std;

lehmer_32::lehmer_32(uint32_t a, uint32_t c, uint32_t st):seed_a(a),seed_c(c),state(st){};

void lehmer_32::set_seed(uint32_t a, uint32_t c, uint32_t st){
    seed_a = a;
    seed_c = c;
    state = st;
}

void lehmer_32::change_mode(){
    low = !low;
}

uint8_t lehmer_32::clock(){
    state = seed_a*state + seed_c;
    if(low){
        return state&0xFF;
    }
    else{
        return state>>24;
    }
}