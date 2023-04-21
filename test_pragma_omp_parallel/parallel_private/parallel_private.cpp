#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char** argv) {
    if(argc != 1){
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;

    int nthreads, tid;    

    // omp 并行指令显式指示编译器并行化选定的代码块
    #pragma omp parallel private(nthreads, tid)  // Specifies variables local to each thread
    {
        tid = omp_get_thread_num();  // thread id
        cout << "Hello, world from thread " << tid << endl;

        if(tid == 0)
        {
            cout << "number of threads: " << nthreads << endl;
        }

    }   

    return 0;
}