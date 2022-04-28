// producer consumer problem using semaphore
// Program with Semaphore:
#include <stdio.h>
#include <pthread.h>   //for all thread related functions.
#include <unistd.h>    //defines miscellaneous symbolic constants and types, and declares miscellaneous functions
#include <semaphore.h> /* The <semaphore.h> header defines the "sem_t" type, used in performing semaphore operations  */
#include <stdlib.h>
#define BUF_SIZE 2

struct buffer
{
    int data;
};

struct buffer buf[BUF_SIZE];
sem_t fill, empty;
int value, i;
void *producer(void *data);
void *consumer(void *data);
int main(void)
{
    int sel, prod_data, cons_data;
    int k;
    // The sem_init() function is used to initialise the semaphorevariable by value given as third parameter.
    if (sem_init(&empty, 0, BUF_SIZE))
    { // initialized to buffer SIZE, when 0, buffer is full
        printf("Error: semaphore not initialize\n");
        return -1;
    }
    if (sem_init(&fill, 0, 0))
    { // initialized to 0, so no consumer can read from buffer, when 0, buffer is empty
        printf("Error: semaphore not initialize\n");
        return -1;
    }
    while (1)
    {
        printf(".........................................................\n");
        printf("Selection\n");
        printf("Producer : 1 | Consumer : 2 | Display : 3 | Exit : 0 || ");
        scanf("%d", &sel);
        printf(".........................................................\n");
        switch (sel)
        {
        case 1:
            // int sem_getvalue(sem_t *sem, int *sval); function updates the location referenced by the sval argument
            // to have the value of the semaphore referenced by sem without affecting the state of the semaphore.
            sem_getvalue(&empty, &value);
            // printf("Prod_e: %d\n", value);
            sem_getvalue(&fill, &value);
            // printf("Prod_f: %d\n", value);
            printf("\nProducer\n");
            pthread_t prod_t;
            printf("Enter data:");
            scanf("%d", &prod_data);
            if (pthread_create(&prod_t, NULL, producer, (void *)&prod_data))
            {
                printf("Error: thread not created\n");
                return -1;
            }
            break;
        case 2:
            printf("\nConsumer\n");
            sem_getvalue(&empty, &value);
            // printf("Cons_e: %d\n", value);
            sem_getvalue(&fill, &value);
            // printf("Cons_f: %d\n", value);
            pthread_t con_t;
            if (pthread_create(&con_t, NULL, consumer, (void *)&cons_data))
            {
                printf("Error: thread not created\n");
                return -1;
            }
            if (i == 0)
            {
                printf("Buffer empty\n");
                break;
            }
            sleep(1); // if commented then synchronization issue
            printf("Consume data: %d\n", cons_data);
            break;
        case 3:
            if (i == 0)
            {
                printf("Buffer empty\n");
                break;
            }
            for (k = 0; k < i; k++)
                printf("buf[%d]: %d\n", k, buf[k].data);
            break;
        case 0:
            sem_destroy(&fill);
            sem_destroy(&empty);
            exit(0);
            break;
        }
    }
    sem_destroy(&fill);
    sem_destroy(&empty);
    return 0;
}
void *producer(void *arg)
{
    int data = *(int *)arg;

    if (sem_wait(&empty))
    { /*  The sem_wait() function locks the semaphore referenced by empty by performing a semaphore lock operation on that semaphore. */
        printf("Error: sem wait fail\n");
        pthread_exit(NULL);
    }

    buf[i].data = data;
    i++;
    if (sem_post(&fill))
    { /* post  The sem_post() function unlocks the semaphore referenced by fill*/
        printf("Error: sem wait fail\n");
        pthread_exit(NULL);
    }
    pthread_exit(NULL);
}
void *consumer(void *arg)
{
    if (sem_wait(&fill))
    { /* wait */
        printf("Error: sem wait fail\n");
        pthread_exit(NULL);
    }
    i--;
    *(int *)arg = buf[i].data;

    if (sem_post(&empty))
    { /* post */
        printf("Error: sem wait fail\n");
        pthread_exit(NULL);
    }
    pthread_exit(NULL);
}