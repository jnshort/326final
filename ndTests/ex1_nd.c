#include <pthread.h> // includes for pthreads
#include <unistd.h>  // includes for sleep()
#include <stdio.h>   // include for file i/o
#include <stdlib.h>  // include for atoi()


FILE *fp;
int count_total = 0;
pthread_mutex_t lock1, lock2;

void* increment_one();
void* increment_two();
int main(int argc, char **argv) {
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    int run_num = atoi(argv[1]);

    fp = fopen("logfile.txt", "w");
    fprintf(fp, "Test Run: %d\n", run_num);
    fclose(fp);

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
        fprintf(fp, "total: %d\n", count_total);
        fclose(fp);
        pthread_mutex_unlock(&lock1);
        pthread_mutex_unlock(&lock2);
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
        pthread_mutex_unlock(&lock1);
        pthread_mutex_unlock(&lock2);
    }

    return NULL;
}
