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

bool checkWin(char arr[9]) {
    // Check rows
    for (int i = 0; i <= 6; i += 3) {
        if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2]) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (arr[i] == arr[i + 3] && arr[i + 3] == arr[i + 6]) {
            return true;
        }
    }

    // Check diagonals
    if ((arr[0] == arr[4] && arr[4] == arr[8]) ||
        (arr[2] == arr[4] && arr[4] == arr[6])) {
        return true;
    }

    return false;
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
    boardPrint(game.arr);

    while (game.gameInProgress) {
        printf("Player %c Turn: ", game.currentPlayer);

        // Validate input
        if (scanf("%d", &game.choice) != 1) {
            printf("Invalid input. Please enter a number from 1 to 9.\n");
            while (getchar() != '\n'); // Clear invalid input from buffer
            continue;
        }

        game.choice--; // Adjust index since (1-9 input maps to 0-8)

        if (game.choice < 0 || game.choice > 8 || game.arr[game.choice] == 'X' || game.arr[game.choice] == 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        game.arr[game.choice] = game.currentPlayer;
        boardPrint(game.arr);

        if (checkWin(game.arr)) {
            printf("Player %c wins.\n", game.currentPlayer);
            game.gameInProgress = false;
        }
        else if (isDraw(game.arr)) {
            printf("It's a draw!\n");
            game.gameInProgress = false;
        }
        else {
            game.currentPlayer = (game.currentPlayer == 'X') ? 'O' : 'X'; // Each turn—if it's 'X', it becomes 'O', and vice versa.
        }
    }

    return 0;
}