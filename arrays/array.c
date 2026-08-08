#include <stdio.h>
#include <string.h>


void main() {
    int size = 5;
    int nums[5] = {1,2,3,4,5};
    printf("%b\n", &nums[1] ==  nums + 1);
    printf("%d\n", *(nums + 7));

    for (int i = 0; i < size; i++) {
        printf("%p\n", &nums[i]);
    }

    char name[] = "Dr Robert Ford";
    strcpy(name, "testing testing testing testing");
    printf("%s\n", name);
    printf("%p\n", name);
}