#include <stdio.h>
#include <string.h>
#include "contacts.h"

// ADD CONTACT
void add_contact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    Contact new_contact;
    new_contact.id = *count + 1;

    printf("Enter name: ");
    scanf("%49s", new_contact.name);

    printf("Enter phone: ");
    scanf("%19s", new_contact.phone);

    contacts[*count] = new_contact;
    (*count)++;

    printf("Contact added.\n");
}

// LIST CONTACTS
void list_contacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts.\n");
        return;
    }

    printf("\nCONTACT LIST:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Phone: %s\n",
               contacts[i].id,
               contacts[i].name,
               contacts[i].phone);
    }
}

// FIND INDEX BY ID
int find_contact_index_by_id(Contact contacts[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (contacts[i].id == id) {
            return i;
        }
    }
    return -1;
}

// UPDATE CONTACT
void update_contact_by_id(Contact contacts[], int count, int id) {
    int index = find_contact_index_by_id(contacts, count, id);

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%49s", contacts[index].name);

    printf("Enter new phone: ");
    scanf("%19s", contacts[index].phone);

    printf("Update successful.\n");
}

// DELETE CONTACT
void delete_contact_by_id(Contact contacts[], int *count, int id) {
    int index = find_contact_index_by_id(contacts, *count, id);

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    for (int i = index; i < (*count) - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    (*count)--;

    printf("Deleted.\n");
}}
