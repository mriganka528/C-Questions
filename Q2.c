#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[50];
    int roll_no;
    float marks;
} Student;

void input_student_details(Student *students, int count);
void display_students(Student *students, int count);

int main()
{
    int total_student;

    printf("Enter the number of students: ");
    scanf("%d", &total_student);
    getchar();

    // Dynamically allocate memory for an array of students
    Student *students = (Student *)malloc(total_student * sizeof(Student));
    if (students == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input student details
    input_student_details(students, total_student);

    // Display students based on their marks
    display_students(students, total_student);

    // Free dynamically allocated memory
    free(students);

    return 0;
}

void input_student_details(Student *students, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Roll Number: ");
        scanf("%d", &students[i].roll_no);

        printf("Marks: ");
        scanf("%f", &students[i].marks);

        getchar();
    }
}

void display_students(Student *students, int count)
{
    printf("\nStudents with marks above 60%%:\n");
    int found_above_60 = 0;
    for (int i = 0; i < count; i++)
    {
        if (students[i].marks > 60.0)
        {
            printf("\nName: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
            found_above_60 = 1;
        }
    }
    if (!found_above_60)
    {
        printf("No students with marks above 60%%.\n");
    }

    printf("\nStudents with marks between 45%% and 59%%:\n");
    int found_between_45_59 = 0;
    for (int i = 0; i < count; i++)
    {
        if (students[i].marks >= 45.0 && students[i].marks <= 59.0)
        {
            printf("\nName: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
            found_between_45_59 = 1;
        }
    }
    if (!found_between_45_59)
    {
        printf("No students with marks between 45%% and 59%%.\n");
    }
}
