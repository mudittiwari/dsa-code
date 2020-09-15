/*this is the program of queue implementation using static array*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct queuearr
{
    int capacity;
    int top;
    int rear;
    int *arr;
};

queuearr * createqueue(int);
bool checkempty(queuearr *);
bool checkfull(queuearr *);
void insertion(int,queuearr *);
int deletion(queuearr *);
/*int checksize(queuearr *);*/


queuearr * createqueue(int value)
{
    queuearr *temp;
    temp=new queuearr;
    temp->capacity=value;
    temp->rear=temp->top=-1;
    temp->arr=new int[temp->capacity];
    return temp;
}



bool checkempty(queuearr * temp)
{
    if(temp->top==-1)
        return true;
    else
        return false;
}

bool checkfull(queuearr *temp)
{
    if(temp->rear==temp->capacity-1 && temp->top==0)
        return true;
    else if(temp->top==temp->rear+1)
        return true;
    else
        return false;
}


void insertion(int value,queuearr *temp)
{
    if(checkempty(temp))
    {
        temp->top=temp->rear=0;
        temp->arr[temp->rear]=value;
        return ;
    }
    else if(checkfull(temp))
    {
        cout<<"the queue is full nothing can be inserted"<<endl;
        return ;
    }
    else
    {
        if(temp->rear==temp->capacity-1)
        {
            temp->rear=0;
            temp->arr[temp->rear]=value;
            return;
        }
        else
        {
            temp->rear++;
            temp->arr[temp->rear]=value;
            return ;
        }
    }
}

int deletion(queuearr *temp)
{
    if(temp->top==-1)
    {
        return -1;
    }
    else if(temp->top==temp->rear)
    {
        int value=temp->arr[temp->top];
        temp->top=temp->rear=-1;
        return value;
    }
    else
    {
        if(temp->top==temp->capacity-1)
        {
            int value=temp->arr[temp->top];
            temp->top=0;
            return value;
        }
        else
        {
            int value=temp->arr[temp->top];
            temp->top++;
            return value;
        }
    }
}

int main()
{
    int value;
    queuearr *temp;
    int capacity;
    int choice;
    cout<<"type the capacity of the queue"<<endl;
    cin>>capacity;
    temp=createqueue(capacity);
    while(1)
    {
        cout<<"1. insertion in the queue"<<endl;
        cout<<"2. deletion from the queue"<<endl;
        cout<<"3. exit"<<endl;
        cout<<"type the choice"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Type the value you want to insert"<<endl;
            cin>>value;
            insertion(value,temp);
            break;
        case 2:
            value=deletion(temp);
            if(value==-1)
                cout<<"the queue is empty nothing can be deleted"<<endl;
            else
                cout<<"The deleted value is"<<value<<endl;
            break;
        case 3:
            exit(0);
        default:
            cout<<"type the right choice"<<endl;
        }
    }
    return 0;
}
