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
        "# Regular Colors\n"
        "Black=\"\\033[0;30m\"        # Black\n"
        "Red=\"\\033[0;31m\"          # Red\n"
        "Green=\"\\033[0;32m\"        # Green\n"
        "Yellow=\"\\033[0;33m\"       # Yellow\n"
        "Blue=\"\\033[0;34m\"         # Blue\n"
        "Purple=\"\\033[0;35m\"       # Purple\n"
        "Cyan=\"\\033[0;36m\"         # Cyan\n"
        "White=\"\\033[0;37m\"        # White\n\n"
        "# Bold\n"
        "BBlack=\"\\033[1;30m\"       # Black\n"
        "BRed=\"\\033[1;31m\"         # Red\n"
        "BGreen=\"\\033[1;32m\"       # Green\n"
        "BYellow=\"\\033[1;33m\"      # Yellow\n"
        "BBlue=\"\\033[1;34m\"        # Blue\n"
        "BPurple=\"\\033[1;35m\"      # Purple\n"
        "BCyan=\"\\033[1;36m\"        # Cyan\n"
        "BWhite=\"\\033[1;37m\"       # White\n\n"
        "# Underline\n"
        "UBlack=\"\\033[4;30m\"       # Black\n"
        "URed=\"\\033[4;31m\"         # Red\n"
        "UGreen=\"\\033[4;32m\"       # Green\n"
        "UYellow=\"\\033[4;33m\"      # Yellow\n"
        "UBlue=\"\\033[4;34m\"        # Blue\n"
        "UPurple=\"\\033[4;35m\"      # Purple\n"
        "UCyan=\"\\033[4;36m\"        # Cyan\n"
        "UWhite=\"\\033[4;37m\"       # White\n\n"
        "# Background\n"
        "On_Black=\"\\033[40m\"       # Black\n"
        "On_Red=\"\\033[41m\"         # Red\n"
        "On_Green=\"\\033[42m\"       # Green\n"
        "On_Yellow=\"\\033[43m\"      # Yellow\n"
        "On_Blue=\"\\033[44m\"        # Blue\n"
        "On_Purple=\"\\033[45m\"      # Purple\n"
        "On_Cyan=\"\\033[46m\"        # Cyan\n"
        "On_White=\"\\033[47m\"       # White\n\n"
        "# High Intensity\n"
        "IBlack=\"\\033[0;90m\"       # Black\n"
        "IRed=\"\\033[0;91m\"         # Red\n"
        "IGreen=\"\\033[0;92m\"       # Green\n"
        "IYellow=\"\\033[0;93m\"      # Yellow\n"
        "IBlue=\"\\033[0;94m\"        # Blue\n"
        "IPurple=\"\\033[0;95m\"      # Purple\n"
        "ICyan=\"\\033[0;96m\"        # Cyan\n"
        "IWhite=\"\\033[0;97m\"       # White\n\n"
        "# Bold High Intensity\n"
        "BIBlack=\"\\033[1;90m\"      # Black\n"
        "BIRed=\"\\033[1;91m\"        # Red\n"
        "BIGreen=\"\\033[1;92m\"      # Green\n"
        "BIYellow=\"\\033[1;93m\"     # Yellow\n"
        "BIBlue=\"\\033[1;94m\"       # Blue\n"
        "BIPurple=\"\\033[1;95m\"     # Purple\n"
        "BICyan=\"\\033[1;96m\"       # Cyan\n"
        "BIWhite=\"\\033[1;97m\"      # White\n\n"
        "# High Intensity Backgrounds\n"
        "On_IBlack=\"\\033[0;100m\"   # Black\n"
        "On_IRed=\"\\033[0;101m\"     # Red\n"
        "On_IGreen=\"\\033[0;102m\"   # Green\n"
        "On_IYellow=\"\\033[0;103m\"  # Yellow\n"
        "On_IBlue=\"\\033[0;104m\"    # Blue\n"
        "On_IPurple=\"\\033[10;95m\"  # Purple\n"
        "On_ICyan=\"\\033[0;106m\"    # Cyan\n"
        "On_IWhite=\"\\033[0;107m\"   # White\n"
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
