#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ice_cream {
    int id;
    char name[50];
    float price;
};
struct ice_cream_database {
    struct ice_cream *ice_creams;
    int count;};
void display_ice_creams(struct ice_cream_database *database);
void add_new_ice_cream(struct ice_cream_database *database);
void update_ice_cream(struct ice_cream_database *database);
void search_ice_cream(struct ice_cream_database *database);
void delete_ice_cream(struct ice_cream_database *database);
int main() {
    struct ice_cream_database database;
    database.count = 0;
    database.ice_creams = NULL;
int choice;
while (1) {
        printf("\nWelcome to Ice-cream Parlor Management System!\n");
        printf("1. Display Ice-creams list\n");
        printf("2. Add new ice-cream data\n");
        printf("3. Update the record of the ice-cream\n");
        printf("4. Search any ice-cream\n");
        printf("5. Delete any ice-cream record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
switch (choice) {
            case 1:
                display_ice_creams(&database);
                break;
            case 2:
                add_new_ice_cream(&database);
                break;
            case 3:
                update_ice_cream(&database);
                break;
            case 4:
                search_ice_cream(&database);
                break;
            case 5:
                delete_ice_cream(&database);
                break;
            case 6:
                printf("\nThank you for using Ice-cream Parlor Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void display_ice_creams(struct ice_cream_database *database) {
    if (database->count == 0) {
        printf("\nNo ice-cream data available!\n");
    } else {
        printf("\nIce-creams list:\n");
        printf("ID\tNAME\t\t\tPRICE\n");
        for(int i = 0;i < database -> count; i++) 
		{
            printf("%d\t%s\t\t%.2f\n", database->ice_creams[i].id, database->ice_creams[i].name, database->ice_creams[i].price);
        }
    }
}

void add_new_ice_cream(struct ice_cream_database *database) {
    database->count++;
    database->ice_creams = (struct ice_cream*)realloc(database->ice_creams, database->count * sizeof(struct ice_cream));
    database->ice_creams[database->count - 1].id = database->count;
    printf("\nEnter ice-cream name: ");
    scanf("%s", database->ice_creams[database->count - 1].name);
    printf("Enter ice-cream price: ");
    scanf("%f", &database->ice_creams[database->count - 1].price);
    printf("Ice-cream data added successfully!\n");
}
void update_ice_cream(struct ice_cream_database *database) {
    if (database->count == 0) {
        printf("\nNo ice-cream data available!\n");
    } else {
        int id;
        printf("\nEnter ice-cream ID to update: ");
        scanf("%d", &id);

        int found = 0;
        for (int i = 0; i < database->count; i++) {
            if (database->ice_creams[i].id == id) {
                printf("\nIce-cream data found:\n");
                printf("ID\tNAME\t\t\tPRICE\n");
                printf("%d\t%s\t\t%.2f\n", database->ice_creams[i].id, database->ice_creams[i].name, database->ice_creams[i].price);
                printf("\nEnter new name: ");
                scanf("%s", database->ice_creams[i].name);
                printf("Enter new price: ");
                scanf("%f", &database->ice_creams[i].price);
                printf("\nIce-cream data updated successfully!\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nIce-cream data not found!\n");
        }
    }
}
void search_ice_cream(struct ice_cream_database *database) {
    if (database->count == 0) {
        printf("\nNo ice-cream data available!\n");
    } else {
        int id;
        printf("\nEnter ice-cream ID to search: ");
        scanf("%d", &id);

        int found = 0;
        for (int i = 0; i < database->count; i++) {
            if (database->ice_creams[i].id == id) {
                printf("\nIce-cream data found:\n");
                printf("ID\tNAME\t\t\tPRICE\n");
                printf("%d\t%s\t\t%.2f\n", database->ice_creams[i].id, database->ice_creams[i].name, database->ice_creams[i].price);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nIce-cream data not found!\n");
        }
    }
}

void delete_ice_cream(struct ice_cream_database *database) {
    if (database->count == 0) {
        printf("\nNo ice-cream data available!\n");
    } else {
        int id;
        printf("\nEnter ice-cream ID to delete: ");
        scanf("%d", &id);

        int index = -1;
        for (int i = 0; i < database->count; i++) {
            if (database->ice_creams[i].id == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("\nIce-cream data not found!\n");
        } else {
            for (int i = index; i < database->count - 1; i++) {
                database->ice_creams[i] = database->ice_creams[i + 1];
            }
            database->count--;
            database->ice_creams = (struct ice_cream*)realloc(database->ice_creams, database->count * sizeof(struct ice_cream));
            printf("\nIce-cream data deleted successfully!\n");
        }
    }
}