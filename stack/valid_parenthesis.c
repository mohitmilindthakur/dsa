#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include "stack.h"

static char get_correct_closing_bracket(char open_bracket) {
    switch(open_bracket) {
        case '(': return ')';
        case '{': return '}';
        case '[': return ']';
        default: return '\0';
    } 
}

bool check_if_valid(char *s)
{
    Stack *stack = create_stack();
    // ... use push / pop / peek here


    for (int i = 0; s[i] != '\0'; i++) {
        char curr = s[i];
        if (curr == '(' || curr == '{' || curr == '[') {
            push(stack, &s[i]);
            continue;
        }
        if (stack->size == 0) {
            destroy_stack(stack);
            return false;
        }
        char prev = *(char *)peek(stack);
        if (curr == '}' || curr == ']' || curr == ')') {
            if (get_correct_closing_bracket(prev) != curr) {
                destroy_stack(stack);
                return false;
            } else {
                void *out;
                pop(stack, &out);
            }
        }
    }
    if (stack->size != 0) {
        return false;
    }
    destroy_stack(stack);
    return true;
}

int main(void)
{
    assert(check_if_valid("") == true);
    assert(check_if_valid("()") == true);
    assert(check_if_valid("()[]{}") == true);
    assert(check_if_valid("(]") == false);
    assert(check_if_valid("([)]") == false);
    assert(check_if_valid("[[]{}()[]]") == true);
    printf("all tests passed\n");

    return 0;
}
