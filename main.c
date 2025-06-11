#include <stdbool.h>
#include <stdio.h>


struct Game {
    char arr[9];
    int choice;
    char currentPlayer;
    bool gameInProgress;
};

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

    struct Game game = {{'1','2','3','4','5','6','7','8','9'},
        -1,
        'X',
        true};

    // While Loop for Input from both players until win
    updateBoard(game.choice, game.arr);

    while (game.gameInProgress) {
        printf("Player %c Turn:", game.currentPlayer);
        scanf("%d", &game.choice);

        game.choice--; // Adjust index since (1-9 input maps to 0-8

        if (game.choice < 0 || game.choice > 8 || game.arr[game.choice] == 'X' || game.arr[game.choice] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        game.arr[game.choice] = game.currentPlayer;
        updateBoard(game.choice, game.arr);

        if (checkWin(game.arr)) {
            printf("Player %c wins.\n", game.currentPlayer);
            game.gameInProgress = false;
        }
        else if (isDraw(game.arr)) {
            printf("It's a draw!\n");
            game.gameInProgress = false;
        }
        else {
            game.currentPlayer = (game.currentPlayer == 'X') ? 'O' : 'X';
        }

    }
    return 0;
}