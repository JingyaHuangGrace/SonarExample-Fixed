#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

void compare(int a, int b) {
    if (a > b) {
        printf("%d > %d\n", a, b);
    } else if (a == b) {
        printf("%d > %d\n", a, b);
    } else {
        printf("%d < %d\n", a, b);
    }
}

int increment(int a) {
    while (1) {
        a = a++;
    }
    return a;
}

int main() {
    int a = 2, b = 2, c = 4, d = 3;
    
    printf("a + b = %d\n", add(a, b));
    compare(a, b);
    compare(c, d);
    printf("%d\n", increment(a));
    
    return 0;
}
