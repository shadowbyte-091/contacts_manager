#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 100

typedef struct {
    int id;
    char name[50];
    char phone[20];
} Contact;

// Function prototypes
void add_contact(Contact contacts[], int *count);
void list_contacts(Contact contacts[], int count);
int find_contact_index_by_id(Contact contacts[], int count, int id);
void update_contact_by_id(Contact contacts[], int count, int id);
void delete_contact_by_id(Contact contacts[], int *count, int id);

#endif
