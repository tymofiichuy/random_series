#pragma once

#include<iostream>
#include<fstream>
#include<string>

class criterion{
private:
    float unigrams[256] = {};
    float bigrams[256][256] = {};
    float quintiles[3] = {-2.33, -1.64, -1.28};
    float limits[3] = {};
    float statistics[3] = {};
    float n_const;

    std::ifstream in;
public:
    void open_series(std::string file);

    void count();
    bool check_equiprobability();
    bool check_independence();
    bool check_uniformity();

    criterion();
};