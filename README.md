# Spam-filter
This is to make a Naive Bayes spam filter
Please note that till now I have made it in such a way that you have to manually input the messages for training and testing. 

For this Naive Bayes spam filter the filter learns the number of time each word has been used in the case if it a spam or not during the training phase. 
Once the training phase is done the filter calculates the probabilty of the sequence of words being spam or not using the already set of words it has seen in the training phase

    strcpy(learn[struct_control].words,temp);
				if(spamorham==1)
				learn[struct_control].spam_word=learn[struct_control].spam_word+1;
				else
				learn[struct_control].ham_word=learn[struct_control].ham_word+1;
				temp_control=0;
				struct_control=struct_control+1;
				memset(temp, NULL, sizeof temp);
 Here the words are sotred into an array and the whenever the same word is obtained it will update the frequency instead of storing the word again.
 
 Next will be the testing phase once we have the frequency of all the words in HAM and SPAM
 
 The probability of a sentance being spam given it has a word is., 
 
 ![image](https://wikimedia.org/api/rest_v1/media/math/render/svg/dc8c39ec48e65c0ab10dabe343d4da9a9585a77b)

where:
Pr(S|W) is the probability that a message is a spam, knowing that a word is in it;
Pr(S) is the overall probability that any given message is spam;
Pr(W|S) is the probability that the word appears in spam messages;
Pr(H) is the overall probability that any given message is not spam (is "ham");
Pr(W|H) is the probability that the word appears in ham messages.

So according to this if we have all the instances of a word in question in spam messages and ham messages we can calculate the probability for that particular word. 

The frequence of all the words in the test case is found out

     strcpy(test[test_control].words,temp);
				test[test_control].freq=test[test_control].freq+1;
				temp_control=0;
				test_control=test_control+1;
				memset(temp, NULL, sizeof temp); 
Now using the frequency we calculate the probability 

    wbys=(((float)test[j].spamfreq)/(float)total_spam);
		wbyh=((float)test[j].hamfreq)/(float)total_ham;
		sbyw=(wbys/(wbys+wbyh));
		prob[j]=(((float)3*(float)0.5)+((float)test[j].freq*(float)sbyw))/((float)3*(float)test[j].freq);
		printf("\n%d/%d=%f\n",test[j].spamfreq,total_spam,wbys);
	  	printf("\n%d/%d=%f\n",test[j].hamfreq,total_ham,wbyh);
		printf("\nw/s=%f  w/h=%f  prob=%f\n",wbys,wbyh,prob[j]);
