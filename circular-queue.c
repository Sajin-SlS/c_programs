#include<stdio.h>
#include<stdlib.h>
int a[20],front=-1,rear=-1,n,item,next;
int main()
{
int ch;
printf("Enter the size of your circular queue:");
scanf("%d",&n);
do
{
    printf("\n1.insert\n2.Deletion\n3.Dispaly\n4.Exit\n");
    printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert();
        break;
        case 2:del();
        break;
        case 3:dis();
        break;
        case 4:exit(0);
        break;
        default:printf("Invaid choice");
        break;
    }
}while(ch!=4);
}

void insert()
{
    next=(rear+1)%n;
    if((front==-1)&&(rear==-1))
    {
        front=0;
        rear=0;
        printf("Enter the item to be inserted :");
        scanf("%d",&item);
        a[rear]=item;
    }
    else
    {
        if(next!=front)
        {
            rear=next;
            printf("Enter the item to inserted :");
            scanf("%d",&item);
            a[rear]=item;
        }
        else
            printf("Circular queue is full\n");
    }
}
void del()
{
    if(front==-1)
        return;
    front=(front+1)%n;
    if(front==rear)
        front=rear=-1;
    printf("Element removed");
}
void dis()
{
    int i;
    for (i=front;;i=(i+1)%n)
    {
    printf("%d",a[i]);
    if(i==rear)
    break;
    }
}

