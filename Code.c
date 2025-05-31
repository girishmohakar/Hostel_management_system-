#include <stdio.h>
#include <string.h>

struct User {
    char name[50];
    char phone[15];
};

struct Menu {
    char breakfast[100];
    char lunch[100];
    char dinner[100];
};

struct Feedback {
    int day;
    int breakfastRating;
    int lunchRating;
    int dinnerRating;
    char suggestion[200];
};

struct User owners[] = {
    {"Owner1", "9999999999"},
    {"Owner2", "8888888888"}
};

struct User students[] = {
    {"Student1", "7777777777"},
    {"Student2", "6666666666"}
};

struct Menu weeklyMenu[7];
struct Feedback feedbackList[100];
int feedbackCount = 0;

int isOwner(char phone[]);
int isStudent(char phone[]);
void ownerMenu();
void studentMenu();
void updateMenu();
void viewMenu();
void submitFeedback();
void generateReport();

int isOwner(char phone[]) {
    for (int i = 0; i < 2; i++) {
        if (strcmp(phone, owners[i].phone) == 0)
            return 1;
    }
    return 0;
}

int isStudent(char phone[]) {
    for (int i = 0; i < 2; i++) {
        if (strcmp(phone, students[i].phone) == 0)
            return 1;
    }
    return 0;
}

void updateMenu() {
    int day;
    printf("\nEnter day number to update menu (1 for Monday to 7 for Sunday): ");
    scanf("%d", &day);
    if (day < 1 || day > 7) {
        printf("Invalid day.\n");
        return;
    }
    day--;

    printf("Enter Breakfast for Day %d: ", day + 1);
    scanf(" %[^\n]", weeklyMenu[day].breakfast);
    printf("Enter Lunch for Day %d: ", day + 1);
    scanf(" %[^\n]", weeklyMenu[day].lunch);
    printf("Enter Dinner for Day %d: ", day + 1);
    scanf(" %[^\n]", weeklyMenu[day].dinner);

    printf("Menu updated for Day %d!\n", day + 1);
}

void viewMenu() {
    int day;
    printf("\nEnter day number to view menu (1 for Monday to 7 for Sunday): ");
    scanf("%d", &day);
    if (day < 1 || day > 7) {
        printf("Invalid day.\n");
        return;
    }
    day--;

    printf("\n--- Menu for Day %d ---\n", day + 1);
    printf("Breakfast: %s\n", weeklyMenu[day].breakfast);
    printf("Lunch    : %s\n", weeklyMenu[day].lunch);
    printf("Dinner   : %s\n", weeklyMenu[day].dinner);
}

void submitFeedback() {
    if (feedbackCount >= 100) {
        printf("Feedback storage full.\n");
        return;
    }

    int day;
    printf("Enter day number (1-7): ");
    scanf("%d", &day);
    if (day < 1 || day > 7) {
        printf("Invalid day.\n");
        return;
    }

    struct Feedback fb;
    fb.day = day;

    printf("Rate Breakfast (1-5): ");
    scanf("%d", &fb.breakfastRating);
    printf("Rate Lunch (1-5): ");
    scanf("%d", &fb.lunchRating);
    printf("Rate Dinner (1-5): ");
    scanf("%d", &fb.dinnerRating);
    printf("Any suggestions or complaints? ");
    scanf(" %[^\n]", fb.suggestion);
    
feedbackList[feedbackCount] = fb;
feedbackCount++;

    printf("Thank you for your feedback!\n");
}

void generateReport() {
    if (feedbackCount == 0) {
        printf("No feedbacks available.\n");
        return;
    }

    float totalBreakfast = 0, totalLunch = 0, totalDinner = 0;

    for (int i = 0; i < feedbackCount; i++) {
        totalBreakfast += feedbackList[i].breakfastRating;
        totalLunch += feedbackList[i].lunchRating;
        totalDinner += feedbackList[i].dinnerRating;
    }

    float avgBreakfast = totalBreakfast / feedbackCount;
    float avgLunch = totalLunch / feedbackCount;
    float avgDinner = totalDinner / feedbackCount;

    printf("\n--- Weekly Food Report ---\n");
    printf("Average Breakfast Rating: %.2f\n", avgBreakfast);
    printf("Average Lunch Rating    : %.2f\n", avgLunch);
    printf("Average Dinner Rating   : %.2f\n", avgDinner);

    printf("\n--- Student Suggestions ---\n");
    for (int i = 0; i < feedbackCount; i++) {
        printf("Day %d: %s\n", feedbackList[i].day, feedbackList[i].suggestion);
    }
}

void ownerMenu() {
    int choice;
    do {
        printf("\n--- Owner Menu ---\n");
        printf("1. Update Menu\n");
        printf("2. View Menu\n");
        printf("3. View Weekly Report\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: updateMenu(); break;
            case 2: viewMenu(); break;
            case 3: generateReport(); break;
            case 4: printf("Exiting Owner Menu.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

void studentMenu() {
    int choice;
    do {
        printf("\n--- Student Menu ---\n");
        printf("1. View Menu\n");
        printf("2. Submit Feedback\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewMenu(); break;
            case 2: submitFeedback(); break;
            case 3: printf("Exiting Student Menu.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);
}

int main() {
    char phone[15];

    printf("Welcome to Hostel Mess Management System\n");
    printf("Enter your registered phone number: ");
    scanf("%s", phone);

    if (isOwner(phone)) {
        printf("Owner login successful!\n");
        ownerMenu();
    } else if (isStudent(phone)) {
        printf("Student login successful!\n");
        studentMenu();
    } else {
        printf("Phone number not registered.\n");
    }

    return 0;
}
