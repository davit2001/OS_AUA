#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n;

    printf("Enter the number of students: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > (size_t) - 1 / sizeof(int)) return 1;

    int *grades = malloc(n * sizeof(*grades));
    if (grades == NULL) return 1;

    printf("Enter the grades: ");
    
    for (size_t i = 0; i < n; i++) {
        if (scanf("%d", &grades[i]) != 1) { 
	  free(grades);
	 
	  return 1;
       	}
    }

    int highest = grades[0];
    int lowest = grades[0];
    
    for (size_t i = 1; i < n; i++) {
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest) lowest = grades[i];
    }

    printf("Highest grade: %d\nLowest grade: %d\n", highest, lowest);
    free(grades);
    
    return 0;
}

