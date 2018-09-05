#include<stdio.h>
#define TRUE 1

//function to store the sentance into a word and








main()
{	//storing all the emails as words
	printf("The learning procedure is going to start....\n");
	int i,n,j,m=0,l=0,dec;
	char store[10],words[100][10];
	for(i=0;TRUE;i=i+1)
	{
	printf("Enter the %dth email\n",i+1);
	gets(store);
	for(j=0;TRUE;j++)
	{
		if(store[j]!=' ')
		{
		words[m][l]=store[j];
		l=l+1;
		}
		else
		{
		m=m+1;
		l=0;
		}
		if(store[j]=='/0')
		break;
		
	}
	for(i=0;i<=10;i++)
	printf("%s\n",words[i]);
	printf("Enter 0 inorder to stop learning\n");
	scanf("%d",&dec);
	if(dec==0)
	break;
	}	
}

