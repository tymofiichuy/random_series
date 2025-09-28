#include "rs_generator.hpp"

using namespace std;

BM_generator::BM_generator(uint256_t s):mod("0xCEA42B987C44FA642D80AD9F51F10457690DEF10C83D0BC1BCEE12FC3B6093E3"),
                                        base("0x5B88C41246790891C095E2878880342E88C79974303BD0400B090FE38A688356"){
    cmp = (mod-1)>>8;

    if(s>mod){
        seed = 2;
        cerr << "Unable to set the seed, default one will be used";
    }
    else{
        seed = s;
    }
    state = seed;
}

void BM_generator::set_seed(uint256_t s){
    if(s>mod){
        seed = 2;
        cerr << "Unable to set the seed, default one will be used";
    }
    else{
        seed = s;
    }
    state = seed;
}

uint8_t BM_generator::clock(){
    state = powm(base, state, mod);
    return (state/cmp).convert_to<uint8_t>();
}

BBS_generator::BBS_generator(uint512_t s):mod("0x37682f6947aaab110517c20b76df64781da78b3e87eb58379085d3395793bdb9d9"){
    if(s>mod){
        seed = 2;
        cerr << "Unable to set the seed, default one will be used";
    }
    else{
        seed = s;
    }
    state = seed;
}

void BBS_generator::set_seed(uint512_t s){
    if(s>mod){
        seed = 2;
        cerr << "Unable to set the seed, default one will be used";
    }
    else{
        seed = s;
    }
    state = seed;
}

uint8_t BBS_generator::clock(){
    state = powm(state, 2, mod);
    return (state&0xFF).convert_to<uint8_t>();
}