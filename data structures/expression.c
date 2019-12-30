#include<stdio.h>
#include<string.h>
int push(int a[],int *top,int x)
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
int pop(int a[],int *top)
    {
    if(*top==-1)
        {
        printf("stack empty\n");
        return 0;
    }
    int u=a[*top];
    *top=*top-1;
    return u;
}
int pushtop(int a[],int *top)
    {
    if(*top==-1)
        {
        printf("stack empty\n");
        return 0;
    }
    int u=a[*top];
    return u;
}
void postfixtoprefix(char a[],int y[])
    {
    int topy=-1,i,n=strlen(a),u,v,j;
    char *p,*q,*r;
    for(i=0;i<n;i++)
        {
        if((a[i]>=48&&a[i]<=57)||(a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
            {
            p=malloc(sizeof(char));
            *p=a[i];
            push(y,&topy,p);
        }
        else
            {
            q=pop(y,&topy);
            r=pop(y,&topy);
            u=strlen(q);
            v=strlen(r);
            p=malloc(sizeof(char)*(u+v+1));
            *p=a[i];
            for(j=1;j<=v;j++)
                {
                *(p+j)=*(r+j-1);
            }
            for(j;j<u+v+1;j++)
                {
                *(p+j)=*(q+j-v-1);
            }
            push(y,&topy,p);
            free(r);
            free(q);
        }
    }
}
void postfixtoinfix(char a[],int y[])
    {
    int topy=-1,i,n=strlen(a),u,v,w,j;
    char *p,*q,*r;
    for(i=0;i<n;i++)
        {
        if((a[i]>=48&&a[i]<=57)||(a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
            {
            p=(char *)malloc(sizeof(char));
            *p=a[i];
            push(y,&topy,p);
        }
        else
            {
            q=pop(y,&topy);
            r=pop(y,&topy);
            u=strlen(q);
            v=strlen(r);
            w=u+v+1;
            p=(char *)malloc(w*sizeof(char));
            for(j=0;j<v;j++)
                {
                *(p+j)=*(r+j);
            }
            *(p+j)=a[i];j++;
            for(j;j<u+v+1;j++)
                {
                *(p+j)=*(q+j-v-1);
            }
            push(y,&topy,p);
            free(r);
            free(q);
        }
    }
}
int main()
    {
    char a[1000];
    int b[1000],i;
    printf("enter postfix expression\n");
    scanf("%s",a);
    printf("infix expression\n");
    postfixtoinfix(a,b);
    printf("%s\n",b[0]);
    printf("prefix expression\n");
    postfixtoprefix(a,b);
    printf("%s\n",b[0]);
    return 0;
}