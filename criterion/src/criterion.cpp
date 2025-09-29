#include "criterion.hpp"

using namespace std;

criterion::criterion(){
    limits[0] = sqrt(510)*quintiles[0] + 255;
    limits[1] = sqrt(510)*quintiles[1] + 255;
    limits[2] = sqrt(510)*quintiles[2] + 255;
}

// bool criterion::check_equiprobability(){
//     float stat = 0;
//     for(int i = 0; i < 256; i++){
//         stat += (unigrams[i]-n_const)*(unigrams[i]-n_const)/n_const;
//     }
//     statistics[0] = stat;
//     if(stat > limits[0]){
//         return false;
//     }
//     return true;
// }