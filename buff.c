#include <stdio.h>
#include <string.h>

int main() {
    char str1[5]; 
    char str2[100]; 

    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Read the input string from the user
    scanf("%4s", str2); 

    // Copy the input string into str1
    strcpy(str1, str2); 

    // Print the copied string
    printf("Copied string is: %s\n", str1);

    return 0;
}
