
#include<stdio.h>
char stack[100] ;
char a[100],b[100];
int be=0;
int top=-1;
int empty()
{
    if (top ==-1)
    return 1;
    else return 0;
}
int full()
{
    if (top ==999)
    return 1;
    else return 0;
}
void push(char x)
{   top++;
    stack[top]=x;
    
}
char pop()
{    top=top-1;
     return stack[top+1];
  
}

void get()
{
    char c;
    int i=0;
    printf("Nhap bieu thuc: ");
    scanf("%s",a);
}
 
int check1(char y)
    {
        if(y=='+'||y=='-')
        return 1; else return 0;
    }
int check2(char z)
    {
        
        if(z=='*'||z=='/')
        return 1; else return 0;
    }
 void change()
{   int c=0;
    while (c==0)
    {
        b[be]=pop();
        be++;
        c=empty();
    }
    
}   
void result(char x)
{   
    if('0'<=x&&x<='9')
    { b[be]=x;be++;}
    else if(check1(x)==1&&check2(stack[top])==1) {change();push(x);}
    else push(x);
}

int stack2[100] ;
char a2[100],b2[100];
int be2=0;
int top2=-1;
int empty2()
{
    if (top2 ==-1)
    return 1;
    else return 0;
}
int full2()
{
    if (top2 ==999)
    return 1;
    else return 0;
}
void push2(char x)
{   top2++;
    stack2[top2]=x;
    
}
int pop2()
{    top2=top2-1;
     return stack2[top2+1];
  
}
void result2(char x)
{    int a,b,c;
    if('0'<=x&&x<='9')
    push2(x-48);
    else if(x=='+')
    {
        a=pop2();
        b=pop2();
        c=a+b;
        push2(c);
        
    }
     else if(x=='*')
    {
        a=pop2();
        b=pop2();
        c=a*b;
        push2(c);
        
    }
}

void main()
{   get();
    int i=0;
    while(a[i]!='\0')
    {
        result(a[i]);
        i++;
    }
    change();
    int k=0;
    while(b[k]!='\0')
    {
        a2[k]=b[k];
        k++;
    }
    
    int l=0;
    while(a2[l]!='\0')
    {
        result2(a2[l]);
        l++;
    }
printf("%d",pop2());  
}