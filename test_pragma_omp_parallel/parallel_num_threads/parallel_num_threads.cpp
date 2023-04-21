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

    bool is_enable_parallel = 1;

    // omp_set_num_threads(5);  // equals to num_threads(5) at below

    #pragma omp parallel if(is_enable_parallel) num_threads(5)  // number of threads to create

    // for(size_t i = 0; i < 5; i++)
    {
        printf ("Hello world! I'm thread %d of %d threads.\n", omp_get_thread_num(), omp_get_num_threads());
    }

    return 0;
}
