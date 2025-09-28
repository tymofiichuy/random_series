#include "generator.hpp"

using namespace std;

int main(int argc, char* argv[]){
    gen_driver dr;
    try{
        dr.initialize(argv[1]);
        dr.generate_sequence(argv[2], stoi(argv[3]));        
    }
    catch(runtime_error err){
        cerr << err.what();
    }

    return 0;
}