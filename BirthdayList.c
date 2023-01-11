#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct birdth_day_form
{
    int day;
    int month;
    int year;
    char *name;
} birth[100];

int info_index = 0;
char find_name[32];

void add_name()
{
    birth[info_index].name = (char *)malloc(32 * sizeof(char));
    printf("Enter the name of your friend\n");
    scanf(" %[^\n]s", birth[info_index].name);
    printf("Enter the birth day of your friend\n");
    scanf("%d", &birth[info_index].day);
    printf("Enter the month of your friend\n");
    scanf("%d", &birth[info_index].month);
    printf("Enter the year of your friend\n");
    scanf("%d", &birth[info_index].year);
    // store name, day, month and year in same array index
    info_index++;
}

void search_name()
{
    printf("Enter the name of your friend\n");
    scanf(" %[^\n]s", find_name);
    for (int i = 0; i < info_index; i++)
    {
        if (strcmp(birth[i].name, find_name) == 0)
        {
            printf("%s %d.%d.%d", birth[i].name, birth[i].day, birth[i].month, birth[i].year);
            return;
        }
    }
    printf("Name not Found\n");
}

void edit_name()
{
    printf("Enter the name of your friend\n");
    scanf(" %[^\n]s", find_name);
    for (int i = 0; i < info_index; i++)
    {
        if (strcmp(birth[i].name, find_name) == 0)
        {
            printf("Enter the New name of your friend\n");
            scanf(" %[^\n]s", birth[i].name);
            printf("Enter the New birth day of your friend\n");
            scanf("%d", &birth[i].day);
            printf("Enter the New month of your friend\n");
            scanf("%d", &birth[i].month);
            printf("Enter the New year of your friend\n");
            scanf("%d", &birth[i].year);
            return;
        }
    }
    printf("Name not Found\n");
}

void display()
{
    for (int i = 0; i < info_index; i++)
    {
        printf("%s %d.%d.%d\n", birth[i].name, birth[i].day, birth[i].month, birth[i].year);
    }
}

void display_recent_birthday()
{
    int month;
    printf("Enter the number of month\n");
    scanf("%d", &month);
    for (int i = 0; i < info_index; i++)
    {
        if ((birth[i].month - month) == 0)
        {
            printf("%s %d.%d.%d\n", birth[i].name, birth[i].day, birth[i].month, birth[i].year);
            return;
        }
    }
    printf("No birhtday in this month\n");
}

int main()
{
    //Taking user input
    int choice;
    while (choice != 0)
    {
        printf("1. Add Name of your Friend\n");
        printf("2. Edit Name of your Friend\n");
        printf("3. Search Name of your Friend\n");
        printf("4. Display the birthday List\n");
        printf("5. Find brthday of your Friend in this month\n");
        printf("Enter 0 to exit\n");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            add_name();
            break;
        case 2:
            edit_name();
            break;
        case 3:
            search_name();
            break;
        case 4:
            display();
            break;
        case 5:
            display_recent_birthday();
            break;
        default:
            printf("Bye :(");
            break;
        }
    }
    return 0;
}