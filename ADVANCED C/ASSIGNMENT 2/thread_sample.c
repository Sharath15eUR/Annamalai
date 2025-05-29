#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>

int N;
bool running = true;

// Signal handler to catch SIGINT
void sig_handler(int signum) {
    printf("\nSIGINT received. Preventing termination...\n");
    running = false;
}

// Check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0) return 0;
    return 1;
}

void* threadA_sumPrimes(void* arg) {
    int count = 0, num = 2, sum = 0;
    while (count < N) {
        if (is_prime(num)) {
            sum += num;
            count++;
        }
        num++;
    }
    printf("Sum of first %d prime numbers is %d\n", N, sum);
    return NULL;
}

void* threadB_2secPrinter(void* arg) {
    while (running) {
        printf("Thread 1 running\n");
        sleep(2);
    }
    return NULL;
}

void* threadC_3secPrinter(void* arg) {
    int elapsed = 0;
    while (elapsed < 100) {
        printf("Thread 2 running\n");
        sleep(3);
        elapsed += 3;
    }
    return NULL;
}

int main() {
    signal(SIGINT, sig_handler);  // Register signal handler

    printf("Enter N (for prime sum): ");
    scanf("%d", &N);

    pthread_t t1, t2, t3;

    clock_t start_time = clock();

    pthread_create(&t1, NULL, threadA_sumPrimes, NULL);
    pthread_create(&t2, NULL, threadB_2secPrinter, NULL);
    pthread_create(&t3, NULL, threadC_3secPrinter, NULL);

    pthread_join(t1, NULL);
    pthread_join(t3, NULL);

    // Thread 2 is infinite; we stop it only when SIGINT received
    running = false;
    pthread_join(t2, NULL);

    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Total time taken: %.2f seconds\n", total_time);

    return 0;
}
