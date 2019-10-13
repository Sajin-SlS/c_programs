#include<stdio.h>
#include<string.h>
char s[50];
int top=-1;
push(char elem)
{
        s[++top]=elem;

}
char pop()
{
    return(s[top--]);
}

int pr(char elem)
{
switch(elem)
    {
    case '+':
    case '-':return 2;
    case '*':
    case '/':return 3;
    case '^':return 4;
    }
    return -1;
}
int main()
{
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("Read the Infix Expression?\n");
    scanf("%s",infx);
    strcat(infx,")");
    push('(');
    while( (ch=infx[i++])!='\0')
    {

        if(isalnum(ch))
                prfx[k++]=ch;
        else if( ch == ')')
        {
                while( s[top] != '(')
                    prfx[k++] = pop();
                elem=pop();
        }
        else if(ch=='(')
            push('(');
        else
        {
            while(pr(s[top]) >= pr(ch))
                prfx[k++]=pop();
            push(ch);
        }
    }
    prfx[k]='\0';
    printf("\n\nGiven Infix Expn: %s  Prefix Expn: %s\n",infx,prfx);
}
