#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void sudo_cp(const char *source, const char *destination) {
    char command[1024];
    snprintf(command, sizeof(command), "sudo cp %s %s", source, destination);
    system(command);
}

void cp(const char *source, const char *destination) {
    char command[1024];
    snprintf(command, sizeof(command), "cp %s %s", source, destination);
    system(command);
}

void sudo_cp_r(const char *source, const char *destination) {
    char command[1024];
    snprintf(command, sizeof(command), "sudo cp -r %s %s", source, destination);
    system(command);
}

void cp_r(const char *source, const char *destination) {
    char command[1024];
    snprintf(command, sizeof(command), "cp -r %s %s", source, destination);
    system(command);
}

const char* get_current_directory() {
    static char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return cwd;
    } else {
        perror("getcwd failed");
        return NULL;
    }
}

void install_pictures(const char *username) {
    const char *current_dir = get_current_directory();
    if (current_dir) {
        printf("Installing Pictures...\n");
        char source[1024];
        snprintf(source, sizeof(source), "%s/Pictures", current_dir);
        char destination[1024];
        snprintf(destination, sizeof(destination), "/home/%s/Pictures", username);
        cp_r(source, destination);
    }
}

void install_dotfiles(const char *username) {
    const char *current_dir = get_current_directory();
    if (current_dir) {
        printf("Installing .bashrc and .vimrc...\n");
        char source_bashrc[1024];
        snprintf(source_bashrc, sizeof(source_bashrc), "%s/.bashrc", current_dir);
        char destination_bashrc[1024];
        snprintf(destination_bashrc, sizeof(destination_bashrc), "/home/%s/.bashrc", username);
        cp(source_bashrc, destination_bashrc);

        char source_vimrc[1024];
        snprintf(source_vimrc, sizeof(source_vimrc), "%s/.vimrc", current_dir);
        char destination_vimrc[1024];
        snprintf(destination_vimrc, sizeof(destination_vimrc), "/home/%s/.vimrc", username);
        cp(source_vimrc, destination_vimrc);
    }
}

void install_pacman_conf(const char *username) {
    const char *current_dir = get_current_directory();
    if (current_dir) {
        printf("Installing pacman.conf...\n");
        char source[1024];
        snprintf(source, sizeof(source), "%s/pacman.conf", current_dir);
        char destination[1024];
        snprintf(destination, sizeof(destination), "/home/%s/pacman.conf", username);
        sudo_cp(source, destination);
    }
}

void install_cpupower(const char *username) {
    const char *current_dir = get_current_directory();
    if (current_dir) {
        printf("Installing cpupower...\n");
        char source[1024];
        snprintf(source, sizeof(source), "%s/cpupower", current_dir);
        char destination[1024];
        snprintf(destination, sizeof(destination), "/home/%s/cpupower", username);
        sudo_cp(source, destination);
    }
}

void install_config_files(const char *username) {
    const char *current_dir = get_current_directory();
    if (current_dir) {
        printf("Installing config files (nwg-panel, nwg-drawer, nwg-bar, MangoHud, hypr)...\n");
        char source_nwg_panel[1024];
        snprintf(source_nwg_panel, sizeof(source_nwg_panel), "%s/nwg-panel", current_dir);
        char destination_nwg_panel[1024];
        snprintf(destination_nwg_panel, sizeof(destination_nwg_panel), "/home/%s/.config/nwg-panel", username);
        cp_r(source_nwg_panel, destination_nwg_panel);

        char source_nwg_drawer[1024];
        snprintf(source_nwg_drawer, sizeof(source_nwg_drawer), "%s/nwg-drawer", current_dir);
        char destination_nwg_drawer[1024];
        snprintf(destination_nwg_drawer, sizeof(destination_nwg_drawer), "/home/%s/.config/nwg-drawer", username);
        cp_r(source_nwg_drawer, destination_nwg_drawer);

        char source_nwg_bar[1024];
        snprintf(source_nwg_bar, sizeof(source_nwg_bar), "%s/nwg-bar", current_dir);
        char destination_nwg_bar[1024];
        snprintf(destination_nwg_bar, sizeof(destination_nwg_bar), "/home/%s/.config/nwg-bar", username);
        cp_r(source_nwg_bar, destination_nwg_bar);

        char source_MangoHud[1024];
        snprintf(source_MangoHud, sizeof(source_MangoHud), "%s/MangoHud", current_dir);
        char destination_MangoHud[1024];
        snprintf(destination_MangoHud, sizeof(destination_MangoHud), "/home/%s/.config/MangoHud", username);
        cp_r(source_MangoHud, destination_MangoHud);

        char source_hypr[1024];
        snprintf(source_hypr, sizeof(source_hypr), "%s/hypr", current_dir);
        char destination_hypr[1024];
        snprintf(destination_hypr, sizeof(destination_hypr), "/home/%s/.config/hypr", username);
        cp_r(source_hypr, destination_hypr);
    }
}

