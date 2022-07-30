
#include "threadpool.hpp"
#include <iostream>
#include <chrono>

using namespace std::literals;
std::mutex m;

void task(){
    std::lock_guard lg(m);
    std::cout << "Thread id: " << std::this_thread::get_id() << " started task" << std::endl;
    std::this_thread::sleep_for(100ms);
    std::cout << "Thread id: " << std::this_thread::get_id() << " finished task" << std::endl;

}

int main() {
    Threadpool pool;
    for(int i = 0; i < 10; i++){
        pool.submit(task);
    }
    std::this_thread::sleep_for(5s);
    return 0;
}
