#include <iostream>

// #ifdef _OPENMP
#include <omp.h>
// #endif

#include <mutex> 

using namespace std;

int sum = 0;

void init()
{
    for (size_t i = 0; i < 10; i++)
    {
        sum ++;
    }
    cout << "thread " << omp_get_thread_num() << " initialize finished." << endl;
}

void process()
{
    cout << "thread " << omp_get_thread_num() << "start process" << endl;
}


int main(int argc, char** argv)
{
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
#pragma omp parallel num_threads(8)
    {
        #pragma omp critical
        {
            init();
        }
#pragma omp barrier  // wait for all threads finish

        cout << "thread sync" << endl;
        cout << "sum: " << sum << endl;

        process();
    }

    return 0;
}