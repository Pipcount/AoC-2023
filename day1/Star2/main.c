#include <stdio.h>
#include <ctype.h>
#include <string.h>



#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char* name;
    int number;
} number;

number numbers[10] = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};

int main (int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./main <filename>\n");
        return 1;
    }
    FILE* data = fopen(argv[1], "r");
    char line[256];
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
            } else {
                char word[6];
                for (int j = 0; j < 5; j++) {
                    word[j] = line[i + j];
                    word[j + 1] = '\0';
                    for (int k = 0; k < 10; k++) {
                        if (strcmp(word, numbers[k].name) == 0) {
                            printf("%s\n", numbers[k].name);
                            lastInt = numbers[k].number;
                            if (firstInt == -1) {
                                firstInt = lastInt;
                            }
                            break;
                        }
                    }
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