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

int main(void) {
    char arr[9] = {'*','*','*','*','*','*','*','*','*'};

    boardPrint(arr);
    return 0;
}