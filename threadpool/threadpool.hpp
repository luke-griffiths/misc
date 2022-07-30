
#ifndef threadpool_hpp
#define threadpool_hpp

#include <atomic>
#include <functional>
#include <thread>
#include <vector>
#include "concurrent_queue.h"

class Threadpool{
    private:
    std::vector<std::thread> threads;
    //this line limits me to only functions that return void. need to figure out a way around this
    Concurrent_queue<std::function<void()>> q;
    void worker();
    
    public:
    Threadpool();
    ~Threadpool();
    void submit(std::function<void()> f);
    
};

#endif /* threadpool_hpp */
