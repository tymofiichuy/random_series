#include "rs_generator.hpp"

using namespace std;

L20::L20(uint32_t s):lr(20,0x80114),seed(s){};

void L20::set_seed(uint32_t s){
    seed = s;
}

uint8_t L20::clock(){
    lr.set_register(seed);
    uint8_t res = 0;
    for(int i = 7; i >= 0; i--){
        res ^= (static_cast<uint8_t>(lr.clock())<<i);
    }
    return res;
};

L89::L89(uint128_t s):lr(89,uint128_t("0x00000000000000000008000000000001")),seed(s){};

void L89::set_seed(uint128_t s){
    seed = s;
}

uint8_t L89::clock(){
    lr.set_register(seed);
    uint8_t res = 0;
    for(int i = 7; i >= 0; i--){
        res ^= (static_cast<uint8_t>(lr.clock())<<i);
    }
    return res;
};

Geffe::Geffe(uint32_t s11, uint32_t s9, uint32_t s10):seed_r11(s11),seed_r9(s9),seed_r10(s10),
                                                    r11(11,0x500), r9(9,0x1B0), r10(10,0x240){};

void Geffe::set_seed(uint32_t s11, uint32_t s9, uint32_t s10){
    seed_r11 = s11;
    seed_r9 = s9;
    seed_r10 = s10;
}

uint8_t Geffe::clock(){
    r11.set_register(seed_r11);
    r9.set_register(seed_r9);
    r10.set_register(seed_r10);

    uint8_t res = 0;
    bool x, y, s;
    for(int i = 7; i >= 0; i--){
        x = r11.clock(), y = r9.clock(), s = r10.clock();
        res ^= (static_cast<uint8_t>(((s&&x)^((!s)&&y)))<<i);
    }
    return res;
}