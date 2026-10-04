#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *values = malloc(10 * sizeof(*values));
    if (values == NULL) return 1;

    printf("Enter 10 integers: ");
    for (size_t i = 0; i < 10; i++) {
        if (scanf("%d", &values[i]) != 1) { 
	   free(values);
	   return 1;
       	}
    }

    int *smaller = realloc(values, 5 * sizeof(*values));
    
    if (smaller == NULL) { 
	free(values);
       	return 1;
    }

    values = smaller;

    printf("Array after resizing:");
    for (size_t i = 0; i < 5; i++) printf(" %d", values[i]);
    
    printf("\n");
    free(values);

    return 0;
}
