#ifndef CONTACTS_H
#define CONTACTS_H

// Global arrays (declared here, defined in contacts.c)
extern char first_names[500][50];
extern char last_names[500][50];
extern char emails[500][100];
extern char phone_numbers[500][20];
extern int ids[500];
extern int count;

// CRUD function declarations
void add_contact();
void list_contacts();
int find_contact_index_by_id(int id);
void update_contact_by_id(int id);
void delete_contact_by_id(int id);

#endif

