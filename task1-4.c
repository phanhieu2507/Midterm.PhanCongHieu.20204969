#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct book
{
           char name[10];
           char phonenumber[100];
           char mail[100];
        
}  book;
book A[100];
int dem=0;
int queue[20];
int front=0,rear=-1;
int num=0;
bool empty()
{   if(rear<front) return true;
else return false;

}
bool full()
{
    if(rear-front>=10) return true;
    else return false;
}
void dequeue()
{
    if(empty()==true) printf("Queue is empty");
    else { printf("%s %s %s\n",A[front].name,A[front].phonenumber,A[front].mail);
        front++;
    }
    
}
void enqueue(char a[],char b[],char c[])
{
    rear++;
    strcpy(A[rear].name,a);
    strcpy(A[rear].phonenumber,b);
    strcpy(A[rear].mail,c);    
}
void main()
{ int a;
 char name[100];
    char phonenumber[100];
    char mail[100];
    printf("Nhap dia chi theo cu phap: ten sodienthoai mail .Ket thuc nhap bang EOF(ctrl+z): \n");
  while( scanf("%s %s %s",name,phonenumber,mail)!=EOF)
    {
       
        enqueue(name,phonenumber,mail);
   }
    
  while(full()==true)
    {
        dequeue();
    }
}

