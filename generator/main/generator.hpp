#include "rs_generator.hpp"

class gen_driver{
private:
    std::unique_ptr<rs_generator> gen;
public:
    //LE-L - lehmer_32_low
    //LE-H - lehmer_32_high
    //L20 - L20
    //L89 - L89
    //GF - Geffe
    //WF - Wolfram
    //LB - Librarian
    //BM_1-8 - Blum–Micali (byte per iteration)
    //BM_8-8 - Blum–Micali (bit per iteration)
    //BBS_1-8 - Blum-Blum-Shub (byte per iteration)
    //BBS_8-8 - Blum-Blum-Shub (bit per iteration)
    void initialize(std::string type);
    //length in bytes
    void generate_sequence(std::string output_file, int length);
};