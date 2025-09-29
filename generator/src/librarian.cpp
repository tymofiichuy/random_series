#include "rs_generator.hpp"

using namespace std;

Librarian::Librarian(string f, uint8_t s):file(f), seed(s){
    init();
};

void Librarian::set_file(string f){
    file = f;
}

void Librarian::set_seed(uint8_t s){
    seed = s;
}

void Librarian::init(){
    str.close();
    str.clear();
    str.open(file, ios::binary);
    if(!str){
        throw runtime_error("Invalid file");
    }
    state = seed;
}

uint8_t Librarian::clock(){
    if(!str){
        throw runtime_error("Uninitialized generator");
    }

    uint8_t temp;
    str.read(reinterpret_cast<char*>(&temp), 1);
    if(str.fail()){
        throw runtime_error("Read error");
    }
    state += temp;

    return state;
}