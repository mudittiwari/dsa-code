#include<iostream>
#include<cstdlib>
using namespace std;

struct queuearr
{
    int capacity;
    int top;
    int rear;
    int *arr;
};

queuearr * createqueue();
bool checkempty(queuearr *);
bool checkfull(queuearr *);
void doublequeue(queuearr *);
void insertion(int, queuearr *);
int deletion(queuearr *);
int checksize(queuearr *);
void shrinkqueue(queuearr *);
void printqueue(queuearr *);


queuearr * createqueue()
{
    queuearr *temp;
    temp=new queuearr;
    temp->capacity=1;
    temp->top=temp->rear=-1;
    temp->arr=new int[temp->capacity];
    return temp;
}

bool checkempty(queuearr *temp)
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
    else if(temp->rear==temp->top+1)
        return true;
    else
        return false;
}

void doublequeue(queuearr *temp)
{
    int *temp2;
    temp2=new int[temp->capacity*2];
    for(int i=temp->top,j=0; j<temp->capacity; j++)
    {
        temp2[j]=temp->arr[i];
        if(i==temp->capacity-1)
            i=0;
        else
            i++;
    }
    delete(temp->arr);
    temp->arr=temp2;
    temp->rear=temp->capacity-1;
    temp->capacity=temp->capacity*2;
    temp->top=0;
}


void insertion(int value,queuearr *temp)
{
    if(checkfull(temp))
    {
        doublequeue(temp);
        /*        cout<<temp->capacity;*/
        temp->rear++;
        temp->arr[temp->rear]=value;
        return;
    }
    if(checkempty(temp))
    {
        temp->rear=temp->top=0;
        temp->arr[temp->rear]=value;
        return ;
    }
    else if(temp->rear==temp->capacity-1)
    {
        temp->rear=0;
        temp->arr[temp->rear]=value;
        return;
    }
    else
    {
        temp->rear++;
        temp->arr[temp->rear]=value;
        return;
    }
}

void shrinkqueue(queuearr *temp)
{
    int *arr;
    arr=new int[temp->capacity/2];
    for(int i=temp->top,j=0; j<temp->capacity/2; j++)
    {
        arr[j]=temp->arr[i];
        if(i==temp->capacity-1)
            i=0;
        else
            i++;
    }
    temp->capacity=temp->capacity/2;
    delete(temp->arr);
    temp->arr=arr;
    temp->top=0;
    temp->rear=temp->capacity-1;
}

int checksize(queuearr *temp)
{
    if(checkempty(temp))
        return 0;
    else
    {
        int s=0;
        for(int i=temp->top; i!=temp->rear; s++)
        {
            if(i==temp->capacity-1)
                i=0;
            else
                i++;
        }
        s++;
        return s;
    }
}


void printqueue(queuearr *temp)
{
    int i;
    if(checkempty(temp))
        cout<<"The queue is empty"<<endl;
    else
    {
        for(i=temp->top; i!=temp->rear; )
        {
            cout<<temp->arr[i]<<"\t";
            if(i==temp->capacity-1)
                i=0;
            else
                i++;
        }
        cout<<temp->arr[i];
        cout<<endl;
    }
}


int deletion(queuearr *temp)
{
    if(temp->top==-1)
        return -1;
    else if(temp->top==temp->rear)
    {
        int value;
        value=temp->arr[temp->top];
        temp->rear=temp->top=-1;
        return value;
    }
    else
    {
        int value;
        value=temp->arr[temp->top];
        if(temp->top==temp->capacity-1)
            temp->top=0;
        else
            temp->top++;
        int size_=checksize(temp);
        cout<<size_;
        if(size_==temp->capacity/2)
        {
            shrinkqueue(temp);
        }
        return value;
    }
}

int main()
{
    queuearr *temp;
    temp=createqueue();
    int value;
    int choice;
    while(1)
    {
        cout<<"1. insertion "<<endl;
        cout<<"2. Deletion "<<endl;
        cout<<"3. check capacity"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"5. print queue"<<endl;
        cout<<"6. size of the queue"<<endl;
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
                cout<<"the value deleted is "<<value<<endl;
            break;
        case 3:
            cout<<"the capacity is "<<temp->capacity<<endl;
            break;
        case 4:
            exit(0);
            break;
        case 5:
            printqueue(temp);
            break;
        case 6:
            value=checksize(temp);
            cout<<"the size of the queue is "<<value<<endl;
            break;
        default:
            cout<<"type the correct choice"<<endl;
            break;
        }
    }
    return 0;
}
