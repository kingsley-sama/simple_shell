#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int search_file(const char *dir_path, const char *file_name) {
    DIR *dir = opendir(dir_path);

    if (dir == NULL) {
        perror("Error opening directory");
        return -1;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, file_name) == 0) {
            printf("File found: %s\n", entry->d_name);
            closedir(dir);
            return 0;
        }
    }

    printf("File not found: %s\n", file_name);
    closedir(dir);
    return -1;
}

int search_file_in_path(const char *file_name) {
    char *path_env = getenv("PATH");
    
    if (path_env == NULL) {
        fprintf(stderr, "Error: PATH environment variable not set.\n");
        return -1;
    }

    char *path = strtok(path_env, ":");

    while (path != NULL) {
        if (search_file(path, file_name) == 0) {
            return 0;  // File found in this directory, stop searching
        }

        path = strtok(NULL, ":");
    }

    return -1;  // File not found in any directory in the PATH
}

int main() {
    const char *file_to_search = "ls";

    if (search_file_in_path(file_to_search) == 0) {
	    
    } else {
        printf("File not found in the PATH.\n");
    }

    return 0;
}
