#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "../include/file_io.h"
#include "../include/contacts.h"

#define MAX_LINE 256

static void get_csv_path(char *path) {
    char *home = getenv("HOME");
    sprintf(path, "%s/.local/share/contact_manager/contacts.csv", home);
}

static void ensure_directory_exists() {
    char *home = getenv("HOME");
    char dir_path[256];

    sprintf(dir_path, "%s/.local/share/contact_manager", home);

    struct stat st = {0};
    if (stat(dir_path, &st) == -1) {
        mkdir(dir_path, 0700);
    }
}

void load_contacts_from_file() {
    ensure_directory_exists();

    char path[256];
    get_csv_path(path);

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return;
    }

    char line[MAX_LINE];

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        if (count >= 500) break;

        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, ",");
        if (!token) continue;
        ids[count] = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(first_names[count], token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(last_names[count], token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(phone_numbers[count], token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strcpy(emails[count], token);

        count++;
    }

    fclose(file);
}

void save_contacts_to_file() {
    ensure_directory_exists();

    char path[256];
    get_csv_path(path);

    FILE *file = fopen(path, "w");
    if (file == NULL) {
        return;
    }

    fprintf(file, "id,first_name,last_name,phone_number,email\n");

    for (int i = 0; i < count; i++) {
        fprintf(
            file,
            "%d,%s,%s,%s,%s\n",
            ids[i],
            first_names[i],
            last_names[i],
            phone_numbers[i],
            emails[i]
        );
    }

    fclose(file);
}

