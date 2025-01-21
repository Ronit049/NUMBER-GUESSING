#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a range
int generateRandomNumber(int lower, int upper) {
    srand(time(0)); // Seed for random number generation
    return (rand() % (upper - lower + 1)) + lower;
}

int main() {
    int lower = 1, upper = 100, maxAttempts = 7;
    int randomNumber, playerGuess, attempts = 0;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between %d and %d. Can you guess it?\n", lower, upper);
    printf("You have %d attempts. Let's begin!\n\n", maxAttempts);

    // Generate the random number
    randomNumber = generateRandomNumber(lower, upper);

    // Start the game loop
    while (attempts < maxAttempts) {
        printf("Enter your guess: ");
        scanf("%d", &playerGuess);

        attempts++;

        if (playerGuess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (playerGuess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

        if (attempts == maxAttempts) {
            printf("Sorry, you've used all %d attempts. The number was %d. Better luck next time!\n", maxAttempts, randomNumber);
        }
    }

    printf("\nThank you for playing the Number Guessing Game. Goodbye!\n");
    return 0;
}
