#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "ProStr.h"
int z3() {
    FILE* file;
    char input[100] = {'\0'};

    file = fopen("z3.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    if (fgets(input, sizeof(input), file) != NULL) {
        int len = strlen(input);
        processString(input, len);

        fclose(file);
        file = fopen("z3.txt", "w");
        if (file == NULL) {
            printf("Error opening file\n");
            return 1;
        }
        fputs(input, file);

        fclose(file);
    }
    else {
        printf("Error reading from file\n");
    }
    return 0;
}
int z2() {
    char input[100] = { '\0' };

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    processString(input, len);
    printf("%s", input);

    return 0;
}
int z1() {
    char input[100] = { '\0' };
    int i = 0;

    printf("Enter a string: ");
    while ((input[i] = getchar()) != '\n') {
        i++;
    }
    int len = strlen(input);
    processString(input, len); 
    len = strlen(input);
    for (int j = 0; j < len; j++) {
        printf("%c\n", input[j]);
    }

    return 0;
}
void main(void) {
    z2();
}