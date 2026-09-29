 #include<stdio.h>
  2 #define MAX 5
  3
  4 int queue[MAX];
  5 int front=-1;
  6 int rear=-1;
  7
  8 void enqueue(int value)
  9 {
 10     if(rear==MAX-1)
 11         printf("queue overflow\n");
 12     else
 13     {
 14        if(front==-1)
 15           front=0;
 16
 17       rear++;
 18      queue[rear]=value;
 19     }
 20 }
 21
 22 void dequeue()
 23 {
 24     if(front == -1 || front > rear )
 25         printf("queue underflow\n");
 26     else
 27     {
 28         printf("deleted:%d\n",queue[front]);
 29         front++;
 30     }
 31 }
 32 void display()
 33 {
 34     int i;
 35
 36     if(front == 1 || front > rear)
 37        printf("queue is empty\n");
 38     else
 39     {
 40        for(i=front;i<=rear;i++)
 41           printf("%d",queue[i]);
 42
 43       printf("\n");
 44     }
 45 }
 46
 47 int main()
 48 {
 49     int choice,value;
 50
 51     while(1)
 52     {
 53         printf("\n1.enqueue\n");
 54         printf("\n2.dequeue\n");
 55         printf("\n3.display\n");
 56         printf("\n4.exit\n");
 57
 58         printf("enter choice:");
 59         scanf("%d",&choice);
 60
 61         switch(choice)
 62         {
 63             case 1:
 64                 printf("enter value:");
 65                 scanf("%d",&value);
 66                 enqueue(value);
 67                 break;
 68
 69             case 2:
 70                 dequeue();
 71                 break;
 72
 73             case 3:
 74               display();
 75               break;
 76
 77             case 4:
 78               return 0;
 79
 80             default:
 81                printf("invalid choice:\n");
 82         }
 83     }
 84  return 0;
 85 }
    
                                                                                                                                                                             5,13          Top
