#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread when its name
// is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(5);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t tid;
    printf("Before Thread\n");
    pthread_create(&tid, NULL, myThreadFun, NULL);
    printf("%d",sizeof(tid));
    sleep(5);
    pthread_join(tid, NULL);
    sleep(5);
    printf("After Thread\n");
    sleep(5);
    exit(0);
}


