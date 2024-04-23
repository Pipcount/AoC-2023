#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./main <filename>\n");
        return 1;
    }
    FILE* data = fopen(argv[1], "r");
    char line[256];
    int sum = 0;
    while (fgets(line, sizeof(line), data)) {
		char *token;
		token = strtok(line, ":");
		int gameId = 0;
		char buffer[64];
		int impossibleGameCounter = 0;
		while (token != NULL) {
			sscanf(token, "%s %d", buffer, &gameId);	
			token = strtok(NULL, ":");
			char *round;
			printf("%s\n", token);
			round = strtok(token, ";");
			while (round != NULL) {
				printf("%s\n", round);
				char *colorSet;
				colorSet = strtok(round, ",");
				while (colorSet != NULL) {
					int amount = 0;
					char color[32];
					sscanf(colorSet, " %d %s", &amount, color);
					if (strcmp(color, "red") && amount > MAX_RED) {
						++impossibleGameCounter;
						printf("%d %s\n", gameId, color);
					} else if (strcmp(color, "blue") && amount > MAX_BLUE) {
						++impossibleGameCounter;
						printf("%d %s\n", gameId, color);
					} else if (strcmp(color, "green") && amount > MAX_GREEN) {
						++impossibleGameCounter;
						printf("%d %s\n", gameId, color);
					}
					colorSet = strtok(NULL, ",");
				}
				round = strtok(NULL, ";");
			}
			token = strtok(NULL, ":");
		}
		if (impossibleGameCounter)
			sum += gameId;
	}
	printf("%d\n", sum);
}

