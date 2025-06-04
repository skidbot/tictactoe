#include <stdbool.h>
#include <stdio.h>

void boardPrint(char arr[9]) {
    for (int i = 0; i < 9; i++) {
        printf(" %c ", arr[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
            if (i < 8) {
                printf("---|---|---\n");
            }
        } else {
            printf("|");
        }
    }
}

char checkWin(char arr[9]) { // Not finished
    for (int i = 0; i < 9; i++) {
        if (arr[i] == 'X') {
            return 'X';
        }
        else if (arr[i] == 'O') {
            return 'O';
        }
        else {
            return '1';
            }
    }
    return false;
}

char updateBoard(char arr[9]) {
    // Replace number with X or O and check for win afterwards
    if (checkWin(arr) == true) {
        return 'W';
    }

    return boardPrint(arr);
}

int main(void) {
    char arr[9] = {'1','2','3','4','5','6','7','8','9'};
    // While Loop for Input from both players until win
    updateBoard(arr);
    return 0;
}