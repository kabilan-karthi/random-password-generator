#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void generatePassword(int length, int numDigits, int numSpecialChars) {
    // Define character sets for different types of characters
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char specialChars[] = "!@#$%^&*()_+{}[]<>?";

    // Calculate the number of letters required
    int numLetters = length - numDigits - numSpecialChars;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < numLetters; i++) {
        int type = rand() % 2;  // Randomly choose between lowercase and uppercase
        if (type == 0) {
            printf("%c", lowercase[rand() % 26]);
        } else {
            printf("%c", uppercase[rand() % 26]);
        }
    }
    for (int i = 0; i < numDigits; i++) {
        printf("%c", digits[rand() % 10]);
    }
    for (int i = 0; i < numSpecialChars; i++) {
        printf("%c", specialChars[rand() % 16]);
    }
    printf("\n");
}

int main() {
    int length, numDigits, numSpecialChars;

    printf("Enter the length of the password: ");
    scanf("%d", &length);

    printf("Enter the number of digits in the password: ");
    scanf("%d", &numDigits);

    printf("Enter the number of special characters in the password: ");
    scanf("%d", &numSpecialChars);

    // Generate and print the password
    generatePassword(length, numDigits, numSpecialChars);

    return 0;
}
