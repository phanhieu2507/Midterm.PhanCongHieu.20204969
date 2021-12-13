#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book
{
           char name[10];
           char phonenumber[100];
           char mail[100];
       struct book *next;
};
typedef struct book *book;
book head =NULL;
int dem=0;
void addpeople(char name[], char a[], char mail[])
{    book node;
    node=(book)malloc(sizeof(struct book));
    strcpy(node->name,name);
     strcpy(node->phonenumber,a);
     strcpy(node->mail,mail);
   if(head== NULL)
   {
       head=node;node->next=NULL;
   } else {node->next=head; head= node;}
   return head; 
}
void get()
{ 
     FILE *f;
    f=fopen("input.txt","r");
    if(f==NULL) printf("Can't open file");
     
    char name[100];
    char phonenumber[100];
    char mail[100];
    while( fscanf(f,"%s %s %s\n",name,phonenumber,mail)!=EOF)
    {
         
       addpeople(name,phonenumber,mail);
    }
    fclose(f);

}
void print(char a[],char b[], char c[])
{    
   FILE *f;
     f=fopen("output.txt","w");  
  fprintf(f,"%s %s %s\n",a,b,c);
     fclose(f);
}
int cmp(char a[],char b[])
{
    if(strcmp(a,b)==0) return 1;
    else return 0;
}
void searching(char a[])
{
    book p;
    p=head;
    while(p->next!=NULL)
    { if(cmp(p->name,a)) print(p->name,p->phonenumber,p->mail);
       p=p->next;
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

