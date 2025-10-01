#include "criterion.hpp"

using namespace std;

// criterion::criterion(){
//     limits[0] = sqrt(510)*quintiles[0] + 255.0f;
//     limits[1] = sqrt(510)*quintiles[1] + 255.0f;
//     limits[2] = sqrt(510)*quintiles[2] + 255.0f;
// }

criterion::~criterion(){
    if(intervals){
        for(int i = 0; i < 256; i++){
            delete[] intervals[i];
        }
        delete[] intervals;
        intervals = nullptr;
    }
}

void criterion::check_equiprobability(){
    int l_n_count = n_const/256;
    float stat = 0;
    for(int i = 0; i < 256; i++){
        stat += static_cast<float>((unigrams[i]-l_n_count)*(unigrams[i]-l_n_count))/l_n_count;
    }
    statistics[0] = stat;

    cout << "Equiprobability\n   alpha: 0.01\n       limit: " << limits[0][0] << ", statistics: " << stat << ", passed: " << !(stat>limits[0][0]) << "\n";
    cout << "   alpha: 0.05\n       limit: " << limits[0][1] << ", statistics: " << stat << ", passed: " << !(stat>limits[0][1]) << "\n";
    cout << "   alpha: 0.1\n       limit: " << limits[0][2] << ", statistics: " << stat << ", passed: " << !(stat>limits[0][2]) << "\n\n";
}

void criterion::check_independence(){
    float stat = 0;

    float f_i_array[256] = {}, l_i_array[256] = {};

    for(int i = 0; i < 256; i++){
        for(int j = 0; j < 256; j++){
            f_i_array[i] += bigrams[i][j];
            l_i_array[i] += bigrams[j][i];
        }
    }

    for(int i = 0; i < 256; i++){
        for(int j = 0; j < 256; j++){
            if((f_i_array[i]!=0)&&(l_i_array[i]!=0)){
                stat += static_cast<float>((bigrams[i][j]*bigrams[i][j]))/(f_i_array[i]*l_i_array[i]);                
            }
        }
    }
    if(stat!=0){
        stat = (stat-1)*(n_const/2);        
    }
    statistics[1] = stat;

    cout << "Independence\n   alpha: 0.01\n       limit: " << limits[1][0] << ", statistics: " << stat << ", passed: " << !(stat>limits[1][0]) << "\n";
    cout << "   alpha: 0.05\n       limit: " << limits[1][1] << ", statistics: " << stat << ", passed: " << !(stat>limits[1][1]) << "\n";
    cout << "   alpha: 0.1\n       limit: " << limits[1][2] << ", statistics: " << stat << ", passed: " << !(stat>limits[1][2]) << "\n\n";
}

void criterion::check_uniformity(){
    float stat = 0;

    for(int i = 0; i < 256; i++){
        for(int j = 0; j < intervals_num; j++){
            stat += static_cast<float>((intervals[i][j]*intervals[i][j]))/(unigrams[i]*interval_len);
        }
    }
    stat = (stat-1)*n_const;
    statistics[2] = stat;

    cout << "Uniformity\n   alpha: 0.01\n       limit: " << limits[2][0] << ", statistics: " << stat << ", passed: " << !(stat>limits[2][0]) << "\n";
    cout << "   alpha: 0.05\n       limit: " << limits[2][1] << ", statistics: " << stat << ", passed: " << !(stat>limits[2][1]) << "\n";
    cout << "   alpha: 0.1\n       limit: " << limits[2][2] << ", statistics: " << stat << ", passed: " << !(stat>limits[2][2]) << "\n\n";
}