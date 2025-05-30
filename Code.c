 #include <stdio.h>
#include <string.h>

struct User {
    char name[50];
    char phone[15]; 
};

struct User owners[] = {
    {"Owner1", "9999999999"},
    {"Owner2", "8888888888"}
};

struct User students[] = {
    {"Student1", "7777777777"},
    {"Student2", "6666666666"}
};


struct Menu {
    char breakfast[100];
    char lunch[100];
    char dinner[100];
};
struct Menu weeklyMenu[7]; 


struct Feedback {
    int day;
    int breakfastRating;
    int lunchRating;
    int dinnerRating;
    char suggestion[200];
};

struct Feedback feedbackList[100]; 
int feedbackCount = 0; 


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

    printf("Menu updated successfully for Day %d!\n", day + 1);
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

    feedbackList[feedbackCount++] = fb;

    printf("Thank you for your feedback!\n");
}


void generateReport() {
    if (feedbackCount == 0) {
        printf("No feedbacks available.\n");
        return;
    }
    struct {
        char name[100];
        int totalRating;
        int count;
    } foodRatings[100];
    int ratingIndex = 0;

    for (int i = 0; i < feedbackCount; i++) {
        int d = feedbackList[i].day - 1;

        
        int found = 0;
        for (int j = 0; j < ratingIndex; j++) {
            if (strcmp(foodRatings[j].name, weeklyMenu[d].breakfast) == 0) {
                foodRatings[j].totalRating += feedbackList[i].breakfastRating;
                foodRatings[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(foodRatings[ratingIndex].name, weeklyMenu[d].breakfast);
            foodRatings[ratingIndex].totalRating = feedbackList[i].breakfastRating;
            foodRatings[ratingIndex].count = 1;
            ratingIndex++;
        }

        found = 0;
        for (int j = 0; j < ratingIndex; j++) {
            if (strcmp(foodRatings[j].name, weeklyMenu[d].lunch) == 0) {
                foodRatings[j].totalRating += feedbackList[i].lunchRating;
                foodRatings[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(foodRatings[ratingIndex].name, weeklyMenu[d].lunch);
            foodRatings[ratingIndex].totalRating = feedbackList[i].lunchRating;
            foodRatings[ratingIndex].count = 1;
            ratingIndex++;
        }

        found = 0;
        for (int j = 0; j < ratingIndex; j++) {
            if (strcmp(foodRatings[j].name, weeklyMenu[d].dinner) == 0) {
                foodRatings[j].totalRating += feedbackList[i].dinnerRating;
                foodRatings[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(foodRatings[ratingIndex].name, weeklyMenu[d].dinner);
            foodRatings[ratingIndex].totalRating = feedbackList[i].dinnerRating;
            foodRatings[ratingIndex].count = 1;
            ratingIndex++;
        }
    }
    float bestAvg = 0, worstAvg = 6;
    char bestFood[100], worstFood[100];

    for (int i = 0; i < ratingIndex; i++) {
        float avg = (float)foodRatings[i].totalRating / foodRatings[i].count;
        if (avg > bestAvg) {
            bestAvg = avg;
            strcpy(bestFood, foodRatings[i].name);
        }
        if (avg < worstAvg) {
            worstAvg = avg;
            strcpy(worstFood, foodRatings[i].name);
        }
    }

    printf("\n--- Weekly Food Report ---\n");
    printf("Most liked item : %s (%.2f stars)\n", bestFood, bestAvg);
    printf("Least liked item: %s (%.2f stars)\n", worstFood, worstAvg);

    printf("\n--- Student Suggestions ---\n");
    for (int i = 0; i < feedbackCount; i++) {
        printf("Day %d: %s\n", feedbackList[i].day, feedbackList[i].suggestion);
    }
}

void ownerMenu() {
    int choice;
    do {
        printf("\n--- Owner Menu ---\n");
        printf("1. Update Food Menu\n");
        printf("2. View Menu\n");
        printf("3. Collect Mess Rent (Coming Soon)\n");
        printf("4. View Student Logs / Weekly Report\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: updateMenu(); break;
            case 2: viewMenu(); break;
            case 4: generateReport(); break;
            case 5: printf("Exiting Owner Menu.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

void studentMenu() {
    int choice;
    do {
        printf("\n--- Student Menu ---\n");
        printf("1. View Food Menu\n");
        printf("2. Submit Feedback / Complaint\n");
        printf("3. Pay Mess Rent (Coming Soon)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewMenu(); break;
            case 2: submitFeedback(); break;
            case 4: printf("Exiting Student Menu.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
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
