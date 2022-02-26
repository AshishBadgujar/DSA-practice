/* LAB ASSIGNMENT 1. Searching and Sorting
 Consider a student database of SEIT class (at least 15 records).
 Database contains different fields of every student like Roll No, Name and SGPA.(a
 a) Design a roll call list, arrange list of students according to roll numbers in
 b) Arrange list of students alphabetically. (Use Insertion sort)
 c) Arrange list of students to find out first ten toppers from a class. (Use Quick
 d) Search students according to SGPA. If more than one student having same SGPA, t
 e) Search a particular student according to name using binary search without recur
 (all the student records having the presence of search key should be displayed)

 NAME:Ashish badgujar
 DIV :1 (SE IT)
 ROLL NO:S20112 */

using namespace std;
#include <iostream>
#include <string.h>
int const size = 5;

struct student
{
    int rno;
    char name[20];
    float SGPA;
};

void accept(struct student list[size]);
void display(struct student list[80]);
void bubbleSort(struct student list[size]);
void insertSort(struct student list[size]);
void search(struct student list[size]);
void binarysearch(struct student list[size]);

int main()
{
    int ch, i;
    struct student data[20];
    accept(data);

    cout << "\n 1: Bubble Sort";
    cout << "\n 2: Insertion Sort";
    cout << "\n 3: Search";
    cout << "\n 4: Binary Search";
    cout << "\n Select your choice:";
    cin >> ch;

    switch (ch)
    {
    case 1:
        bubbleSort(data);
        display(data);
        break;

    case 2:
        insertSort(data);
        display(data);
        break;

    case 3:
        search(data);
        break;

    case 4:
        binarysearch(data);
        break;

    default:
        cout << " Invalid choice ...";
    }
    return 0;
}

void accept(struct student list[size])
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << " Enter rollno, name and SGPA:";
        cin >> list[i].rno >> list[i].name >> list[i].SGPA;
    }
}

void display(struct student list[80])
{
    int i;
    cout << "\nRollno \t Name \t SGPA \n";
    for (i = 0; i < size; i++)
    {
        cout << "\n"
             << list[1].rno << "\t" << list[i].name << "\t" << list[i].SGPA;
    }
}

void bubbleSort(struct student list[size])
{
    int i, j;
    struct student temp;
    cout << "List Of Students According To Roll Numbers In Ascending Order";
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < (size - 1 - i); j++)
        {
            if (list[j].rno > list[j + 1].rno)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void insertSort(struct student list[size])
{
    int k, j;
    struct student temp;
    cout << "List Of Students Alphabetically";
    for (k = 1; k < size; k++)
    {
        temp = list[k];
        j - k - 1;

        while (strcmp(list[j].name, temp.name) > 0 && j >= 0)
        {
            list[j + 1] = list[j];
            --j;
        }
        list[j + 1] = temp;
    }
}

void search(struct student list[size])
{
    float SGPA;
    int i;
    cout << "Search students according to SGPA";
    cout << "\n Enter SGPA:";
    cin >> SGPA;

    cout << "\n Rollno\t Name\t SGPA\n";
    for (i = 0; i < size; i++)
    {
        if (SGPA == list[i].SGPA)
            cout << "\n"
                 << list[i].rno << "\t" << list[i].name << "\t" << list[i].SGPA;
    }
}

void binarysearch(struct student list[size])
{
    int k, lower, upper, mid;
    char search[80];
    cout << "Search a particular student according to Name";
    cout << "\n Enter name of student you want to search";
    cin >> search;

    lower = 0;
    upper = size - 1;
    mid = (lower + upper) / 2;

    while (lower <= upper)
    {
        if (strcmp(list[mid].name, search) < 0)
            lower = mid + 1;

        else if (strcmp(list[mid].name, search) == 0)
        {
            cout << "\n"
                 << list[mid].rno << "\t" << list[mid].name << "\t" << list[mid].SGPA;
            break;
        }
        else
            upper = mid - 1;
        mid = (lower + upper) / 2;
    }
    if (lower > upper)
        cout << search << "Not found in the list";
}