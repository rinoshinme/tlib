#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "tlib.h"
using namespace tlib;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Path path("/Users/liyu/work/data/baby.jpg");
    std::cout << path.getFullPath() << std::endl;
    
    std::cout << ((path.isFile()) ? "file" : "dir") << std::endl;
    
    std::cout << "finished...\n";
    return 0;
}
