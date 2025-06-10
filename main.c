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

bool checkWin(char arr[9]) { // Not finished redo please
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


    if (checkWin(arr) == false) {

    }
    else if (checkWin(arr) == true) {

    }

    return boardPrint(arr);
}

bool isDraw(char arr[]) {
    for (int i = 0; i < 9; i++) {
        if (arr[i] != 'X' && arr[i] != 'O') return false;
    }
    return true;
}

int main(void) {

    char arr[9] = {'1','2','3','4','5','6','7','8','9'};
    int choice;
    char currentPlayer = 'X';
    bool gameInProgress = true;

    // While Loop for Input from both players until win
    updateBoard(choice, arr);

    while (gameInProgress) {
        printf("Player 1 Turn:");
        scanf("%d", &choice);

        choice--; // Adjust index since (1-9 input maps to 0-8

        if (choice < 0 || choice > 8 || arr[choice] == 'X' || arr[choice] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        arr[choice] = currentPlayer;
        updateBoard(choice, arr);

        if (checkWin(arr)) {
            printf("Player %c wins.\n", currentPlayer);
            gameInProgress = false;
        }
        else if (isDraw(arr)) {
            printf("It's a draw!\n");
            gameInProgress = false;
        }
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

    }
    return 0;
}