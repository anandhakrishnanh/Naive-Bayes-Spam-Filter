#include<stdio.h>
#include<string.h>
void main()
{
	char email[2][10];
	int decision=10;
	printf("The learning procedure is going to start......\n");
	for(int i=0;1==1;i=i+1)
	{
		printf("Ente the %d th email: ",i);
		scanf("%s",&email[i]);
	    printf("\nContinue Learning: Press 1\nGo to Testing: Press 0\n");
		scanf("%d",&decision);
		if(decision==0)
		break;
	}
}
