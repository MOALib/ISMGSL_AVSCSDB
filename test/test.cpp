#include <iostream>
#include "../Src/ISMGSL_AVSCSDB.hpp"

int main(int argc, char* argv[])
{
    MXPSQL::ISMGSL_AVSCSDB::ISMGSL_AVSCSDB* isgml = new MXPSQL::ISMGSL_AVSCSDB::ISMGSL_AVSCSDB();

    std::cout << "Hello World!" << std::endl;
    std::cout << "This is a test!" << std::endl;

    delete isgml;

    return 0;
}