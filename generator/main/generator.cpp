#include "generator.hpp"

using namespace std;

void gen_driver::initialize(string type){
    uint32_t seed_32_1, seed_32_2, seed_32_3;
    uint128_t seed_128;
    uint256_t seed_256;
    string s_seed;

    if(type == "LE"){
        cout << "\nSeed (32-bit number): ";
        if (!(std::cin >> seed_32_1)) {
            throw "Unable to parse\n";
        }

        gen = make_unique<lehmer_32>(seed_32_1);
    }
    else if(type == "L20"){
        cout << "\nSeed (20-bit number): ";
        if (!(std::cin >> seed_32_1)) {
            throw "Unable to parse\n";
        }

        gen = make_unique<L20>(seed_32_1);
    }
    else if(type == "L89"){
        cout << "\nSeed (89-bit number): ";
        cin >> s_seed;
        if (!(seed_128 = uint128_t(s_seed))) {
            throw "Unable to parse\n";
        }
        
        gen = make_unique<L89>(seed_128);
    }
    else if(type == "GF"){
        cout << "\nSeed (11-bit, 9-bit and 10-bit numbers): ";
        if (!(std::cin >> seed_32_1 >> seed_32_2 >> seed_32_3)) {
            throw "Unable to parse\n";
        }

        gen = make_unique<Geffe>(seed_32_1, seed_32_2, seed_32_3);
    }
    else if(type == "WF"){
        cout << "\nSeed (32-bit number): ";
        if (!(std::cin >> seed_32_1)) {
            throw "Unable to parse\n";
        }
        
        gen = make_unique<Wolfram>(seed_32_1);
    }
    else if(type == "LB"){
        cout << "\nSeed (file name): ";
        if (!(std::cin >> s_seed)) {
            throw "Unable to parse\n";
        }
        
        gen = make_unique<Librarian>(s_seed);
    }
    else if(type == "BM"){
        cout << "\nSeed (256-bit number): ";
        cin >> s_seed;
        if (!(seed_256 = uint256_t(s_seed))) {
            throw "Unable to parse\n";
        }
        
        gen = make_unique<BM_generator>(seed_256);
    }
    else if(type == "BBS"){
        cout << "\nSeed (256-bit number): ";
        cin >> s_seed;
        if (!(seed_256 = uint256_t(s_seed))) {
            throw "Unable to parse\n";
        }
        
        gen = make_unique<BBS_generator>(seed_256);
    }
    else{
        throw runtime_error("Undefined type\n");
    }
}

void gen_driver::generate_sequence(string output_file, int length){
    ofstream str(output_file, ios::binary);
    char ch;
    if(!str){
        throw runtime_error("Unable to open file");
    }

    for(int i = 0; i < length; i++){
        ch = gen->clock(); 
        str.write(&ch, 1);
    }
}