#include "rs_generator.hpp"

class gen_driver{
private:
    std::unique_ptr<rs_generator> gen;
public:
    //LE - lehmer_32
    //L20 - L20
    //L89 - L89
    //GF - Geffe
    //WF - Wolfram
    //LB - Librarian
    //BM - BM
    //BBS - BBS
    void initialize(std::string type);
    //length in bytes
    void generate_sequence(std::string output_file, int length);
};