#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

void compare(int a, int b) {
    if (a > b) {
        printf("%d > %d\n", a, b);
    } else if (a == b) {
        printf("%d = %d\n", a, b);
    } else {
        printf("%d < %d\n", a, b);
    }
}


int main() {
    int a = 2; 
    int b = 2; 
    int c = 4; 
    int d = 3;
    
    printf("a + b = %d\n", add(a, b));
    compare(a, b);
    compare(c, d);
    
    return 0;
}
