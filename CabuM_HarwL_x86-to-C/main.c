#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void kernelA(int n, float* a, float* x, float* y, float* z);

void kernelC(int n, float a, float* x, float* y, float* z) {

    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + y[i];
    }
}

void initialize_random_vector(int n, float vector[]) {
    for (int i = 0; i < n; i++) {
        vector[i] = (float)(rand() % 31); // Generate random float between 0 to 30
    }
}


int main() {

    int n1 = 1 << 20; // 2^20
    int n2 = 1 << 24; // 2^24
    int n3 = 1 << 28; // 2^28

    float* x1 = (float*)malloc(n1 * sizeof(float));
    float* y1 = (float*)malloc(n1 * sizeof(float));
    float* z1 = (float*)malloc(n1 * sizeof(float));

    float* x2 = (float*)malloc(n2 * sizeof(float));
    float* y2 = (float*)malloc(n2 * sizeof(float));
    float* z2 = (float*)malloc(n2 * sizeof(float));

    float* x3 = (float*)malloc(n3 * sizeof(float));
    float* y3 = (float*)malloc(n3 * sizeof(float));
    float* z3 = (float*)malloc(n3 * sizeof(float));

    // Initialize random vectors

    initialize_random_vector(n1, x1);
    initialize_random_vector(n1, y1);

    initialize_random_vector(n2, x2);
    initialize_random_vector(n2, y2);

    initialize_random_vector(n3, x3);
    initialize_random_vector(n3, y3);

    float a = 2.0;

    // Aeverage Execution Time Testing
    printf("-----KERNEL AVERAGE TIMES-----\n\n");

    clock_t start, end;
    double cpu_time_used;
    int runs = 30;

    /*kernelA(n1, &a, x1, y1, z1);
    kernelA(n2, &a, x2, y2, z2);
    kernelA(n3, &a, x3, y3, z3);*/

    /*kernelC(n1, a, x1, y1, z1);
    kernelC(n2, a, x2, y2, z2);
    kernelC(n3, a, x3, y3, z3);*/

    // Test kernelA for 2^20
    double timeA_N1 = 0;
    for (int i = 0; i < runs; i++) {
        start = clock();
        kernelA(n1, &a, x1, y1, z1);
        end = clock();
        cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
        timeA_N1 += cpu_time_used;
    }
    printf("Average run time for kernelA with 2^20 Vector Size: %f seconds\n", timeA_N1 / runs);

    // Test kernelC for 2^20
    double timeC_N1 = 0;
    for (int i = 0; i < runs; i++) {
        start = clock();
        kernelC(n1, a, x1, y1, z1);
        end = clock();
        cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
        timeC_N1 += cpu_time_used;
    }
    printf("Average run time for kernelC with 2^20 Vector Size: %f seconds\n", timeC_N1 / runs);

    printf("\n\n");

    // Test kernelA for 2^24
    double timeA_N2 = 0;
    for (int i = 0; i < runs; i++) {
        start = clock();
        kernelA(n2, &a, x2, y2, z2);
        end = clock();
        cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
        timeA_N2 += cpu_time_used;
    }
    printf("Average run time for kernelA with 2^24 Vector Size: %f seconds\n", timeA_N2 / runs);

    // Test kernelC for 2^24
    double timeC_N2 = 0;
    for (int i = 0; i < runs; i++) {
        start = clock();
        kernelC(n2, a, x2, y2, z2);
        end = clock();
        cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
        timeC_N2 += cpu_time_used;
    }
    printf("Average run time for kernelC with 2^24 Vector Size: %f seconds\n", timeC_N2 / runs);

    printf("\n\n");

    // Test kernelA for 2^28
    double timeA_N3 = 0;
    for (int i = 0; i < runs; i++) {
        start = clock();
        kernelA(n3, &a, x3, y3, z3);
        end = clock();
        cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
        timeA_N3 += cpu_time_used;
    }
    printf("Average run time for kernelA with 2^28 Vector Size: %f seconds\n", timeA_N3 / runs);

    // Test kernelC for 2^28
    double timeC_N3 = 0;
    for (int i = 0; i < runs; i++) {
        start = clock();
        kernelC(n3, a, x3, y3, z3);
        end = clock();
        cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
        timeC_N3 += cpu_time_used;
    }
    printf("Average run time for kernelC with 2^28 Vector Size: %f seconds\n", timeC_N3 / runs);

    printf("\n\n");

    int i;

    //Sanity Check
    printf("----- Correctness Check -----\n\n");

    printf("A value: %.1f \n\n", a);

    printf("--- Vector Size N = 3 Outputs ---\n\n");

    float x[] = { 1.0, 2.0, 3.0 };
    float y[] = { 11.0, 12.0, 13.0 };
    float z[3];

    int n = 3;

    printf("X values: ");

    for (i = 0; i < n; i++) {
        printf("%.1f ", x[i]);
    }

    printf("\n");

    printf("Y values: ");

    for (i = 0; i < n; i++) {
        printf("%.1f ", y[i]);
    }

    printf("\n\n");

    printf("Assembly Output: ");

    kernelA(n, &a, x, y, z);

    for (i = 0; i < n; i++) {
        printf("%.1f ", z[i]);
    }

    printf("\n\n");

    printf("C Funct Output:  ");

    kernelC(n, a, x, y, z);

    for (i = 0; i < n; i++) {
        printf("%.1f ", z[i]);
    }

    printf("\n\n");

    printf("--- Vector Size N = 10 Outputs ---\n\n");

    float x4[10];
    float y4[10];
    float z4[10];

    int n4 = 10;

    initialize_random_vector(n4, x4);
    initialize_random_vector(n4, y4);

    printf("X values: ");

    for (i = 0; i < 10; i++) {
        printf("%.1f ", x4[i]);
    }

    printf("\n");

    printf("Y values: ");

    for (i = 0; i < 10; i++) {
        printf("%.1f ", y4[i]);
    }

    printf("\n\n");

    printf("Assembly Output: ");

    kernelA(n4, &a, x4, y4, z4);

    for (i = 0; i < 10; i++) {
        printf("%.1f ", z4[i]);
    }

    printf("\n\n");

    printf("C Funct Output:  ");

    kernelC(n4, a, x4, y4, z4);

    for (i = 0; i < 10; i++) {
        printf("%.1f ", z4[i]);
    }

    printf("\n\n");

    printf("--- Vector Size N = 2^20 Outputs ---\n\n");

    printf("X values: ");

    for (i = 0; i < 10; i++) {
        printf("%.1f ", x1[i]);
    }

    printf("\n");

    printf("Y values: ");

    for (i = 0; i < 10; i++) {
        printf("%.1f ", y1[i]);
    }

    printf("\n\n");

    printf("Assembly Output: ");

    kernelA(n1, &a, x1, y1, z1);

    for (i = 0; i < 10; i++) {
        printf("%.1f ", z1[i]);
    }

    printf("\n\n");

    printf("C Funct Output:  ");

    kernelC(n1, a, x1, y1, z1);

    for (i = 0; i < 10; i++) {
        printf("%.1f ", z1[i]);
    }

    printf("\n\n--------------------------------");



    return 0;
}