#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 4096      // Powers of 2 are better for cache alignment
#define BLOCK_SIZE 64  // Fits into most L2/L3 cache lines
#define THREADS 8      // Set to your core count

float *A, *B, *C;

void* tiled_multiply(void* arg) {
    int tid = *(int*)arg;
    int start_i = (tid * SIZE) / THREADS;
    int end_i = ((tid + 1) * SIZE) / THREADS;

    for (int ih = start_i; ih < end_i; ih += BLOCK_SIZE) {
        for (int jh = 0; jh < SIZE; jh += BLOCK_SIZE) {
            for (int kh = 0; kh < SIZE; kh += BLOCK_SIZE) {
                
                // Inner "Tiled" loops
                for (int i = ih; i < ih + BLOCK_SIZE && i < SIZE; i++) {
                    for (int k = kh; k < kh + BLOCK_SIZE && k < SIZE; k++) {
                        float temp = A[i * SIZE + k];
                        for (int j = jh; j < jh + BLOCK_SIZE && j < SIZE; j++) {
                            C[i * SIZE + j] += temp * B[k * SIZE + j];
                        }
                    }
                }

            }
        }
    }
    return NULL;
}

int main() {
    printf("Starting Tiled Matrix Test (%dx%d)...\n", SIZE, SIZE);
    
    A = malloc(SIZE * SIZE * sizeof(float));
    B = malloc(SIZE * SIZE * sizeof(float));
    C = calloc(SIZE * SIZE, sizeof(float));

    pthread_t thread_ids[THREADS];
    int t_args[THREADS];

    for (int i = 0; i < THREADS; i++) {
        t_args[i] = i;
        pthread_create(&thread_ids[i], NULL, tiled_multiply, &t_args[i]);
    }

    for (int i = 0; i < THREADS; i++) pthread_join(thread_ids[i], NULL);

    printf("Done! High-efficiency stress complete.\n");
    free(A); free(B); free(C);
    return 0;
}