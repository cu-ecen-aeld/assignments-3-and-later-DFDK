#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
//#define DEBUG_LOG(msg,...)
#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    //struct thread_data* thread_func_args = (struct thread_data *) thread_param;

    struct thread_data* thread_func_args = (struct thread_data *) thread_param;

    // sleep before lock
    usleep(thread_func_args->wait_to_obtain_ms * 1000);
    
    // lock mutex
    int rc1 = pthread_mutex_lock(thread_func_args->mutex);
    if (rc1!=0){
        ERROR_LOG("mutex lock failed with %d\n",rc1);
        thread_func_args->thread_complete_success = false;
    }

    // sleep after lock
    usleep(thread_func_args->wait_to_release_ms * 1000);

    // release mutex
    int rc2 = pthread_mutex_unlock(thread_func_args->mutex);
    if (rc2!=0){
        ERROR_LOG("mutex unlock failed with %d\n",rc2);
        thread_func_args->thread_complete_success = false;
    }  

    return thread_func_args;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */


    // allocate memory for thread_data
    struct thread_data *wait_args = (struct thread_data *)malloc(sizeof(struct thread_data));

    // thread_data
    wait_args->wait_to_obtain_ms = wait_to_obtain_ms;
    wait_args->wait_to_release_ms = wait_to_release_ms; 
    wait_args->thread_complete_success = true;     
    wait_args->mutex = mutex;
    wait_args->thread = thread;
    
    // create thread
    if (pthread_create(thread, NULL, threadfunc,  (void *)wait_args)!=0){
        ERROR_LOG("Thread failed to start! free allocated memory");
        free(wait_args);
        return false;  
    }    

    DEBUG_LOG("Thread created successfully.");
    return true; 
          
}

