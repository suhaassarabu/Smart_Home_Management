#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🌍 Smart Environment
int currentTemp = 30;
int isNight = 1;
int isUserHome = 1;

// 🔠 Convert to UPPERCASE
void toUpperCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

// ⚡ Auto Power Assignment
int getPower(char name[]) {
    if (strcmp(name, "AC") == 0) return 20;
    if (strcmp(name, "FAN") == 0) return 10;
    if (strcmp(name, "LIGHT") == 0) return 5;
    if (strcmp(name, "TV") == 0) return 15;
    if (strcmp(name, "FRIDGE") == 0) return 25;
    if (strcmp(name, "WASHER") == 0) return 30;
    if (strcmp(name, "HEATER") == 0) return 12;
    return 8;
}

// 🌳 Device Structure
struct Device {
    int id;
    char name[50];
    char status[10];
    char room[50];
    int power;
    int temperature;
    struct Device *left, *right;
};

// 🔹 Create Device
struct Device* createDevice(int id, char name[], char status[], char room[], int power) {
    struct Device* newNode = (struct Device*)malloc(sizeof(struct Device));

    // ✅ Memory safety check
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->status, status);
    strcpy(newNode->room, room);
    newNode->power = power;
    newNode->temperature = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 🔹 Insert (BST)
struct Device* insert(struct Device* root, int id, char name[], char status[], char room[], int power) {
    if (!root) return createDevice(id, name, status, room, power);

    if (id < root->id)
        root->left = insert(root->left, id, name, status, room, power);
    else if (id > root->id)
        root->right = insert(root->right, id, name, status, room, power);
    else
        printf(" Device ID already exists!\n");

    return root;
}

// 🔹 Display
void display(struct Device* root) {
    if (root) {
        display(root->left);
        printf("%d | %-15s | %-3s | %-10s | %d\n",
               root->id, root->name, root->status, root->room, root->power);
        display(root->right);
    }
}

// 🔹 Search
struct Device* search(struct Device* root, int id) {
    if (!root || root->id == id) return root;
    if (id < root->id) return search(root->left, id);
    return search(root->right, id);
}

// 🔹 Find Min
struct Device* findMin(struct Device* root) {
    while (root && root->left) root = root->left;
    return root;
}

// 🔹 Delete
struct Device* deleteDevice(struct Device* root, int id) {
    if (!root) return root;

    if (id < root->id)
        root->left = deleteDevice(root->left, id);
    else if (id > root->id)
        root->right = deleteDevice(root->right, id);
    else {
        if (!root->left) {
            struct Device* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Device* temp = root->left;
            free(root);
            return temp;
        }

        struct Device* temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        strcpy(root->status, temp->status);
        strcpy(root->room, temp->room);
        root->power = temp->power;

        root->right = deleteDevice(root->right, temp->id);
    }
    return root;
}

// 🔹 Update
void update(struct Device* root, int id) {
    struct Device* d = search(root, id);

    if (!d) {
        printf(" Device not found!\n");
        return;
    }

    char oldStatus[10];
    strcpy(oldStatus, d->status);  // backup old status

    printf("New Name: ");
    scanf("%s", d->name);
    toUpperCase(d->name);

    printf("New Status (ON/OFF): ");
    scanf("%s", d->status);
    toUpperCase(d->status);

    // ✅ Validate status
    if (strcmp(d->status, "ON") != 0 && strcmp(d->status, "OFF") != 0) {
        printf("Invalid status! Keeping old value.\n");
        strcpy(d->status, oldStatus);
    }

    printf("New Room: ");
    scanf("%s", d->room);
    toUpperCase(d->room);

    // ✅ Update power automatically if name changes
    d->power = getPower(d->name);

    printf(" Device updated successfully!\n");
}

// ⚡ Total Power
int totalPower(struct Device* root) {
    if (!root) return 0;

    int curr = (strcmp(root->status, "ON") == 0) ? root->power : 0;
    return curr + totalPower(root->left) + totalPower(root->right);
}

// 🤖 Smart Automation
void smartHomeControl(struct Device* root) {
    if (root) {
        smartHomeControl(root->left);

        if (!isUserHome) {
            strcpy(root->status, "OFF");
        } else {

            if (strcmp(root->name, "AC") == 0) {
                if (currentTemp > 28) {
                    strcpy(root->status, "ON");
                    root->temperature = 24;
                    currentTemp--;
                } else strcpy(root->status, "OFF");
            }

            if (strcmp(root->name, "FAN") == 0) {
                if (currentTemp > 26) strcpy(root->status, "ON");
                else strcpy(root->status, "OFF");
            }

            if (strcmp(root->name, "LIGHT") == 0) {
                if (isNight) strcpy(root->status, "ON");
                else strcpy(root->status, "OFF");
            }
        }

        smartHomeControl(root->right);
    }
}

// 🔹 Run Smart System
void runSmartSystem(struct Device* root) {
    printf("\n Smart System Activated...\n");

    smartHomeControl(root);

    int power = totalPower(root);
    printf(" Power Usage: %d units\n", power);

    printf(" Temp: %d°C | %s | User: %s\n",
           currentTemp,
           isNight ? "Night" : "Day",
           isUserHome ? "Home" : "Outside");

    printf("All Devices adjusted automatically!\n");
}

// 🚀 MAIN
int main() {
    struct Device* root = NULL;
    int ch, id, power;
    char name[50], status[10], room[50];

    // Sample Data
    root = insert(root, 10, "AC", "OFF", "BEDROOM", 20);
    root = insert(root, 5, "LIGHT", "OFF", "HALL", 5);
    root = insert(root, 15, "FAN", "OFF", "BEDROOM", 10);

    while (1) {
        printf("\n==== SMART HOME MENU ====\n");
        printf("1.Add\n2.Delete\n3.Update\n4.Search\n5.Display\n6.Smart System\n7.Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {

            case 1:
                printf("ID: "); scanf("%d", &id);

                printf("Name: "); scanf("%s", name);
                toUpperCase(name);

                printf("Status (ON/OFF): "); scanf("%s", status);
                toUpperCase(status);

                if (strcmp(status,"ON")!=0 && strcmp(status,"OFF")!=0){
                    printf(" Invalid status!\n"); break;
                }

                printf("Room: "); scanf("%s", room);
                toUpperCase(room);

                power = getPower(name);
                printf(" Power assigned: %d\n", power);

                root = insert(root, id, name, status, room, power);
                break;

            case 2:
                printf("ID: "); scanf("%d", &id);
                root = deleteDevice(root, id);
                break;

            case 3:
                printf("ID: "); scanf("%d", &id);
                update(root, id);
                break;

            case 4: {
                printf("ID: "); scanf("%d", &id);
                struct Device* d = search(root, id);
                if (d)
                    printf(" Found -> ID:%d | %s | %s | %s\n",
                           d->id, d->name, d->status, d->room);
                else
                    printf(" Not found!\n");
                break;
            }

            case 5:
                printf("\nID | Name           | Sts | Room       | Power\n");
                printf("------------------------------------------------\n");
                display(root);
                printf("\n");
                break;

            case 6:
                printf("User Home? (1=Yes,0=No): ");
                scanf("%d", &isUserHome);

                printf("Night? (1=Yes,0=No): ");
                scanf("%d", &isNight);

                printf("Current Temp: ");
                scanf("%d", &currentTemp);

                runSmartSystem(root);
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}