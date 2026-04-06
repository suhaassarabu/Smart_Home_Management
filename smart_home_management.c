#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Device Structure (Tree Node)
struct Device {
    int id;
    char name[50];
    char status[10]; // ON / OFF
    struct Device *left, *right;
};

// Create a new device node
struct Device* createDevice(int id, char name[], char status[]) {
    struct Device* newNode = (struct Device*)malloc(sizeof(struct Device));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->status, status);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert device (BST)
struct Device* insert(struct Device* root, int id, char name[], char status[]) {
    if (root == NULL)
        return createDevice(id, name, status);

    if (id < root->id)
        root->left = insert(root->left, id, name, status);
    else if (id > root->id)
        root->right = insert(root->right, id, name, status);
    else
        printf("Device with ID %d already exists!\n", id);

    return root;
}

// Display devices (Inorder Traversal)
void display(struct Device* root) {
    if (root != NULL) {
        display(root->left);
        printf("ID: %d | Name: %s | Status: %s\n", root->id, root->name, root->status);
        display(root->right);
    }
}

// Search device
struct Device* search(struct Device* root, int id) {
    if (root == NULL || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);
    else
        return search(root->right, id);
}

// Find minimum node (used in delete)
struct Device* findMin(struct Device* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete device
struct Device* deleteDevice(struct Device* root, int id) {
    if (root == NULL) {
        printf("Device not found!\n");
        return root;
    }

    if (id < root->id)
        root->left = deleteDevice(root->left, id);
    else if (id > root->id)
        root->right = deleteDevice(root->right, id);
    else {
        // Node found
        if (root->left == NULL) {
            struct Device* temp = root->right;
            free(root);
            printf("Device deleted successfully!\n");
            return temp;
        }
        else if (root->right == NULL) {
            struct Device* temp = root->left;
            free(root);
            printf("Device deleted successfully!\n");
            return temp;
        }

        // Node with two children
        struct Device* temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        strcpy(root->status, temp->status);
        root->right = deleteDevice(root->right, temp->id);
    }
    return root;
}

// Update device
void update(struct Device* root, int id) {
    struct Device* temp = search(root, id);

    if (temp == NULL) {
        printf("Device not found!\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", temp->name);

    printf("Enter new status (ON/OFF): ");
    scanf("%s", temp->status);

    printf("Device updated successfully!\n");
}

// MAIN FUNCTION
int main() {
    struct Device* root = NULL;
    int choice, id;
    char name[50], status[10];

    while (1) {
        printf("\n====== Smart Home Management System ======\n");
        printf("1. Add Device\n");
        printf("2. Delete Device\n");
        printf("3. Update Device\n");
        printf("4. Search Device\n");
        printf("5. Display Devices\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Device ID: ");
                scanf("%d", &id);
                printf("Enter Device Name: ");
                scanf("%s", name);
                printf("Enter Status (ON/OFF): ");
                scanf("%s", status);
                root = insert(root, id, name, status);
                break;

            case 2:
                printf("Enter Device ID to delete: ");
                scanf("%d", &id);
                root = deleteDevice(root, id);
                break;

            case 3:
                printf("Enter Device ID to update: ");
                scanf("%d", &id);
                update(root, id);
                break;

            case 4: {
                printf("Enter Device ID to search: ");
                scanf("%d", &id);
                struct Device* result = search(root, id);
                if (result != NULL)
                    printf("Found -> ID: %d | Name: %s | Status: %s\n", result->id, result->name, result->status);
                else
                    printf("Device not found!\n");
                break;
            }

            case 5:
                printf("\n--- Device List (Sorted by ID) ---\n");
                display(root);
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}