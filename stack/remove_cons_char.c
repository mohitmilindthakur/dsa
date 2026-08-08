#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include "stack.h"
#include <string.h>
#include <stdlib.h>



char *remove_cons_char(char *s) {
    Stack *stack = create_stack();
    push(stack, &s[0]);
    for (int i = 1; s[i] != '\0'; i++) {
        if (stack->size == 0 || *(char *)peek(stack) != s[i]) {
            push(stack, &s[i]);
        } else {
            void *out;
            pop(stack, &out);
        }
    }
    char *final = malloc(stack->size + 1);
    int index = 0;
    final[stack->size] = '\0';
    for (int i = stack->size - 1; i >= 0; i--) {
        void *out;
        pop(stack, &out);
        final[i] = *(char *)out;
    }
    return final;
}


int main() {
    assert(strcmp(remove_cons_char("aabcbb"), "bc") == 0);
    printf("all tests passed\n");

    return 0;
}