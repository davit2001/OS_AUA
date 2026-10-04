#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void *resized = malloc(new_size);
    if (resized == NULL) return NULL;
    if (ptr != NULL) {
        memcpy(resized, ptr, old_size < new_size ? old_size : new_size);
        free(ptr);
    }
    return resized;
}

int main(void) {
    size_t old_count = 3;
    size_t new_count = 5;
    int *values = malloc(old_count * sizeof(*values));
    
    if (values == NULL) return 1;

    for (size_t i = 0; i < old_count; i++) values[i] = (int)(i + 1) * 10;
    
    int *resized = my_realloc(values, old_count * sizeof(*values), new_count * sizeof(*values));
    
    if (resized == NULL) { free(values); return 1; }
    values = resized;
    
    for (size_t i = old_count; i < new_count; i++) values[i] = (int)(i + 1) * 10;

    printf("Array after my_realloc:");
    
    for (size_t i = 0; i < new_count; i++) printf(" %d", values[i]);
    
    printf("\n");
    free(values);
    
    return 0;
}
