#include <stdio.h>

char firstRepeatedChar(char *s) {
    int seen[26] = {0};

    for(int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if(seen[idx] == 1) {
            return s[i];
        }

        seen[idx] = 1;
    }

    return '\0';
}

int main() {
    char s[] = "abccbaacz";
    char ans = firstRepeatedChar(s);

    if(ans != '\0')
        printf("First repeated character: %c\n", ans);
    else
        printf("No repeated character\n");

    return 0;
}