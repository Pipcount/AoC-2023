#include <cstdio>
#include <stdio.h>
#include <ctype.h>

#define MAX_COLS 100
#define MAX_ROWS 100
 
void print_array(char array[MAX_ROWS][MAX_COLS], int row, int cols);

struct number {
	int value;
	int col_start;
	int col_end;
	int row;
	int is_adjacent;
};


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./main <filename>\n");
        return 1;
    }
    FILE* data = fopen(argv[1], "r");
    char line[1024];
    int sum = 0;
	char input[MAX_ROWS][MAX_COLS]; 
	int row = 0;
	int cols = 0; //the same for every line
    while (fgets(line, sizeof(line), data) && row < MAX_ROWS) {
		int col = 0;
		for (; line[col] != '\n' && col < MAX_COLS; col++)
			input[row][col] = line[col];
		++row;
		cols = col;
	}

	struct number numbers[1000];
	for (int i = 0; i < row; i++) {
		for (int j = cols; j > 0; --j) {
			if (isdigit(input[i][j])) {
				int value = atoi(input[i][j])
			}
		}
	}
	
	print_array(input, row, cols);
	

	fclose(data);
	return 0;
}



void print_array(char array[MAX_ROWS][MAX_COLS], int row, int cols) {
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j < cols; j++) {
			printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}
