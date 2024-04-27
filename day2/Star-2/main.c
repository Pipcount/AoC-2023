#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void split(char *output[], const char *input, const char *delimiter, int *count);
void free_split(char *output[], int count);


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
        int max_red = 0, max_blue = 0, max_green = 0; 
        for (int i = 0; i < subcount; i++) {
            char *color[3];
            int color_count = 0;
            split(color, subset[i], ",", &color_count);
            for (int j = 0; j < color_count; j++) {
                int cube_count = 0;
                char cube_color[16];
                sscanf(color[j], "%d %s", &cube_count, cube_color);
                if (strcmp(cube_color, "red") == 0 && cube_count > max_red) {
                    max_red = cube_count;
                }
                if (strcmp(cube_color, "green") == 0 && cube_count > max_green) {
                    max_green = cube_count;
                }
                if (strcmp(cube_color, "blue") == 0 && cube_count > max_blue) {
                    max_blue = cube_count;
                }
            }
            free_split(color, color_count);
        }
        free_split(subset, subcount);
        sum += (max_blue * max_green * max_red);
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
