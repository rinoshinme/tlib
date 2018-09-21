#include <iostream>
#include "tlib.h"
using namespace tlib;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    tlib::Counter counter;
    counter.add("1", 1);
    std::cout << counter.get("1") << std::endl;
    
    std::cout << "finished...\n";
    return 0;
}
