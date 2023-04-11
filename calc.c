#include <stdio.h>
#include <stdlib.h>

#define maxRange 100

void calculate(int a,char op,int b)
{
    switch(op){
        case '+': printf("%d\n",a+b);
            break;
        case '-': printf("%d\n",a-b);
            break;
        case '*': printf("%d\n",a*b);
            break;
        case '/': b!=0?printf("%d\n",a/b):printf("error\n");
            break;
        default: printf("error\n");
            break;
    }
}
/* a is the first number
** b is the second number
** op is the operator char
** flag is the counter of the succeeded requirments
*/
void analyseBuffer(char Buffer[]){
    int flag=0,a,b;
    char op;
    //we trim the spaces by copying all the chars except the spaces to a new char array
    char trimmedBuffer[maxRange];
    int i=0,j=0;
    for(i=0;i<maxRange||j==3;i++){
        if(Buffer[i]!=' ')
        {
            trimmedBuffer[j]=Buffer[i];
            j++;
        }
    }
    //after we trimmed the spaces now we need to look at the first 3 chars
    //a=[0] , op=[1] , b=[2] --> all we need now is to check the validity
    if(trimmedBuffer[0]>='0'&&trimmedBuffer[0]<='9')
    {
        flag++;
        a=trimmedBuffer[0]-'0';
    }
    if(trimmedBuffer[2]>='0'&&trimmedBuffer[2]<='9')
    {
        flag++;
        b=trimmedBuffer[2]-'0';
    }
    if(trimmedBuffer[1]=='+'||trimmedBuffer[1]=='-'||trimmedBuffer[1]=='*'||trimmedBuffer[1]=='/')
    {
        flag++;
        op=trimmedBuffer[1];
    }
    if(flag==3)//The flag will get 3 only when the 3 requirements are met
    {
        calculate(a,op,b);
    }
    else printf("error\n");

}
int main()
{
    char Buffer[maxRange];
    while(fgets(Buffer,sizeof(Buffer),stdin))
    {
        if(Buffer[0]=='e'&&Buffer[1]=='x'&&Buffer[2]=='i'&&Buffer[3]=='t') {break;}
        analyseBuffer(Buffer);
    }
    return 0;
}
