
//Write a menu driven program to Process a sorted Array. Your program should have the following menu: Insert, Delete, Search, Display and Exit.


#include<bits/stdc++.h>
using namespace std;


int Array[10000],N;

void sarting_arrangement(void);
void sorting(void);
void Search(void);
int Insert(void);
void Delete(void);
void display(void);
int menu(void);

int menu(void)
{
    int choice;

    do
    {
        cout<<endl<<"1-Insert"<<endl<<"2-Delete"<<endl<<"3-Search"<<endl<<"4-Display"<<endl<<"0-Exit"<<endl;
        cout<<"Enter your choice by pressing the following digit : ";
        cin>>choice;

        if(choice<0 || choice>4)
        {
            cout<<endl<<"Wrong...!!!!"<<endl<<" Choice again..."<<endl;
        }

    }
    while(choice<0||choice>4);

    return (choice);
}



void sarting_arrangement(void)
{

    cout<<"Enter the Number= ";
    cin>>N;

    srand((unsigned) time(0));

    for(int i=0; i<N; i++)
    {
        Array[i]= ((rand()%100)+1);
    }

    cout<<"Before sorting, the array is = ";

    for(int i=0; i<N; i++)
    {
        cout<<Array[i]<<' ';
    }
    cout<<endl;

}


void sorting(void)
{

    int temp=0,i,j;

    for( i=1; i<N; i++)
    {

        for( j=0; j<(N-i); j++)
        {

            if(Array[j]>Array[j+1])
            {
                temp=Array[j];
                Array[j]=Array[j+1];
                Array[j+1]=temp;
            }

        }

    }

}


void Search(void)
{

    int i,element,loc=-1;

    cout<<"Enter the element = ";
    cin>>element;

    loc=-1;

    for(i=0; i<N; i++)
    {
        if(Array[i]==element)
        {
            loc=i;
            break;
        }

    }

    if(loc==-1)
    {
        cout<<"Element is not in the array "<<endl;
    }
    else
    {
        cout<<loc+1<<" is the location of element"<<endl;
    }


}

int Insert(void)
{
    int element,i,s=N-1;

    cout<<"Enter the element = ";
    cin>>element;

    s=N-1;

    if(element>Array[N-1])
    {
        Array[N]=element;
    }

    else
    {
        for(i=N-1; element<Array[i] && i>=0 ; i--)
        {
            Array[i+1]=Array[i];
            s--;
        }

        Array[s+1]=element;

    }
    N=N+1;



}

void Delete(void)
{
    int element,i,pos=-1,mid=0,end,beg=0;

    cout<<"Enter the element = ";
    cin>>element;

    beg=0;
    end=N;
    mid= int((beg+end)/2);
    pos=-1;

    for(i=beg;  i<=end && Array[mid]!=element;  i++)
    {
        if(Array[mid]>element)
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }

        mid=((beg+end)/2);
    }

    if(Array[mid]==element)
    {
        pos=mid;

        for(i=pos; i<N-1; i++)
        {
            Array[i]=Array[i+1];
        }

        N=N-1;
    }
    else if(N==0)
    {
        cout<<"Array is empty . Insert please....."<<endl;
    }
    else
    {
        cout<<"Element is not in the array "<<endl;
    }

}


void display(void)
{
    int i;

    for(i=0; i<N; i++)
    {
        cout<<Array[i]<<' ';
    }
    cout<<endl;

}

int main()
{
    int choice;

    sarting_arrangement();
    sorting();

    cout<<"After sorting, the array is = ";
    display();


    do
    {
        choice=menu();
        switch(choice)
        {
        case 1:
            Insert();
            display();
            break;
        case 2:
            Delete();
            display();
            break;
        case 3:
            Search();
            display();
            break;
        case 4:
            cout<<"Displaying the elements of array = ";
            display();
            break;
        case 0:
            cout<<"End of operation"<<endl;
            break;
        }
    }
    while(choice!=0);
    return 0;
}



