#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct book
{
           char name[100];
           char phonenumber[100];
           char mail[100];
        
}  book;
book A[100];
int dem=0;
void addpeople(char name[], char a[], char mail[])
{    strcpy(A[dem].name,name);
     strcpy(A[dem].phonenumber,a);
     strcpy(A[dem].mail,mail);
    dem++;
}
void get()
{ 
     FILE *f;
    f=fopen("input.txt","r");
    if(f==NULL) printf("Can't open file");
     
    char name[100];
    char phonenumber[100];
    char mail[100];
    
  for(int i=0;i<6;i++)
  {fscanf(f,"%s %s %s\n",name,phonenumber,mail);
     enqueue(name,phonenumber,mail);
   }
    
    fclose(f);

}
int front=0,rear=-1;
bool empty()
{   if(rear<front) return true;
else return false;
}
bool full()
{
    if(rear-front>=10) return true;
    else return false;
}
int dequeue()
{
   
        front++;
    
    return front;
}
void enqueue(char a[],char b[],char c[])
{
    rear++;
    strcpy(A[rear].name,a);
    strcpy(A[rear].phonenumber,b);
    strcpy(A[rear].mail,c);    
}
int cmp(char a[],char b[])
{
    if(strcmp(a,b)==0) return 1;
    else return 0;
}
void print(char a[],char b[], char c[])
{    
   FILE *f;
     f=fopen("output.txt","w");  
  fprintf(f,"%s %s %s\n",a,b,c);
     fclose(f);
}
void searching(char a[])
{ int x=dequeue();
    while(empty()==false)
    {   x=dequeue();
        if(cmp(a,A[x].name)) print(A[x].name,A[x].phonenumber,A[x].mail);
        
    }

}
void main()
{
    get();
    char b[10];
    printf("Nhap ten: ");
    scanf("%s",b);
    searching(b);

    
}

