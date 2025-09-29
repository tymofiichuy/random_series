#include "rs_generator.hpp"

using namespace std;

BM_generator::BM_generator(uint256_t s, bool b):byte(b),
                                                mod("0xCEA42B987C44FA642D80AD9F51F10457690DEF10C83D0BC1BCEE12FC3B6093E3"),
                                                base("0x5B88C41246790891C095E2878880342E88C79974303BD0400B090FE38A688356"),
                                                cmp_bit("0x675215CC3E227D3216C056CFA8F8822BB486F788641E85E0DE77097E1DB049F1"){
    cmp_byte = (mod-1)>>8;

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

void BM_generator::change_mode(){
    byte = !byte;
}

uint8_t BM_generator::clock(){
    if(byte){
        state = powm(base, state, mod);
        return (state/cmp_byte).convert_to<uint8_t>();        
    }
    else{
        uint8_t res = 0;
        for(int i = 7; i >= 0; i--){
            state = powm(base, state, mod);
            res ^= (state<cmp_bit)<<i;
        }
        return res;
    }
}

BBS_generator::BBS_generator(uint512_t s, bool b):byte(b),
                                                  mod("0x37682f6947aaab110517c20b76df64781da78b3e87eb58379085d3395793bdb9d9"){
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

void BBS_generator::change_mode(){
    byte = !byte;
}

uint8_t BBS_generator::clock(){
    if(byte){
        state = powm(state, 2, mod);
        return (state&0xFF).convert_to<uint8_t>();        
    }
    else{
        uint8_t res;
        for(int i = 7; i >= 0; i--){
            state = powm(state, 2, mod);
            res ^= (state.convert_to<uint8_t>()&1)<<i;
        }
        return res;
    }
}