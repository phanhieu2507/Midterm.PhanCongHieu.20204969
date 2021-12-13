#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book
{
           char name[10];
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
     
    char name[10];
    char phonenumber[10];
    char mail[10];
    
  for(int i=0;i<10;i++)
  fscanf(f,"%s %s %s\n",A[i].name,A[i].phonenumber,A[i].mail);
    
    fclose(f);

}

int BinarySearch( char name[] , int N ) {
int Low, Mid, High;
Low = 0; High = N - 1;
while( Low <= High ) {
Mid = ( Low + High ) / 2;
if( strcmp(A[ Mid ].name, name) < 0 )
Low = Mid + 1;
else if(strcmp(A[ Mid ].name, name) > 0)
High = Mid - 1;
else
return Mid; /* Found */
}
return -1; /* NotFound is defined as -1 */
}
void print(int a)
{    
   FILE *f;
     f=fopen("output.txt","w");
   if(a!=-1) 
  fprintf(f,"%s %s %s\n",A[a].name,A[a].phonenumber,A[a].mail);
   else  fprintf(f,"NotFound");
     fclose(f);
}
void main()
{
    get();
    char b[10];
    printf("Nhap ten: ");
    scanf("%s",b);
    print(BinarySearch(b,6));
    
}

