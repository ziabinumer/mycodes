#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char id[4];
    char Class[20];
} node;

node student;

// functions declaration
void start(void);
void functions(int choice);
void addRecord(void);
void viewRecord(void);
void error(void);
void updateRecord(void);
void clear(void);
void removeRecord(void);


// main
int main()
{
    start();
}


// functions definition

void error()
{
    printf("\nAn Error encountered. Exiting...");
    return;
}

void start()
{
    system("cls");
    printf("\n\t----Student Management System----\n\n");
    printf("1. Add Record\n");
    printf("2. View Record\n");
    printf("3. Update Record\n");
    printf("4. Remove Record\n");
    printf("5. Clear Record\n");
    printf("6. Quit\n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%i", &choice);
    functions(choice);
}

void functions(int choice)
{
    switch(choice)
    {
        case 1:
            system("cls");
            addRecord();
            break;
        case 2:
            system("cls");
            viewRecord();
            break;
        case 3:
            system("cls");
            updateRecord();
            break;
        case 4:
            system("cls");
            removeRecord();
            break;
        case 5:
            system("cls");
            clear();
            break;
        case 6:
            return;
        default:
            printf("Invalid Choice\n");
    }

    printf("\nPress any key to continue...");
    getch();
    start();
}

void addRecord()
{
    FILE *file = fopen("student_record.bin", "ab");
    if (file == NULL)
    {
        error();
        return;
    }
    printf("\n\t----Add Record----\n\n");
    printf("Enter Name: ");
    scanf("%s", student.name);
    printf("Enter ID: ");
    scanf("%s", student.id);
    printf("Enter Class: ");
    scanf("%s", student.Class);
    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
}

void viewRecord()
{
    FILE *file = fopen("student_record.bin", "rb");
    if (file == NULL)
    {
        error();
        return;
    }
    int record = 0;
    printf("\n\t----View Record----\n\n");
    while (fread(&student, sizeof(student), 1, file))
    {
        printf("Name \t: %s\n", student.name);
        printf("ID \t: %s\n", student.id);
        printf("Class \t: %s\n", student.Class);
        printf("--------------------\n");
        record++;
    }
    if (record == 0) printf("Oops, no record found\n");
    else printf("Total Records Found: %i\n", record);
    fclose(file);
}

void updateRecord()
{
    FILE *file;
    file = fopen("Student_record.bin", "rb+");
    int found = 0;
    char id[4];
    if (file == NULL)
    {
        error();
        return;
    }
    printf("\n\t---Update Student Record---\n\n");
    printf("Enter Student ID  : ");
    scanf("%s", id);
    while (fread(&student, sizeof(student), 1, file) == 1)
    {
        if (strcmp(student.id, id) == 0)
        {
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\nSorry record not found :( ");
        return;
    }
    fseek(file, -(sizeof(student)), SEEK_CUR);

    printf("\n\tEnter new details\n\n");
    printf("Name    : ");
    scanf("%s", student.name);
    printf("Id      : ");
    scanf("%s", student.id);
    printf("Class  : ");
    scanf("%s", student.Class);
    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
    printf("\n  Student details updated successfully..\n");
}

void removeRecord()
{
    printf("\n\t----Remove Student Record----\n\n");
    char id[4];
    printf("Enter Student ID  : ");
    scanf("%s", id);

    FILE *file = fopen("student_record.bin", "rb");
    if (file == NULL)
    {
        error();
        return;
    }
    FILE *temp = fopen("temp.bin", "wb");
    if (temp == NULL)
    {
        fclose(file);
        error();
        return;
    }
    int found = 0;
    while(fread(&student, sizeof(student), 1, file))
    {
        if (strcmp(student.id, id) == 0)
        {
            found++;
        }
        else fwrite(&student, sizeof(student), 1, temp);
    }
    fclose(file);
    fclose(temp);
    if (found == 0)
    {
        printf("No Records Found\n");
        return;
    }
    fopen("student_record.bin", "wb");
    fopen("temp.bin", "rb");
    while (fread(&student, sizeof(student), 1, temp))
    {
        fwrite(&student, sizeof(student), 1, file);
    }
    fclose(file);
    fclose(temp);
    remove("temp.bin");
    printf("-------------");
    printf("\nTotal Records Removed  : %i\n", found);
}

void clear()
{
    printf("\t----Clear Record----\n\n");
    FILE *file = fopen("student_record.bin", "w");
    if (file == NULL) error();
    else printf("Records cleared\n");
}

