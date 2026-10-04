#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n;
    long long sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > (size_t)-1 / sizeof(int)) return 1;

    int *values = calloc(n, sizeof(*values));
    if (values == NULL) return 1;

    printf("Array after calloc:");
    
    for (size_t i = 0; i < n; i++) printf(" %d", values[i]);
    printf("\nEnter %zu integers: ", n);

    for (size_t i = 0; i < n; i++) {
        if (scanf("%d", &values[i]) != 1) { 
	  free(values); 
	  
	  return 1;
       	}

        sum += values[i];
    }

    printf("Updated array:");
    for (size_t i = 0; i < n; i++) printf(" %d", values[i]);
    
    printf("\nAverage of the array: %.1f\n", (double)sum / n);
    free(values);
    
    return 0;
}
