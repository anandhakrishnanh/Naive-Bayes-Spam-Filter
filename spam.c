#include<stdio.h>
#include<string.h>
//creartes a structure


struct word 
{
char words[30];
int spam_word;
int ham_word;
float sbyw;
};

struct word_test //struct to store the testing values
{
	char words[30];
	int freq;
	int spamfreq;
	int hamfreq;
};
//main function starts
void main()
{ 
	int spamorham;//variable to store if the email is spam or not`;
	printf("This is the learning phase......\n");
	int br=0,i=0;
//initialize the struct where all the words will be stored
	struct word learn[1000];
//sets all the frequencies of the words to zero
	for(int i=0;i<100;i=i+1)
	{
		learn[i].spam_word=0;
		learn[i].ham_word=0;
		learn[i].sbyw=0;
	}	
	int struct_control=0;
	while(br!=1)
	{	
		char lr[100];
		printf("\nEnter the %dth email: ",i+1);
		gets(lr); //gets the ith email
		printf("\nEnter if the email is spam or ham:\nEnter 1 for Spam and 0 for Ham\n");
		scanf("%d",&spamorham);
//Now we have to take the email which is in lr to individual words in struct learn
		char temp[10];
		int temp_control=0;
//now we need to make that repeating words are not added to the struct 	
		for(int j=0;lr[j]!= NULL ;j=j+1)//loop until full stop is observed
		{
		
			if((int)lr[j]==32||(int)lr[j]==46) //ascii code for space=32 or fullstop=46
			{	
				for(int l=0;l<10;l=l+1)
				{
					if(strcmp(learn[l].words,temp)==0)
					{
						if(spamorham==1)
						learn[l].spam_word=learn[l].spam_word+1;
						else
						learn[l].ham_word=learn[l].ham_word+1;
						temp_control=0;
						goto help;
					}

				}
				strcpy(learn[struct_control].words,temp);
	
				if(spamorham==1)
				learn[struct_control].spam_word=learn[struct_control].spam_word+1;
				else
				learn[struct_control].ham_word=learn[struct_control].ham_word+1;
			
		
				temp_control=0;
				struct_control=struct_control+1;
				memset(temp, NULL, sizeof temp);
			}
			if(lr[j]==' ')
			continue;
			temp[temp_control]=lr[j];
			temp_control=temp_control+1;
			help:
				printf("");
			
			
			
			
		}		

		memset(lr, '\0' , 100*sizeof(char));
		i=i+1;

		printf("\nEnter '1' to go to testing phase Enter '0' to continue learning\n");
		scanf("%d",&br);
		//if(br==1)//edit removed break statement since the while loop checks if br is one or not everytime
		//break;
	}
	for(int k=0;k<struct_control;k=k+1)
	printf("The words are:%s\nSpam occurence:%d\nHam occurence:%d\n\n",learn[k].words,learn[k].spam_word,learn[k].ham_word);
	
//testing phase 
//for loop required if we need to test multiple emails
	//edit  this part is where we calculate and store the p(s/w) of all the words
	//to calculat the total number of spam words
	int total_spam=0,total_ham;
	for(int j=0;learn[j].ham_word||learn[j].spam_word !=0;j=j+1)
	{
		total_spam=total_spam+learn[j].spam_word;
	}
	
	for(int j=0;learn[j].ham_word||learn[j].spam_word !=0;j=j+1)
	{
		int s=3;
		float n,wbys,wbyh,temp;
		n=learn[j].ham_word+learn[j].ham_word;
		printf("888888%s88888888888",learn[j].words);
		wbys=(learn[j].spam_word/total_spam);
		wbyh=learn[j].ham_word/total_ham;
		temp=(wbys/(wbys+wbyh));
		learn[j].sbyw=((3*0.5)+(n*temp))/(3+n);
		printf("******************%f************",learn[j].sbyw);
		
	}
	//edit
	
	
	br=0;
	while(br!=1)
	{	
		struct word_test test[100];
		for(int i=0;i<100;i=i+1)
		{
			test[i].freq=0;
			test[i].spamfreq=0;
			test[i].hamfreq=0;
		}
		char ts[100];
		int test_control=0;
		printf("\nEnter the email to be tested: \n");
		gets(ts); //gets the ith email
		
//Now we have to take the email which is in lr to individual words in struct learn
		char temp[10];
		int temp_control=0;
//now we need to make that repeating words are not added to the struct 	
		for(int j=0;ts[j]!= NULL ;j=j+1)//loop until full stop is observed
		{
		
			if((int)ts[j]==32||(int)ts[j]==46) //ascii code for space=32 or fullstop=46
			{	
				for(int l=0;l<10;l=l+1)
				{
					if(strcmp(test[l].words,temp)==0)
					{
						test[l].freq=test[l].freq+1;
						temp_control=0;
						goto help1;
					}

				}
				strcpy(test[test_control].words,temp);
	
				test[test_control].freq=test[test_control].freq+1;
			
		
				temp_control=0;
				test_control=test_control+1;
				memset(temp, NULL, sizeof temp);
			}
			if(ts[j]==' ')
			continue;
			temp[temp_control]=ts[j];
			temp_control=temp_control+1;
			help1:
			printf("");
			
		}		

		memset(ts, '\0' , 100*sizeof(char));
		i=i+1;

		
		//if(br==1)//edit removed break statement since the while loop checks if br is one or not everytime
		//break;
		
		for(int m=0;m<test_control;m=m+1)
		{
			for(int n=0;n<100;n=n+1)
			{
				if(strcmp(test[m].words,learn[n].words)==0)
				{
					test[m].spamfreq=learn[n].spam_word;
					test[m].hamfreq=learn[n].ham_word;
				}
			}
			
		}	
		
		for(int k=0;k<test_control;k=k+1)
		printf("The words are:%s\nFrequency:%d\nSpam occurence:%d\nHam occurence:%d\n\n",test[k].words,test[k].freq,test[k].spamfreq,test[k].hamfreq);
//edit
		//Now for the main part as in calculating the probability of everything
		
	
	
	
	
	
	
	
	
	
	
		printf("\nDo you want to continue testing\nPress 1:STOP and Press 0:Continue testing\n");
		scanf("%d",&br);	
	}
	
	
//edit
}



















