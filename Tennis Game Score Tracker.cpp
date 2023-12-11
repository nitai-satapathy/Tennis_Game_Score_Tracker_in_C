#include <stdio.h>

// Structure to represent a tennis player
struct Player {
    char name[50];
    int gamesWon;
    int matchesWon;
};

// Function to display the current game score
void displayScore(int player1Score, int player2Score) {
    printf("Current Game Score:\n");
    printf("Player 1: %d  Player 2: %d\n", player1Score, player2Score);
}

int main() {
    // Initialize players
    struct Player player1, player2;
    player1.gamesWon = 0;
    player1.matchesWon = 0;
    player2.gamesWon = 0;
    player2.matchesWon = 0;

    int player1Score = 0, player2Score = 0;
    int matchesPlayed = 0;

    printf("Enter Player 1's Name: ");
    scanf("%s", player1.name);
    printf("Enter Player 2's Name: ");
    scanf("%s", player2.name);

    while (1) {
        int choice;
        printf("\nSelect an option:\n");
        printf("1. Player 1 scores a point\n");
        printf("2. Player 2 scores a point\n");
        printf("3. End game\n");
        scanf("%d", &choice);

        if (choice == 1) {
            player1Score++;
        } else if (choice == 2) {
            player2Score++;
        } else if (choice == 3) {
            // End the current game
            if (player1Score > player2Score) {
                player1.gamesWon++;
                printf("%s wins the game!\n", player1.name);
            } else if (player2Score > player1Score) {
                player2.gamesWon++;
                printf("%s wins the game!\n", player2.name);
            } else {
                printf("It's a tie!\n");
            }

            // Reset scores for the next game
            player1Score = 0;
            player2Score = 0;

            // Display player statistics
            printf("\nPlayer Statistics:\n");
            printf("%s: %d games won\n", player1.name, player1.gamesWon);
            printf("%s: %d games won\n", player2.name, player2.gamesWon);

            // Update overall match score
            if (player1.gamesWon > player2.gamesWon) {
                player1.matchesWon++;
            } else if (player2.gamesWon > player1.gamesWon) {
                player2.matchesWon++;
            }

            // Display overall match score
            printf("Overall Match Score:\n");
            printf("%s: %d matches won\n", player1.name, player1.matchesWon);
            printf("%s: %d matches won\n", player2.name, player2.matchesWon);

            // Ask if the players want to continue
            char playAgain;
            printf("Do you want to play another game? (y/n): ");
            scanf(" %c", &playAgain);

            if (playAgain != 'y') {
                printf("Thanks for playing!\n");
                break; // Exit the program
            }
        }

        // Display the current game score
        displayScore(player1Score, player2Score);
    }

    return 0;
}
