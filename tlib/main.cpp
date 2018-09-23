#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "tlib.h"
using namespace tlib;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Path path("/Users/liyu/work/data/baby.jpg");
    int n = 100;
    RNG* rng = RNG::getRNG(&n);
    std::cout << rng->getFloat() << std::endl;
    
    std::cout << "finished...\n";
    return 0;
}
