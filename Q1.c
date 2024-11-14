#include <stdio.h>
#include <string.h>
int max_task, max_task_length;
void add_task(char tasks[max_task][max_task_length], int *task_count)
{
    if (*task_count >= max_task)
    {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }
    printf("Enter the task description: ");
    fgets(tasks[*task_count], max_task_length, stdin);
    tasks[*task_count][strcspn(tasks[*task_count], "\n")] = '\0';
    (*task_count)++;
    printf("Task added successfully.\n");
}
void view_task(char tasks[max_task][max_task_length], int *task_count)
{
    if (*task_count <= 0)
    {
        printf("No task to view");
        return;
    }
    printf("\nList of Tasks:\n");
    for (int i = 0; i < *task_count; i++)
    {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}
void mark_as_complete(char tasks[max_task][max_task_length], int *task_count)
{
    int task_num;
    if (*task_count == 0)
    {
        printf("\nNo tasks available to mark as complete.\n");
        return;
    }
    printf("\nEnter the task number to complete :");
    scanf("%d", &task_num);

    if (task_num < 1 || task_num > *task_count)
    {
        printf("Invalid task number! Please try again.\n");
        return;
    }
    for (int i = task_num - 1; i < *task_count - 1; i++)
    {
        strcpy(tasks[i], tasks[i + 1]);
    }
    (*task_count)--;
    printf("\nTask number %d is mark as complete successfully", task_num);
}
void task_track(char task[max_task][max_task_length], int max_task, int max_task_length)
{
    int task_count = 0;

    while (1)
    {
        int ch;
        printf("\nTo-Do List Menu:\n");
        printf("1. Add a new task\n");
        printf("2. View all tasks\n");
        printf("3. Mark a task as complete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();
        switch (ch)
        {
        case 1:
            add_task(task, &task_count);
            break;
        case 2:
            view_task(task, &task_count);
            break;
        case 3:
            mark_as_complete(task, &task_count);
            break;
        case 4:
            printf("Exiting the program.\n");
            return;
            break;

        default:
            break;
        }
    }
}
int main()
{
    printf("Enter the max number of task and max length of each task :");
    scanf("%d%d", &max_task, &max_task_length);
    char tasks[max_task][max_task_length];
    task_track(tasks, max_task, max_task_length);
    return 0;
}