#include <stdio.h>
#include <string.h>

int main() {
    char code[100];
    int i;

    printf("Enter code name: ");
    gets(code);  

    printf("Mirror format: ");

    for(i = strlen(code) - 1; i >= 0; i--) {
        printf("%c", code[i]);
    }

    return 0;
}
