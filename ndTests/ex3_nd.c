#include <pthread.h> // includes for pthreads
#include <unistd.h>  // includes for sleep()
#include <stdio.h>   // include for file i/o
#include <stdlib.h>  // include for atoi()


FILE *fp, *dummy1, *dummy2;
int count_total = 0;
int dummy_var = 0;
int total_1 = 0;
int total_2 = 0;
pthread_mutex_t lock1, lock2;

void* increment_one();
void* increment_two();
int main(int argc, char **argv) {
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    fp = fopen("logfile.txt", "w");
    fclose(fp);

    pthread_t process1, process2;
    pthread_create(&process1, NULL, increment_one, NULL);
    pthread_create(&process2, NULL, increment_two, NULL);

    sleep(60);
}

void* pad_size_1(int count) {

    for (int i = 0; i < count; i++) {
        dummy_var++;
        dummy1 = fopen("dummy.txt", "w");
        fprintf(dummy1, "dummy text %d\n", dummy_var);
        fclose(dummy1);
    }
}

void* pad_size_2(int count) {

    for (int i = 0; i < count; i++) {
        dummy_var++;
        dummy2 = fopen("dummy.txt", "w");
        fprintf(dummy2, "dummy text %d\n", dummy_var);
        fclose(dummy2);
    }
}
void* increment_one() {
    while (1 == 1) {
        pthread_mutex_lock(&lock1);
        pthread_mutex_lock(&lock2);
        fp = fopen("logfile.txt", "a");
        count_total++;
        fprintf(fp, "total: %d\n", count_total);
        fclose(fp);
        pthread_mutex_unlock(&lock1);
        pthread_mutex_unlock(&lock2);
        pad_size_1(2);
    }

    return NULL;
}

void* increment_two() {
    while (1 == 1) {
        pthread_mutex_lock(&lock1);
        pthread_mutex_lock(&lock2);
        fp = fopen("logfile.txt", "a");
        count_total++;
        fprintf(fp, "total: %d\n", count_total);
        fclose(fp);
        pthread_mutex_unlock(&lock2);
        pthread_mutex_unlock(&lock1);
        pad_size_2(2);
    }

    return NULL;
}


