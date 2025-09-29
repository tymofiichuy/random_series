#include "criterion.hpp"

using namespace std;

void criterion::open_series(string file){
    try{
        in.clear();
        in.open(file, ios::binary);
    }
    catch(...){
        throw runtime_error("Unable to open file");
    }
}

void criterion::count(){
    if(!in){
        throw runtime_error("Unable to read a series");
    }

    uint8_t prev, curr;
    if(!in.read(reinterpret_cast<char*>(&prev), 1)){
        return;
    };
    unigrams[prev]++;
    n_const++;

    while(in.read(reinterpret_cast<char*>(&curr), 1)){
        unigrams[curr]++;
        bigrams[prev][curr]++;
        n_const++;
        prev = curr;
    }

    n_const = n_const/256;
}