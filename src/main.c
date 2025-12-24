#include <stdio.h>
#include <stdlib.h>
#include "../include/contacts.h"
#include "../include/file_io.h"

void show_menu() {
    printf("\n=== Contact Manager ===\n");
    printf("1. Add Contact\n");
    printf("2. List Contacts\n");
    printf("3. View Contact by ID\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

int main() {
    load_contacts_from_file();

    int choice;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        if (choice == 1) add_contact();
        else if (choice == 2) list_contacts();
        else if (choice == 3) {
            int id;
            printf("Enter ID: ");
            scanf("%d", &id);
            int index = find_contact_index_by_id(id);
            if (index == -1) printf("Contact not found.\n");
            else {
                printf("\nID: %d\n", ids[index]);
                printf("Name: %s %s\n", first_names[index], last_names[index]);
                printf("Phone: %s\n", phone_numbers[index]);
                printf("Email: %s\n", emails[index]);
            }
        }
        else if (choice == 4) {
            int id;
            printf("Enter ID to update: ");
            scanf("%d", &id);
            update_contact_by_id(id);
        }
        else if (choice == 5) {
            int id;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            delete_contact_by_id(id);
        }
        else if (choice == 6) {
            save_contacts_to_file();
            printf("Saved. Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

