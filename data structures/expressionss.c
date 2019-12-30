#include<stdio.h>
#include<string.h>
int push(char a[],int *top,char x)
    {
    if(*top==999)
        {
        printf("stack full\n");
        return 0;
    }
    *top=*top+1;
    a[*top]=x;
    return 0;
}
char pop(char a[],int *top)
    {
    if(*top==-1)
        {
        printf("stack empty\n");
        return 0;
    }
    char u=a[*top];
    *top=*top-1;
    return u;
}
char pushtop(char a[],int *top)
    {
    if(*top==-1)
        {
        printf("stack empty\n");
        return 0;
    }
    char u=a[*top];
    return u;
}
int priority(char a)
    {
    if(a=='+'||a=='-')
        return 1;
    else if(a=='*'||a=='/')
        return 2;
    return 0;
}
void infixtopostfix(char a[],char x[])
    {
    char y[1000],u;
    int topx=-1,topy=-1;
    int i=0,n=strlen(a);
    for(i=0;i<n;i++)
        {
        if((a[i]>=48&&a[i]<=57)||(a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
            {
            push(x,&topx,a[i]);
        }
        else
            {
                while((topy!=-1)&&(priority(pushtop(y,&topy))>=priority(a[i])))
                    {
                    push(x,&topx,pop(y,&topy));
                }
               push(y,&topy,a[i]);
        }
    }
    while(topy!=-1)
            {
            push(x,&topx,pop(y,&topy));
        }
}
void infixtoprefix(char a[],char x[])
    {
    char y[1000];
    int i,n=strlen(a),topx=-1,topy=-1;
    for(i=n-1;i>=0;i--)
        {
        if((a[i]>=48&&a[i]<=57)||(a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
            {
            push(y,&topy,a[i]);
        }
        else
            {
                while((topx!=-1)&&(priority(pushtop(x,&topx))>priority(a[i])))
                    {
                    push(y,&topy,pop(x,&topx));
                }
               push(x,&topx,a[i]);
        }
    }
    while(topx!=-1)
            {
            push(y,&topy,pop(x,&topx));
        }
   while(topy!=-1)
       {
       push(x,&topx,pop(y,&topy));
   }
}
int main()
    {
    char a[1000],b[1000];
    scanf("%s",a);
    infixtoprefix(a,b);
    printf("prefix expression\n%s\n",b);
    infixtopostfix(a,b);
    printf("postfixexpression\n%s\n",b);
    return 0;
}