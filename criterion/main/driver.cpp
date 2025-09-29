#include "criterion.hpp"

using namespace std;

int main(int argc, char* argv[]){
    criterion cr;
    try{
        cr.open_series(argv[1]);     
    }
    catch(runtime_error err){
        cerr << err.what();
        return 1;
    }
    cr.count();
    cr.check_equiprobability();
    cr.check_independence();
    cr.check_uniformity();
    return 0;
}