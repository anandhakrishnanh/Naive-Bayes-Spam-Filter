#include<stdio.h>
main()
{
char email[100][1000]={0},word[100]={0};
int fun=0,decision;
printf("Learning procedure is going to start....\n");
for(int i=0;1==1;i++)
{
//getting the emails
printf("Enter the %dth email: ",i);
scanf("%s",&email[i]);

//storing the words
for(int j=0;j<1000;j++)
{
for(int k=0;k<100;k++)
{if(email[i][j]==word[k])
fun=1;

if(fun!=1)
word[j]=email[i][j];
printf("%c\n",word[j]);
i=0;
}
}




scanf("%d",&decision);
if(decision==2)
break;
printf("\nTo continue learning: Press 1		To start testing: Press 2\n");
}

}

