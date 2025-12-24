#include <stdio.h>
#include <string.h>
#include "../include/contacts.h"

char first_names[500][50];
char last_names[500][50];
char emails[500][100];
char phone_numbers[500][20];
int ids[500];
int count = 0;

void add_contact() {
    if (count >= 500) {
        printf("Contact limit reached.\n");
        return;
    }

    printf("First name: ");
    scanf("%49s", first_names[count]);

    printf("Last name: ");
    scanf("%49s", last_names[count]);

    printf("Phone number: ");
    scanf("%19s", phone_numbers[count]);

    printf("Email: ");
    scanf("%99s", emails[count]);

    if (count == 0)
        ids[count] = 1;
    else
        ids[count] = ids[count - 1] + 1;

    count++;

    printf("Contact added successfully.\n");
}

void list_contacts() {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\nID | First Name | Last Name | Phone | Email\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d | %s | %s | %s | %s\n",
               ids[i],
               first_names[i],
               last_names[i],
               phone_numbers[i],
               emails[i]);
    }
}

int find_contact_index_by_id(int id) {
    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}

void update_contact_by_id(int id) {
    int index = find_contact_index_by_id(id);

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    printf("Updating contact ID %d\n", id);

    printf("New first name: ");
    scanf("%49s", first_names[index]);

    printf("New last name: ");
    scanf("%49s", last_names[index]);

    printf("New phone number: ");
    scanf("%19s", phone_numbers[index]);

    printf("New email: ");
    scanf("%99s", emails[index]);

    printf("Contact updated successfully.\n");
}

void delete_contact_by_id(int id) {
    int index = find_contact_index_by_id(id);

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(first_names[i], first_names[i + 1]);
        strcpy(last_names[i], last_names[i + 1]);
        strcpy(phone_numbers[i], phone_numbers[i + 1]);
        strcpy(emails[i], emails[i + 1]);
    }

    count--;

    printf("Contact deleted successfully.\n");
}

