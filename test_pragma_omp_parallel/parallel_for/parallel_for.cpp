#include <iostream>
#include <omp.h>

using namespace std;


int main(int argc, char** argv){
    if(!(argc == 1))
    {
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    size_t thread_id=0;

    // C,C++使用以#pragma omp开头的标准预处理指令
    // if you have sepecific num_threads, each thread will get N/num_thread works  
    #pragma omp parallel for num_threads(5)
    for(size_t i = 0; i < 10; i++)
    {
        printf ("Hello world! I'm thread %d of %d threads.\n", omp_get_thread_num(), omp_get_num_threads());
    }

    return 0;
}