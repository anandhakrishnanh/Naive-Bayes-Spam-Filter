<div align="center">

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

</div>

<!-- PROJECT LOGO -->
<br />
<div align="center">

  <h3 align="center">Naive Bayes Spam Filter</h3>

  <p align="center">
    A simple implementation of the Naive Bayes classifier built entirely on C without any libraries 
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
This is a simple implementation of the classic Naive Bayes classifier that classifies whether a given
text is spam or not based on the initial training data it was trained on.

Right now the script requires you to train and test everything one by one ( yes I know it  sucks ) but 
I don't work on C anymore, so I'm not sure if I'm going to update it to be used properly. 

### Built With

This is build entirely on built in C libraries `stdio.h` and `string.h`

<!-- USAGE EXAMPLES -->
## Usage

To train and test the classifier just run `spam.c`, where the first part will be training and the second
part is testing on an unknown text. 

## How it Works

1. First the filter learns the number of times a word has been used in the training phase.  Once 
the training phase is done the filter calculates the probability of the sequence of words being 
spam or not using the already set of words it has seen in the training phase.

```
strcpy(learn[struct_control].words,temp);
if(spamorham==1)
learn[struct_control].spam_word=learn[struct_control].spam_word+1;
else
learn[struct_control].ham_word=learn[struct_control].ham_word+1;
temp_control=0;
struct_control=struct_control+1;
memset(temp, NULL, sizeof temp);
```

Here the words are sotred into an array and the whenever the same word is obtained it will 
update the frequency instead of storing the word again.

2. During the testing phase, we calculate the testing sentance being a HAM (not spam) or SPAM using 

 ![image](https://wikimedia.org/api/rest_v1/media/math/render/svg/dc8c39ec48e65c0ab10dabe343d4da9a9585a77b)

Here,

* `Pr(S|W)` is the probability that a message is a spam, knowing that a word is in it
* `Pr(S)` is the overall probability that any given message is spam
* `Pr(W|S)` is the probability that the word appears in spam messages
* `Pr(H)` is the overall probability that any given message is not SPAM (is HAM)
* `Pr(W|H)` is the probability that the word appears in ham messages

So according to this if we have all the instances of a word in question in spam messages and 
ham messages we can calculate the probability for that particular word.

3. The frequence of all the words in the test case is found out

``` 
strcpy(test[test_control].words,temp);
test[test_control].freq=test[test_control].freq+1;
temp_control=0;
test_control=test_control+1;
memset(temp, NULL, sizeof temp); 
```
Now using the frequency we calculate the probability

```
wbys=(((float)test[j].spamfreq)/(float)total_spam);
wbyh=((float)test[j].hamfreq)/(float)total_ham;
sbyw=(wbys/(wbys+wbyh));
prob[j]=(((float)3*(float)0.5)+((float)test[j].freq*(float)sbyw))/((float)3*(float)test[j].freq);
printf("\n%d/%d=%f\n",test[j].spamfreq,total_spam,wbys);
printf("\n%d/%d=%f\n",test[j].hamfreq,total_ham,wbyh);
printf("\nw/s=%f  w/h=%f  prob=%f\n",wbys,wbyh,prob[j]);
```
<!-- CONTACT -->
## Contact

Your Name - [Anandha Krishnan H](anandhakrishnanh1998@gmail.com) - anandhakrishnanh1998@gmail.com

Project Link: [https://github.com/anandhakrishnanh/Naive-Bayes-Spam-Filter](https://github.com/anandhakrishnanh/Naive-Bayes-Spam-Filter)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/anandhakrishnanh/Naive-Bayes-Spam-Filter.svg?style=for-the-badge
[contributors-url]: https://github.com/anandhakrishnanh/Naive-Bayes-Spam-Filter/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/anandhakrishnanh/Naive-Bayes-Spam-Filter.svg?style=for-the-badge
[forks-url]: https://github.com/anandhakrishnanh/Naive-Bayes-Spam-Filter/network/members
[stars-shield]: https://img.shields.io/github/stars/anandhakrishnanh/Naive-Bayes-Spam-Filter.svg?style=for-the-badge
[stars-url]: https://github.com/anandhakrishnanh/Naive-Bayes-Spam-Filter/stargazers
[issues-shield]: https://img.shields.io/github/issues/anandhakrishnanh/Naive-Bayes-Spam-Filter.svg?style=for-the-badge
[issues-url]: https://github.com/anandhakrishnanh/Naive-Bayes-Spam-Filter/issues
[license-shield]: https://img.shields.io/github/license/anandhakrishnanh/Naive-Bayes-Spam-Filter.svg?style=for-the-badge
[license-url]: https://github.com/anandhakrishnanh/Naive-Bayes-Spam-Filter/blob/master/LICENSE.txt

