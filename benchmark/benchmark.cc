//Written by Andrew Purcell.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <unistd.h>
#include <thread>
#include <vector>

#define NUM_TO_CALCULATE 250000

void primeCalculator();
int isNumberPrime(int num);

int main() {
    std::vector<std::thread> threads;

    int i;
    for (i = 0; i < 32; i++) {
        threads.push_back(std::thread(primeCalculator));
    }
	
    for (auto &thread : threads) {
        thread.join();
    }
    
    // struct rusage *usage = malloc(sizeof(struct rusage));
    struct rusage *usage = new rusage;
    getrusage(RUSAGE_SELF, usage);
    printf("User CPU time used:\n    %1ld.%06ld seconds\n",
        usage->ru_utime.tv_sec, usage->ru_utime.tv_usec);
    printf("System CPU time used:\n    %1ld.%06ld seconds\n",
        usage->ru_stime.tv_sec, usage->ru_stime.tv_usec);
    printf("Max resident set size:\n    %ld kbytes\n",
        usage->ru_maxrss);
    printf("Times filesystem had to perform input:\n    %ld\n",
        usage->ru_inblock);
    printf("Times filesystem had to perform output:\n    %ld\n",
        usage->ru_oublock);
    printf("Soft page faults:\n    %ld\n",
        usage->ru_minflt);
    printf("Hard page faults:\n    %ld\n",
        usage->ru_majflt);
    printf("Voluntary context switches:\n    %ld\n",
        usage->ru_nvcsw);
    printf("Involuntary context switches:\n    %ld\n",
        usage->ru_nivcsw);

    exit(EXIT_SUCCESS);
}

void primeCalculator() {
	int i = 2;
    int numPrimes = 0;
    int count = NUM_TO_CALCULATE;

    while (numPrimes < count) {
        if (isNumberPrime(i) == 1) {
            numPrimes++;
        }
        i++;
    }
}

int isNumberPrime(int num) {
    int i;
    if (num < 2) {
        return 0;
    }
    for (i = 2; i * i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}