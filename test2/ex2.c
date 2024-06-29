#include <pthread.h> // includes for pthreads
#include <unistd.h>  // includes for sleep()
#include <stdio.h>   // include for file i/o
#include <stdlib.h>  // include for atoi()


FILE *fp;
int count_total = 0;
int total_1 = 0;
int total_2 = 0;
int total_3 = 0;
pthread_mutex_t lock1, lock2;

void* increment_one();
void* increment_two();
int main() {
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    fp = fopen("logfile.txt", "w");
    fclose(fp);

    pthread_t process1, process2, process3;
    pthread_create(&process1, NULL, increment_one, NULL);
    pthread_create(&process2, NULL, increment_two, NULL);
    pthread_create(&process3, NULL, increment_one, NULL);

    sleep(5);

}

void* increment_one() {
    while (1 == 1) {
        pthread_mutex_lock(&lock1);
        pthread_mutex_lock(&lock2);
        fp = fopen("logfile.txt", "a");
        count_total++;
        total_1++;
        fprintf(fp, "total: %d\tprocess1: %d\tprocess2: %d\tprocess3:%d\n", count_total, total_1, total_2, total_3);
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
        fprintf(fp, "total: %d\tprocess1: %d\tprocess2: %d\tprocess3:%d\n", count_total, total_1, total_2, total_3);
        fclose(fp);
        pthread_mutex_unlock(&lock2);
        pthread_mutex_unlock(&lock1);
    }

    return NULL;
}
void* increment_three() {
    while (1 == 1) {
        pthread_mutex_lock(&lock2);
        pthread_mutex_lock(&lock1);
        fp = fopen("logfile.txt", "a");
        count_total++;
        total_3++;
        fprintf(fp, "total: %d\tprocess1: %d\tprocess2: %d\tprocess3:%d\n", count_total, total_1, total_2, total_3);
        fclose(fp);
        pthread_mutex_unlock(&lock2);
        pthread_mutex_unlock(&lock1);
    }

    return NULL;

}
