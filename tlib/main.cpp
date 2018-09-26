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
    
    Array<float> a1(2, 3, 4, 100);
    std::cout << a1.length() << std::endl;
    std::cout << a1.offset(1, 1, 1, 1) << std::endl;
    
    Array<float> sub = a1.getSubarray(std::vector<int>{1, 1, 1, 100}, std::vector<int>{1, 1, 1, 1});
    std::cout << sub.length() << std::endl;
    std::cout << sub.offset(0, 0, 0, 0) << std::endl;
    
    std::cout << "finished...\n";
    return 0;
}
