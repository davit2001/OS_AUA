#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n;
    long long sum = 0;

    printf("Enter the number of elements: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > (size_t)-1 / sizeof(int)) return 1;

    int *values = malloc(n * sizeof(*values));
    if (values == NULL) return 1;

    printf("Enter %zu integers: ", n);
    
    for (size_t i = 0; i < n; i++) {
        if (scanf("%d", &values[i]) != 1) { 
	  free(values);
	  
	  return 1;
       	}

        sum += values[i];
    }

    printf("Sum of the array: %lld\n", sum);
    free(values);
    
    return 0;
}

