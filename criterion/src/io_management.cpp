#include "criterion.hpp"

using namespace std;

void criterion::init_limits(){
    limits[0][0] = static_cast<float>(sqrt(510))*quintiles[0] + 255;
    limits[0][1] = static_cast<float>(sqrt(510))*quintiles[1] + 255;
    limits[0][2] = static_cast<float>(sqrt(510))*quintiles[2] + 255;

    limits[1][0] = static_cast<float>(sqrt(130050))*quintiles[0] + 65025;
    limits[1][1] = static_cast<float>(sqrt(130050))*quintiles[1] + 65025;
    limits[1][2] = static_cast<float>(sqrt(130050))*quintiles[2] + 65025;

    limits[2][0] = static_cast<float>(sqrt(2*255*intervals_num))*quintiles[0] + 255*intervals_num;
    limits[2][1] = static_cast<float>(sqrt(2*255*intervals_num))*quintiles[1] + 255*intervals_num;
    limits[2][2] = static_cast<float>(sqrt(2*255*intervals_num))*quintiles[2] + 255*intervals_num;
}

void criterion::open_series(string file){
    if(intervals){
        for(int i = 0; i < 256; i++){
            delete[] intervals[i];
        }
        delete[] intervals;
        intervals = nullptr;
    }
    try{
        in.clear();
        in.open(file, ios::binary);
    }
    catch(...){
        throw runtime_error("Unable to open file");
    }

    n_const = 0;
    memset(unigrams, 0, sizeof(unigrams));
    for(int i = 0; i < 256; i++){
        memset(bigrams[i], 0, sizeof(bigrams[i]));
    }
    intervals_num = static_cast<int>(filesystem::file_size(file))/interval_len;

    init_limits();

    intervals = new int*[256];
    for(int i = 0; i < 256; i++){
        intervals[i] = new int[intervals_num];
        memset(intervals[i], 0, intervals_num*sizeof(int));
    }
}

void criterion::count(){
    if(!in){
        throw runtime_error("Unable to read a series");
    }

    bool pair = true;
    uint8_t prev, curr;
    int inter_counter = 0, curr_inter = 0;
    if(!in.read(reinterpret_cast<char*>(&prev), 1)){
        return;
    };
    unigrams[prev]++;
    intervals[prev][curr_inter]++;
    inter_counter++;
    n_const++;

    while(in.read(reinterpret_cast<char*>(&curr), 1)){
        inter_counter++;
        if(inter_counter >= interval_len){
            inter_counter = 0;
            curr_inter++;
        }
        unigrams[curr]++;
        if(pair){
            bigrams[prev][curr]++;
            pair = false;         
        }
        else{
            pair = true;
        }
        intervals[curr][curr_inter]++;
        n_const++;
        prev = curr;
    }

    // for(int i = 0; i < 256; i++){
    //     for(int j = 0; j < 256; j++){
    //         cout << bigrams[i][j] << " ";
    //     }
    // }
}