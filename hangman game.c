#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD_LENGTH 100

void display_hangman(int tries) {
    switch (tries) {
        case 6: printf("  -----\n  |   |\n  |\n  |\n  |\n  |\n"); break;
        case 5: printf("  -----\n  |   |\n  |   O\n  |\n  |\n  |\n"); break;
        case 4: printf("  -----\n  |   |\n  |   O\n  |   |\n  |\n  |\n"); break;
        case 3: printf("  -----\n  |   |\n  |   O\n  |  /|\n  |\n  |\n"); break;
        case 2: printf("  -----\n  |   |\n  |   O\n  |  /|\\\n  |\n  |\n"); break;
        case 1: printf("  -----\n  |   |\n  |   O\n  |  /|\\\n  |  /\n  |\n"); break;
        case 0: printf("  -----\n  |   |\n  |   O\n  |  /|\\\n  |  / \\\n  |\n"); break;
    }
}

int main() {
    char word[WORD_LENGTH], guessed[WORD_LENGTH], guess;
    int word_length, tries = MAX_TRIES, correct_guesses = 0;
int i;
    printf("Enter a word for Hangman: ");
    scanf("%s", word);
    word_length = strlen(word);
    for (i = 0; i < word_length; i++) {
        guessed[i] = '_'; // Initialize guessed letters
    }
    guessed[word_length] = '\0'; // Null-terminate the string

    while (tries > 0 && correct_guesses < word_length) {
        printf("\n%s\n", guessed);
        display_hangman(tries);
        printf("You have %d tries left. Guess a letter: ", tries);
        scanf(" %c", &guess);
        guess = tolower(guess); // Convert to lowercase

        int found = 0;
        for (i = 0; i < word_length; i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                correct_guesses++;
                found = 1;
            }
        }

        if (!found) {
            tries--;
            printf("Wrong guess! '%c' is not in the word.\n", guess);
        } else {
            printf("Good guess! '%c' is in the word.\n", guess);
        }
    }

    if (correct_guesses == word_length) {
        printf("Congratulations! You've guessed the word: %s\n", word);
    } else {
        printf("Game over! The word was: %s\n", word);
    }

    return 0;
}

