#include "rs_generator.hpp"

using namespace std;

Librarian::Librarian(string s):seed(s){};

void Librarian::set_seed(string s){
    seed = s;
}

void Librarian::init(){
    str.clear();
    str.open(seed, ios::binary);
    if(!str){
        cerr << "Invalid seed";
        return;
    }
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

    return temp;
}