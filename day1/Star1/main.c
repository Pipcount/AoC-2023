#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./main <filename>\n");
        return 1;
    }
    FILE* data = fopen(argv[1], "r");
    char line[1024];
    int sum = 0;
    while (fgets(line, sizeof(line), data)) {
        int firstInt = -1;
        int lastInt = -1;
        for (int i = 0; i < strlen(line); i++) {
            if (isdigit(line[i])) {
                printf("%c\n", line[i]);
                lastInt = line[i] - '0';
                if (firstInt == -1) {
                    firstInt = lastInt;
                }
            }
        } 
        printf("%d %d\n", firstInt, lastInt);
        int num = firstInt * 10 + lastInt;
        printf("%d\n", num);
        sum += num;
    }
    printf("Sum: %d\n", sum);


    return 0;
}