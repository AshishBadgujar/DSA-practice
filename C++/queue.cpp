/* LAB ASSIGNMENT 3. Circular Queue
Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
 b) Deletion (Dequeue)
 c) Display

 NAME:Ashish badgujar
 DIV :1 (SE IT)
 ROLL NO:S20112

 */
#include <iostream>
using namespace std;

int cqueue[5];
int front = -1, rear = -1, n = 5;

void insertCQ(int val)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        cout << "Queue Overflow \n";
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == n - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue[rear] = val;
}
void deleteCQ()
{
    if (front == -1)
    {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Element deleted from queue is : " << cqueue[front] << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == n - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void display_forwardCQ()
{
    int f = front, r = rear;
    if (front == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements(forward) are :\n";
    if (f <= r)
    {
        while (f <= r)
        {
            cout << cqueue[f] << " ";
            f++;
        }
    }
    else
    {
        while (f <= n - 1)
        {
            cout << cqueue[f] << " ";
            f++;
        }
        f = 0;
        while (f <= r)
        {
            cout << cqueue[f] << " ";
            f++;
        }
    }
    cout << endl;
}
void display_reverseCQ()
{
    int f = front, r = rear;
    if (front == -1)
    {
        cout << "queue is empty" << endl;
        return;
    }
    cout << "Queue elements(reverse) are :\n";
    if (f <= r)
    {
        while (f <= r)
        {
            cout << cqueue[r] << " ";
            r--;
        }
    }
    else
    {
        while (r >= 0)
        {
            cout << cqueue[r] << " ";
            r--;
        }
        while (r >= f)
        {
            cout << cqueue[r] << " ";
        }
    }
    cout << endl;
}
int main()
{
    int ch, val;
    cout << "1)Insert\n";
    cout << "2)Delete\n";
    cout << "3)display_forwardCQ\n";
    cout << "4)display_reverseCQ\n";
    cout << "5)Exit\n";
    do
    {
        cout << "Enter choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Input for insertion: " << endl;
            cin >> val;
            insertCQ(val);
            break;

        case 2:
            deleteCQ();
            break;

        case 3:
            display_forwardCQ();
            break;

        case 4:
            display_reverseCQ();
            break;

        case 5:
            cout << "Exit\n";
            break;
        default:
            cout << "Incorrect!\n";
        }
    } while (ch != 4);
    return 0;
}
