#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phoneNumber[20];
    char email[50];
};

struct Contact phonebook[MAX_CONTACTS];
int numContacts = 0;

void addContact(const char* name, const char* phoneNumber, const char* email) {
    if (numContacts < MAX_CONTACTS) {
        strcpy(phonebook[numContacts].name, name);
        strcpy(phonebook[numContacts].phoneNumber, phoneNumber);
        strcpy(phonebook[numContacts].email, email);
        numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Phonebook is full. Cannot add more contacts.\n");
    }
}

void searchContact(const char* name) {
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone Number: %s\n", phonebook[i].phoneNumber);
            printf("Email: %s\n", phonebook[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts() {
    if (numContacts == 0) {
        printf("Phonebook is empty.\n");
    } else {
        printf("Phonebook contacts:\n");
        for (int i = 0; i < numContacts; i++) {
            printf("Contact %d:\n", i + 1);
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone Number: %s\n", phonebook[i].phoneNumber);
            printf("Email: %s\n", phonebook[i].email);
        }
    }
}

void deleteContact(const char* name) {
    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            found = 1;
            // Shift all contacts after the deleted contact to the left
            for (int j = i; j < numContacts - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j + 1].name);
                strcpy(phonebook[j].phoneNumber, phonebook[j + 1].phoneNumber);
                strcpy(phonebook[j].email, phonebook[j + 1].email);
            }
            numContacts--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    while(1){
        displayContacts();
        printf("\nTo add contact, type 1\n");
        printf("To search contact, type 2\n");
        printf("To delete contact, type 3\n");
        printf("To quit, type 0\n");
        printf("and press Enter.\n");
        int key;
        if (scanf("%d", &key) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter an integer number.\n");
            return 1; // Indicate error
        }
        getchar();
        if (key == 1) {
            char name[50];
            printf("Enter name: ");
            fgets(name, 50, stdin);
            size_t ln = strlen(name)-1;
            if (name[ln] == '\n')
                name[ln] = '\0';
            printf("Enter %s phone number: ", name);
            char num[50]; scanf( "%s]", num);
            printf("Enter %s Email address: ", name);
            char email[50]; scanf( "%s]", email);
            addContact(name, num, email);
        }else if (key == 2) {
            printf("Enter name: ");
            char name[50]; fgets(name, 50, stdin);
            searchContact(name);
        }else if (key == 3) {
            printf("Enter name: ");
            char name[50]; fgets(name, 50, stdin);
            deleteContact(name);
        }else   break;
    }
    printf("End of program!");
    return 0;
}
