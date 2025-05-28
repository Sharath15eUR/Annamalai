#include <stdio.h>
#include <string.h>

#define MAX_TASKS 3
#define MAX_DAYS 7
#define MAX_LEN 100

// Structure to store day and tasks
struct Day {
    char dayName[10];
    char tasks[MAX_TASKS][MAX_LEN];
};

int main() {
    struct Day week[MAX_DAYS] = {
        {"Monday", {"", "", ""}},
        {"Tuesday", {"", "", ""}},
        {"Wednesday", {"", "", ""}},
        {"Thursday", {"", "", ""}},
        {"Friday", {"", "", ""}},
        {"Saturday", {"", "", ""}},
        {"Sunday", {"", "", ""}}
    };

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add tasks to a day\n");
        printf("2. Display all tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character

        if (choice == 1) {
            int dayIndex;
            printf("Select a day (0=Monday, 1=Tuesday, ..., 6=Sunday): ");
            scanf("%d", &dayIndex);
            getchar();  // clear newline

            if (dayIndex >= 0 && dayIndex < MAX_DAYS) {
                for (int i = 0; i < MAX_TASKS; i++) {
                    printf("Enter task %d for %s: ", i + 1, week[dayIndex].dayName);
                    fgets(week[dayIndex].tasks[i], MAX_LEN, stdin);
                    // Remove newline character
                    week[dayIndex].tasks[i][strcspn(week[dayIndex].tasks[i], "\n")] = 0;
                }
            } else {
                printf("Invalid day index!\n");
            }
        } else if (choice == 2) {
            printf("\nWeekly Task List:\n");
            for (int i = 0; i < MAX_DAYS; i++) {
                printf("\n%s:\n", week[i].dayName);
                for (int j = 0; j < MAX_TASKS; j++) {
                    if (strlen(week[i].tasks[j]) > 0)
                        printf("  Task %d: %s\n", j + 1, week[i].tasks[j]);
                }
            }
        }

    } while (choice != 3);

    return 0;
}
