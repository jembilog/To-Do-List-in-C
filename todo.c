#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX_TASKS 100

//todo list
typedef struct 
{
    char title[100];
    int completed;
}Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

//functions
void addTask();
void viewTasks();
void completeTask();
void deleteTask();

//main func
int main(){
    int choice;
    do{ 
        printf("\n=== TO DO LIST MAIN MENU ===\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addTask();
                break;
            case 2: 
                viewTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4: 
                deleteTask();
                break;
            case 5: 
                printf("Bye");
                break;
            
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 5);
    return 0;
}

void addTask(){
    //we'll check first if taskCount in full or greater than Max Tasks
    if(taskCount >= MAX_TASKS){
        printf("Task list os full\n");
        return;
    }
    getchar();
    printf("Enter task: ");
    fgets(tasks[taskCount].title, sizeof(tasks[taskCount].title), stdin);
    tasks[taskCount].title[strcspn(tasks[taskCount].title, "\n")] = '\0';
    // if(tasks[taskCount].title[0] == '\0'){
    //     printf("Error: Task title cannot be empty");
    //     return;
    // }
    tasks[taskCount].completed = 0;
    taskCount++;
    printf("Task added successfully");
}
void viewTasks() {

    if(taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\n=== TO DO LIST ===\n");

    for(int i = 0; i < taskCount; i++) {

        printf("%d. [%c] %s\n",
               i + 1,
               tasks[i].completed ? 'X' : ' ',
               tasks[i].title);
    }
}
void completeTask(){
    int index;

    viewTasks();
    printf("Enter task number to complete: ");
    scanf("%d", &index);

    if(index < 1 || index > taskCount){
        printf("Invalid task number\n");
        return;
    }

    tasks[index - 1 ]. completed = 1;
    printf("Task completed\n");
}
void deleteTask(){
    int index;

    viewTasks();

    printf("Enter task number to delete: ");
    scanf("%d", &index);

    if(index < 1 || index > taskCount){
        printf("invalid task number\n");
        return;
    }

    for(int i = index - 1 ; i < taskCount - 1; i++){
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    printf("Task deleted\n");
}