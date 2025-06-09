#include <stdbool.h>
#include <stdio.h>


bool gameInProgress = true;

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

char checkWin(char arr[9]) { // Not finished redo please
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
    } //     bool gameInProgress = false;
    return false;
}

void updateBoard(int choice, char arr[9]) {
    // Replace number with X or O and check for win afterwards


    if (checkWin(arr) == true) {
        gameInProgress = false;
        return 'W';
    }

    return boardPrint(arr);
}

int main(void) {


    char arr[9] = {'1','2','3','4','5','6','7','8','9'};
    int choice;
    // While Loop for Input from both players until win
    updateBoard(choice, arr);

    while (gameInProgress) {
        printf("Player 1 Turn (X):");
        scanf("%d", &choice);
        updateBoard(&choice, arr);

        printf("Player 2 Turn (O):");
        scanf("%d", &choice);
        updateBoard(&choice, arr);
    }
    return 0;
}