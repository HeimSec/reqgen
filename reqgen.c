#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define FILENAME "requirements.txt"
#define PIP_COMMAND "pip freeze"

// Define error codes
#define ERROR_PIP_OPEN 1
#define ERROR_FILE_OPEN 2

// Function to display ANSI color constants
void displayColorConstants() {
    printf(
        "# Reset\n"
        "Color_Off=\"\\033[0m\"       # Text Reset\n\n"
        // Include the rest of the color constants here
    );
}

// Function to display the welcome message and menu
void displayWelcomeMessage() {
    printf(
        "\033[1;31m"  // Red color
        "888d888 .d88b.   .d88888  .d88b.   .d88b.  88888b.  \n"
        "888P   d8P  Y8b d88  888 d88P 88b d8P  Y8b 888  88b \n"
        "888    88888888 888  888 888  888 88888888 888  888 \n"
        "888    Y8b.     Y88b 888 Y88b 888 Y8b.     888  888 \n"
        "888      Y8888    Y88888   Y88888   Y8888  888  888 \n"
        "                     888      888                   \n"
        "                     888 Y8b d88P                   \n"
        "                     888   Y88P                     \n"
        "\033[0m"  // Reset color
    );

    printf(
        "Welcome to reqgen - Python Requirements Generator\n"
        "This utility generates a 'requirements.txt' file listing installed Python packages.\n"
        "Please choose and type one of the following commands:\n"
        "1. Analyze (Show total count of all installed dependencies)\n"
        "2. Create (Generate 'requirements.txt' file)\n"
        "3. Exit (Exit the program or simply press Ctrl+C to exit...)\n"
    );
}

int main(int argc, char *argv[]) {
    int displayColors = 0;

    // Check if the --ansi_colors flag is provided
    if (argc > 1 && (strcmp(argv[1], "--ansi_colors") == 0 || strcmp(argv[1], "-c") == 0)) {
        displayColors = 1;
    }

    if (displayColors) {
        displayColorConstants();
        return 0;
    }

    char choice[10];

    displayWelcomeMessage();

    while (1) {
        printf("Enter your choice: ");
        fgets(choice, sizeof(choice), stdin);
        choice[strlen(choice) - 1] = '\0'; // Remove the newline character

        // Make the user input case-insensitive
        for (int i = 0; choice[i]; i++) {
            choice[i] = tolower(choice[i]);
        }

        if (strcmp(choice, "1") == 0 || strcmp(choice, "analyze") == 0 || strcmp(choice, "i") == 0 || strcmp(choice, "info") == 0) {
            // Analyze command
            FILE *fp;
            char line[BUFFER_SIZE];
            int dependencyCount = 0;

            // Open a pipe to execute the pip freeze command
            fp = popen(PIP_COMMAND, "r");
            if (fp == NULL) {
                perror("Failed to run 'pip freeze' command");
                return ERROR_PIP_OPEN;
            }

            // Count the dependencies
            while (fgets(line, sizeof(line), fp) != NULL) {
                dependencyCount++;
            }

            // Close the pipe
            pclose(fp);

            // Display the total count of installed dependencies
            printf("Total installed dependencies: %d\n", dependencyCount);
        } else if (strcmp(choice, "2") == 0 || strcmp(choice, "create") == 0) {

            // Create command
            // Developer comment
            const char *developer_comment =
                "# Developer: Brainhub24\n"
                "# Tool: reqgen - Python Requirements Generator (v1.0)\n"
                "# GitHub Repository: https://github.com/brainhub24/reqgen\n"
                "# Developer Mail: github@brainhub24.com\n"
                "# Disclaimer: This file was generated using reqgen, a tool to list installed Python packages in your environment.\n";

            // Use the system function to run "pip freeze" and capture its output
            FILE *fp;
            char line[BUFFER_SIZE];

            // Open a pipe to execute the pip freeze command
            fp = popen(PIP_COMMAND, "r");
            if (fp == NULL) {
                perror("Failed to run 'pip freeze' command");
                return ERROR_PIP_OPEN;
            }

            // Create and open the requirements.txt file
            FILE *requirements_file = fopen(FILENAME, "w");
            if (requirements_file == NULL) {
                perror("Failed to create " FILENAME " file");
                pclose(fp); // Close the pipe
                return ERROR_FILE_OPEN;
            }

            // Write the developer comment to the requirements.txt file
            fprintf(requirements_file, "%s\n", developer_comment);

            // Read the output of "pip freeze" and write it to requirements.txt
            while (fgets(line, sizeof(line), fp) != NULL) {
                fprintf(requirements_file, "%s", line);
            }

            // Close the files and the pipe
            fclose(requirements_file);
            pclose(fp);

            printf(FILENAME " generated successfully.\n");
        } else if (strcmp(choice, "3") == 0 || strcmp(choice, "exit") == 0) {
            // Exit command
            printf("Thank you for using this developer tool! Have a creative and productive day!\n");
            break;
        } else {
            printf("Invalid choice. Please choose a valid command.\n");
        }
    }

    return 0;
}