void install_nwg_hello(const char *username) {
    const char *current_dir = get_current_directory();
    if (current_dir) {
        printf("Installing nwg-hello...\n");
        char source[1024];
        snprintf(source, sizeof(source), "%s/nwg-hello", current_dir);
        char destination[1024];
        snprintf(destination, sizeof(destination), "/home/%s/.config/nwg-hello", username);
        sudo_cp_r(source, destination);
    }
}

void install_girl_png(const char *username) {
    const char *current_dir = get_current_directory();
    if (current_dir) {
        printf("Installing girl.png...\n");
        char source[1024];
        snprintf(source, sizeof(source), "%s/Pictures/girl.png", current_dir);
        
        // Ensure the destination path is correct
        char destination[1024];
        snprintf(destination, sizeof(destination), "/usr/share/nwg-hello/girl.png");
        
        // Ensure sudo is used for copying to a system directory
        char command[1024];
        snprintf(command, sizeof(command), "sudo cp %s %s", source, destination);
        
        // Execute the sudo command
        int result = system(command);
        if (result != 0) {
            printf("Failed to install girl.png. You may need to run the script as root.\n");
        } else {
            printf("girl.png successfully installed to /usr/share/nwg-hello/\n");
        }
    }
}

int main() {
    char username[256];
    printf("Enter your username: ");
    scanf("%s", username);
    
    // Clear the input buffer
    while (getchar() != '\n');
    
    // Display options for installation
    printf("Welcome to the Dotfiles Installer!\n");
    printf("Choose the components to install (separate by space, e.g., 1 5 6):\n");
    printf("1. Install Pictures\n");
    printf("2. Install .bashrc and .vimrc\n");
    printf("3. Install pacman.conf\n");
    printf("4. Install cpupower\n");
    printf("5. Install nwg-panel, nwg-drawer, nwg-bar, MangoHud, hypr\n");
    printf("6. Install nwg-hello\n");
    
    // Read multiple component numbers
    char input[1024];
    printf("Enter the numbers separated by spaces: ");
    fgets(input, sizeof(input), stdin);
    
    // Parse the input string
    char *token = strtok(input, " ");
    while (token != NULL) {
        int choice = atoi(token);
        switch (choice) {
            case 1:
                install_pictures(username);
                break;
            case 2:
                install_dotfiles(username);
                break;
            case 3:
                install_pacman_conf(username);
                break;
            case 4:
                install_cpupower(username);
                break;
            case 5:
                install_config_files(username);
                break;
            case 6:
                install_nwg_hello(username);
                install_girl_png(username);
                break;
            default:
                printf("Invalid choice: %d\n", choice);
                break;
        }
        token = strtok(NULL, " ");
    }
    
    printf("\033[31mI\033[33mn\033[32ms\033[34mt\033[35ma\033[36ml\033[31ma\033[33mt\033[32me\033[34md \033[35mC\033[36mo\033[31ml\033[33mo\033[32mr \033[34mT\033[35me\033[36mx\033[31mt!\n");

    getchar(); // Wait for user to press Enter
    return 0;
}
