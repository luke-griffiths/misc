
#ifndef concurrent_queue_h
#define concurrent_queue_h

#include <queue>
#include <mutex>
#include <condition_variable>


template<typename T>
class Concurrent_queue{
    private:
    std::mutex m;
    std::queue<T> q;
    std::condition_variable c;
    
    public:
    void push(T val){
        std::lock_guard lg(m);
        q.push(val);
        c.notify_one();
    }
    
    void pop(T& val){
        std::unique_lock lg(m);
        c.wait(lg, [this]{ return !q.empty();});
        val = q.front();
        q.pop();
    }
    
};

#endif /* concurrent_queue_h */
