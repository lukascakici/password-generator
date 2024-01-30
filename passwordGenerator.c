#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random character
char generateRandomChar() {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";
    int index = rand() % (sizeof(charset) - 1);
    return charset[index];
}

// Function to generate a random password of a given length
void generatePassword(char *password, int length) {
    for (int i = 0; i < length; ++i) {
        password[i] = generateRandomChar();
    }
    password[length] = '\0';  // Null-terminate the string
}

// Function to save the password to a file
void savePasswordToFile(const char *filename, const char *password) {
    FILE *file = fopen(filename, "a"); // Open the file in append mode
    if (file != NULL) {
        fprintf(file, "%s\n", password);
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    int numPasswords;
    int passwordLength;
    char filename[50] = "passwords.txt";

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &numPasswords);

    printf("Enter the length of each password: ");
    scanf("%d", &passwordLength);


    for (int i = 0; i < numPasswords; ++i) {
        char password[passwordLength + 1];  // +1 for the null terminator
        generatePassword(password, passwordLength);
        printf("Generated Password: %s\n", password);
        savePasswordToFile(filename, password);
    }

    printf("Passwords saved to %s\n", filename);

    return 0;
}
