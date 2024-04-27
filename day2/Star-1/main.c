#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

void split(char *output[], const char *input, const char *delimiter, int *count);
void free_split(char *output[], int count);
bool game_is_impossible(char *cube_color, int cube_count);


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./main <filename>\n");
        return 1;
    }
    FILE* data = fopen(argv[1], "r");
    char line[1024];
    int sum = 0;
    while (fgets(line, sizeof(line), data)) {
        char *output[2];
        int count = 0;

        split(output, line, ":", &count);
        int gameId = 0;
        char buffer[16];
        sscanf(output[0], "%s %d", buffer, &gameId);
        char *subset[1000];
        int subcount = 0;
        split(subset, output[1], ";", &subcount);
        free_split(output, count);
        int incorrect_game = 0;
        for (int i = 0; i < subcount; i++) {
            char *color[3];
            int color_count = 0;
            split(color, subset[i], ",", &color_count);
            for (int j = 0; j < color_count; j++) {
                int cube_count = 0;
                char cube_color[16];
                sscanf(color[j], "%d %s", &cube_count, cube_color);
                if (game_is_impossible(cube_color, cube_count)) {
                    printf("%s \n", color[j]);
                    ++incorrect_game;
                }
            }
            free_split(color, color_count);
        }
        free_split(subset, subcount);
        if (!incorrect_game) {
            printf("%s \n", line);
            sum += gameId;
        }
    }
    printf("%d \n", sum);
    fclose(data);
}


void split(char *output[], const char *input, const char *delimiter, int *count) {

    char *input_cpy = strdup(input);

    char *token;
    int i = 0;
    token = strtok((char *)input_cpy, delimiter);

    while (token != NULL) {
        output[i++] = strdup(token);
        token = strtok(NULL, delimiter);
    }

    *count = i;

   free(input_cpy);
}

void free_split(char *output[], int count) {
    for (int i = 0; i < count; i++)
        free(output[i]);
}

bool game_is_impossible(char *cube_color, int cube_count) {
    printf("%d\n", cube_count);
    if (strcmp(cube_color, "red") == 0 && cube_count > MAX_RED)
        return true;
    
    if (strcmp(cube_color, "blue") == 0 && cube_count > MAX_BLUE)
        return true;

    if (strcmp(cube_color, "green") == 0 && cube_count > MAX_GREEN)
        return true;

    return false;
}
