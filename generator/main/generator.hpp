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
    //BM-1-8 - BM (byte per iteration)
    //BM-8-8 - BM (bit per iteration)
    //BBS-1-8 - BBS (byte per iteration)
    //BBS-8-8 - BBS (bit per iteration)
    void initialize(std::string type);
    //length in bytes
    void generate_sequence(std::string output_file, int length);
};