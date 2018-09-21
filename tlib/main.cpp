#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "tlib.h"
using namespace tlib;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    tlib::Counter counter;
    counter.add("1", 1);
    std::cout << counter.get("1") << std::endl;
    
    int N = 5;
    StopWatch sw;
    sw.start();
    for (int i = 0; i < N; ++i)
    {
        usleep(100);
        sw.click("timer");
    }
    sw.stop();
    
    for (int i = 0; i < N; ++i)
        std::cout << sw.getTimeCost(i) << std::endl;
    
    Logger logger("tlib");
    logger.write("test message");
    
    std::cout << "finished...\n";
    return 0;
}
