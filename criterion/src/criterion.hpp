#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>

class criterion{
private:
    int unigrams[256] = {};
    int bigrams[256][256] = {};
    int** intervals = nullptr;
    int interval_len = 128;
    int intervals_num = 0;
    // float intervals[256][1024] = {};

    float quintiles[3] = {2.33f, 1.64f, 1.28f};
    //{202.381f, 217.964f, 226.094f},{0,0,0},{0,0,0}
    float limits[3][3] = {};
    float statistics[3] = {};
    int n_const;

    std::ifstream in;

    void init_limits();
public:
    void open_series(std::string file);

    void count();
    void check_equiprobability();
    void check_independence();
    void check_uniformity();

    ~criterion();
};