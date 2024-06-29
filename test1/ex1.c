#include <pthread.h> // includes for pthreads
#include <unistd.h>  // includes for sleep()
#include <stdio.h>   // include for file i/o
#include <stdlib.h>  // include for atoi()


FILE *fp;
int count_total = 0;
int total_1 = 0;
int total_2 = 0;
pthread_mutex_t lock1, lock2;

void* increment_one();
void* increment_two();
int main() {
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    fp = fopen("logfile.txt", "w");

    pthread_t process1, process2;
    pthread_create(&process1, NULL, increment_one, NULL);
    pthread_create(&process2, NULL, increment_two, NULL);

    sleep(3);

}

void* increment_one() {
    while (1 == 1) {
        pthread_mutex_lock(&lock1);
        pthread_mutex_lock(&lock2);
        fp = fopen("logfile.txt", "a");
        count_total++;
        total_1++;
        fprintf(fp, "total: %d\tprocess1: %d\t process2: %d\n", count_total, total_1, total_2);
        fclose(fp);
        pthread_mutex_unlock(&lock1);
        pthread_mutex_unlock(&lock2);
    }

    return NULL;
}

void* increment_two() {
    while (1 == 1) {
        pthread_mutex_lock(&lock2);
        pthread_mutex_lock(&lock1);
        fp = fopen("logfile.txt", "a");
        count_total++;
        total_2++;
        fprintf(fp, "total: %d\tprocess1: %d\t process2: %d\n", count_total, total_1, total_2);
        fclose(fp);
        pthread_mutex_unlock(&lock2);
        pthread_mutex_unlock(&lock1);
    }

    return NULL;
}
