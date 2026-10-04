#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char **words = malloc(3 * sizeof(*words));
    if (words == NULL) return 1;

    for (size_t i = 0; i < 3; i++) {
        words[i] = malloc(51);
        
	if (words[i] == NULL) {
            for (size_t j = 0; j < i; j++) free(words[j]);
            free(words);
            
	    return 1;
        }
    }

    printf("Enter 3 strings: ");
    
    for (size_t i = 0; i < 3; i++) {
        if (scanf("%50s", words[i]) != 1) {
            for (size_t j = 0; j < 3; j++) free(words[j]);
            free(words);
            
	    return 1;
        }
    }

    char **larger = realloc(words, 5 * sizeof(*words));
    
    if (larger == NULL) {
        for (size_t i = 0; i < 3; i++) free(words[i]);
        free(words);
        
	return 1;
    }
    words = larger;

    for (size_t i = 3; i < 5; i++) {
        words[i] = malloc(51);
        if (words[i] == NULL) {
            for (size_t j = 0; j < i; j++) free(words[j]);
            free(words);
            
	    return 1;
        }
    }

    printf("Enter 2 more strings: ");
    
    for (size_t i = 3; i < 5; i++) {
        if (scanf("%50s", words[i]) != 1) {
            for (size_t j = 0; j < 5; j++) free(words[j]);
            free(words);
            return 1;
        }
    }

    printf("All strings:");
    
    for (size_t i = 0; i < 5; i++) printf(" %s", words[i]);
    printf("\n");

    for (size_t i = 0; i < 5; i++) free(words[i]);
    free(words);
    return 0;
}
