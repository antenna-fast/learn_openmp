#include <iostream>
#include <omp.h>

#include <unistd.h>


using namespace std;

int main(int argc, char** argv)
{
    if(!(argc == 1))
	{
        cout << " argc not match, Usage: " << endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;
    
    size_t thread_id=0;

// #pragma omp parallel   //C,C++使用以#pragma omp开头的标准预处理指令
// {
//     // cout << "parallel run!!!" << endl;
//     // cout << "thread_id: " << thread_id << endl;
//     // thread_id += 1;
//     printf ("Hello world! I'm thread %d out of %d threads.\n", omp_get_thread_num(), omp_get_num_threads());
// }


#pragma omp parallel sections 
	{
	#pragma omp section 
	{
		#pragma omp critical (critical1)
		{
			for (int i=0; i < 5; i++)
			{
				printf("section1 thread %d excute i = %d\n", omp_get_thread_num(), i);
				// Sleep(200);
				sleep(1);  // sleep 3 seconds
			}
		}
	}

	#pragma omp section
	{
		#pragma omp critical (critical2)
		{
			for (int j=0; j < 9; j++)
			{	
				printf("section2 thread %d excute j = %d\n", omp_get_thread_num(), j);
				// Sleep(200);
				sleep(1);  // sleep 3 seconds

			} 
		}
	}

	}

    return 0;
}