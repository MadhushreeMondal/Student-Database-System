
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

struct Student
{
    int roll;
    char name[50];
    int age;
    char dept[30];
    float marks;
};

struct Student s[MAX];
int count=0;

// Load from file
void loadFile()
{
    FILE *fp;

    fp=fopen("students.txt","r");

    if(fp==NULL)
        return;

    while(fscanf(fp,"%d %s %d %s %f",
          &s[count].roll,
          s[count].name,
          &s[count].age,
          s[count].dept,
          &s[count].marks)!=EOF)
    {
        count++;
    }

    fclose(fp);
}

// Save to file
void saveFile()
{
    FILE *fp;
    int i;

    fp=fopen("students.txt","w");

    for(i=0;i<count;i++)
    {
        fprintf(fp,"%d %s %d %s %.2f\n",
        s[i].roll,
        s[i].name,
        s[i].age,
        s[i].dept,
        s[i].marks);
    }

    fclose(fp);
}

// Add student
void addStudent()
{
    printf("Enter Roll: ");
    scanf("%d",&s[count].roll);

    printf("Enter Name: ");
    scanf("%s",s[count].name);

    printf("Enter Age: ");
    scanf("%d",&s[count].age);

    printf("Enter Department: ");
    scanf("%s",s[count].dept);

    printf("Enter Marks: ");
    scanf("%f",&s[count].marks);

    count++;

    saveFile();

    printf("Student Added Successfully\n");
}

// Display all
void displayStudents()
{
    int i;

    if(count==0)
    {
        printf("No Records Found\n");
        return;
    }

    printf("\nRoll\tName\tAge\tDept\tMarks\n");

    for(i=0;i<count;i++)
    {
        printf("%d\t%s\t%d\t%s\t%.2f\n",
        s[i].roll,
        s[i].name,
        s[i].age,
        s[i].dept,
        s[i].marks);
    }
}

// Search
void searchStudent()
{
    int roll,i;

    printf("Enter Roll Number: ");
    scanf("%d",&roll);

    for(i=0;i<count;i++)
    {
        if(s[i].roll==roll)
        {
            printf("Record Found\n");
            printf("Roll: %d\n",s[i].roll);
            printf("Name: %s\n",s[i].name);
            printf("Age: %d\n",s[i].age);
            printf("Department: %s\n",s[i].dept);
            printf("Marks: %.2f\n",s[i].marks);
            return;
        }
    }

    printf("Record Not Found\n");
}

// Update
void updateStudent()
{
    int roll,i;

    printf("Enter Roll To Update: ");
    scanf("%d",&roll);

    for(i=0;i<count;i++)
    {
        if(s[i].roll==roll)
        {
            printf("Enter New Name: ");
            scanf("%s",s[i].name);

            printf("Enter New Age: ");
            scanf("%d",&s[i].age);

            printf("Enter New Department: ");
            scanf("%s",s[i].dept);

            printf("Enter New Marks: ");
            scanf("%f",&s[i].marks);

            saveFile();

            printf("Record Updated\n");
            return;
        }
    }

    printf("Record Not Found\n");
}

// Delete
void deleteStudent()
{
    int roll,i,j;

    printf("Enter Roll To Delete: ");
    scanf("%d",&roll);

    for(i=0;i<count;i++)
    {
        if(s[i].roll==roll)
        {
            for(j=i;j<count-1;j++)
            {
                s[j]=s[j+1];
            }

            count--;
            saveFile();

            printf("Record Deleted\n");
            return;
        }
    }

    printf("Record Not Found\n");
}

// Sort by marks
void sortByMarks()
{
    int i,j;
    struct Student temp;

    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(s[j].marks > s[j+1].marks)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }

    printf("Records Sorted By Marks\n");

    displayStudents();
}

int main()
{
    int choice;

    loadFile();

    while(1)
    {
        printf("\n--- STUDENT DATABASE SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort by Marks\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                sortByMarks();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
}

