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

    // conditional parallel
    // #pragma omp parallel if(0)   // disable parallel
    #pragma omp parallel if(1)  // enable parallel

    // for(size_t i = 0; i < 5; i++)
    {
        printf ("Hello world! I'm thread %d of %d threads.\n", omp_get_thread_num(), omp_get_num_threads());
    }

    return 0;
}