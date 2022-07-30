#include "threadpool.hpp"

Threadpool::Threadpool(){
    const unsigned numThreads{std::thread::hardware_concurrency()};
    for(unsigned i = 0; i < numThreads; i++){
        threads.emplace_back(std::thread{&Threadpool::worker, this});
    }
}

Threadpool::~Threadpool(){
    for(auto& t : threads){
        t.join();
    }
}

void Threadpool::worker(){
    while(true){
        std::function<void()> task;
        q.pop(task);
        task();
    }
}

void Threadpool::submit(std::function<void()> f){
    q.push(f);
}
