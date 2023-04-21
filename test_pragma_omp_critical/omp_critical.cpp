#include <iostream>

#ifdef _OPENMP
#include <omp.h>
#endif

#include <mutex> 

using namespace std;


int main(int argc, char** argv){
    if(!(argc == 1))
    {
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;

    std::mutex mtx;

    size_t thread_id=0;
    int counter = 0;

    // C,C++使用以#pragma omp开头的标准预处理指令
    // if you have sepecific num_threads, each thread will get N/num_thread works  
#pragma omp parallel for num_threads(4) shared(counter)
    for(size_t i = 0; i < 1000000; i++)
    {

// OpenMP critical安排线程对接下来的代码块互斥访问
// 互斥锁之critical定义临界区
// 制导指令critical可以定义一个任意大小的代码块作为临界区保护，atomic原子操作应用在单条赋值语句中

// add atomic, the result also is right, but, not efficient like atomic
#pragma omp critical
        {
            // mtx.lock();  // mutex lock also work, but NOT efficient
            counter ++;  // if we do NOT have atomic, it will cause error
            // mtx.unlock();
        }
    }

    cout << "counter: " << counter << endl;

    return 0;
}