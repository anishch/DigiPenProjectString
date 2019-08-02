#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 10000
#define MAX_WORDS 33
#define MAX_WORD_LENGTH 45

int main()
{
	char input[MAX_LENGTH]; //creating an array for your entire input (your block of text)
	char entire[MAX_LENGTH]; //creating an array for your entire search term
	printf("StringSearch Initialized\n"); //prints 
	printf("Please input the text in which you would like to search. (Max 1000 characters)\n"); //prints
	gets_s(input, MAX_LENGTH); //gets input and puts it into an array
	printf("Please enter your search terms\n"); //prints
	gets_s(entire, MAX_LENGTH); //gets search terms and puts it into an array
	int numwordsinEntire = 0; //sets default number of words counted to zero
	int z = 0; //sets 'spot#' in array created below equal to zero
	int wordlength[33]; //creates an integer array of 33 (max number of words) with each of their wordlength
	int recordofsearchterm[MAX_LENGTH];
	//for loop below is wrong
	for (int searchTermincrement = 0; searchTermincrement <= strlen(entire); searchTermincrement++) { //for increment going through characters in entire (add)
		if (entire[searchTermincrement] == ' ' || entire[searchTermincrement] == '\0') { //if we have hit a space, increment numwords by one
			numwordsinEntire++; //incrementing number of words
			if (z == 0) { //if z is zero, 
				recordofsearchterm[z] = searchTermincrement;
				wordlength[z] = searchTermincrement; //correct and verified by anish at 9:41 P.M.
				z++;  //incrementing z for next round
			}
			else if (z > 0) { //if z is greater than zero
				recordofsearchterm[z] = searchTermincrement;
				wordlength[z] = searchTermincrement - recordofsearchterm[z - 1] - 1;
				z++;  //incrementing z for next round
			}
		}
	}
	printf("%d\n", numwordsinEntire); //PRINTCHECKS - CORRECT
	printf("%d\n", wordlength[0]); //PRINTCHECKS - CORRECT 
	printf("%d\n", wordlength[1]); //PRINTCHECKS - CORRECT
	char arrayofwords[33][45] = { 0 }; //creating a character array of words (how many words by how long each word reasonably can be)
	//for loop below seems wrong
	int j = 0, k;
	for (int i = 0; i < numwordsinEntire; i++) { //creating a for loop that goes through each word
		char currentWord[MAX_WORD_LENGTH]; //creating a character array for word number x
		for (k = 0; !(entire[j] == ' ' || entire[j] == '\0'); j++, k++) { //while we haven't pointed to all the letters yet in the word (SHOULD I USE ASTERISK HERE??)
			currentWord[k] = entire[j]; //add the character in entire to currentWord pointer 
		}
		j++;
		currentWord[k] = '\0';
		strcpy_s(arrayofwords[i], 45, currentWord); //copy currentword to a two-dimensional array of row i
	}
	int r = 0; //setting m to zero
	int numblocksinInput = 0; //setting numblocksinInput to zero
	int articlelength[MAX_LENGTH]; //creating a one-dimensional int array of lengths of each article
	char arrayofarticles[45][MAX_LENGTH]; //creating a two-dimensional array of articles -> 45 potential articles (a stretch) * MAXIMUM LENGTH OF BLOCK (A STRETCH)
	int whatcharareweon[MAX_LENGTH];
	for (int charsoftext = 0; charsoftext <= strlen(input); charsoftext++) { //creating for loop that goes through characters of text, # is incremented
		if (input[charsoftext] == '@' || input[charsoftext] == '\0') {  //if we hit an @
			numblocksinInput++; //incrementing number of blocks
			if (r == 0) {  //if 1st position in one-d array of lengths)
				articlelength[r] = charsoftext;  //setting length of first article to chars of text (we already know the length of the article)
				whatcharareweon[r] = charsoftext;
			}
			else if (r > 0) { //(if greater than 1st position in one-d array of lengths) 
				whatcharareweon[r] = charsoftext;
				articlelength[r] = charsoftext - whatcharareweon[r - 1] - 1; //MATH CORRECTED
			}
			r++; //incrementing m
		}
	}
	int m = 0, n;
	int l = 0;
	for (l = 0; l < numblocksinInput; l++) { //creating a for loop that goes through each word
		char currentarticle[MAX_LENGTH]; //creating a character array for word number x
		for (n = 0; !(input[m] == '@' || input[m] == '\0'); m++, n++) { //while we haven't pointed to all the letters yet in the word (SHOULD I USE ASTERISK HERE??)
			currentarticle[n] = input[m]; //add the character in entire to currentWord pointer 
		}
		m++;
		currentarticle[n] = '\0';
		strcpy_s(arrayofarticles[l], MAX_LENGTH, currentarticle); //copy currentword to a two-dimensional array of row i
	}
	int s = 0;
	int q = 0;
	int count = 0;
	for (int b = 0; b < l; b++) { //creating for loop for all articles
		for (int i = 0; i <= (strlen(input) + 1); i++) { //creating for loop for all characters per article
			if (entire[s] != arrayofarticles[b][i]) { //if they are not equal
				s = 0; //whatever we've counted, it's not applicable if the whole term doesn't match
				if (input[i] == NULL && s == 0) { //if nothing is there for Article #B, move on to Article #B + 1
					continue;
				}
			}
			else if (entire[s] == arrayofarticles[b][i]) {
				s++;
				if (entire[s] == NULL) {
					q++;
					for (int z = 0; z <= (strlen(input) + 1); z++) {
						printf("%c", arrayofarticles[b][z]);
					}
					printf("\n");
				}
			}
		}
	}
	int arrayofhits[MAX_LENGTH] = { 0 };
	int x = 0;
	int f = 0; //f is the count of how many 'hits'
	int w = 0;
	int p = 0;
	if (q < 3) {
		printf("Suggested Results\n");
		printf("-----------------\n");
		for (int u = 0; u < MAX_LENGTH; u++) { //loops over each character in article
			if (arrayofwords[w][p] != arrayofarticles[x][u]) { //if they aren't equal to each other
				p = 0; //set p to 0
				if (arrayofarticles[x][u] == NULL) {
					w++; //look at next word
					if (w < 33) {
						u = 0; //start over for original article
					}
					else {
						u++;
					}
					continue;
				}
			}
			else if (arrayofwords[w][p] == arrayofarticles[x][u]) { //if they are equal characters
				p++; //increase p as well
				if (arrayofwords[w][p] == NULL) { //if they have gone through all the words (meaning exist in article)
					f++; //increase number of 'hit'
					arrayofhits[x] = f; //(create new array)
					f = 0;
					x++; //looking at second article
				}
			}
		}
		char temp[MAX_LENGTH];
		for (int y = 0; y < MAX_LENGTH; y++)       //Loop for descending ordering
		{
			for (int c = 0; c < MAX_LENGTH; c++)             //Loop for comparing other values
			{
				if (arrayofhits[c] == 0)
					break;
				if (arrayofhits[c] < arrayofhits[y])                //Comparing other array elements
				{
					int tmp = arrayofhits[c];         //Using temporary variable for storing last value
					arrayofhits[c] = arrayofhits[y];            //replacing value
					arrayofhits[y] = tmp;    //storing last value
					strcpy_s(temp, MAX_LENGTH, arrayofarticles[c]);
					strcpy_s(arrayofarticles[c], MAX_LENGTH, arrayofarticles[y]);
					strcpy_s(arrayofarticles[y], MAX_LENGTH, temp[y]);
				}
			}
		}
		for (int u = 0; u < 2; u++) {
			printf("%s\n", arrayofarticles[u]);
		}
	}
}



/* 
			for (int x = 0; x < l; x) { //loops over each article
				for (int w = 0; w < 33; w) { //loops over each word in search term
					for (int p = 0; p < 45; p) { //loops over each character in each word in search term
						for (int u = 0; u < MAX_LENGTH; u++) { //loops over each character in article
							if (arrayofwords[w][p] != arrayofarticles[x][u]) { //if they aren't equal to each other
								p = 0; //set p to 0
								if (arrayofarticles[x][u] == NULL) {
									w++; //look at next word
									u = 0; //start over for original article
									continue;
								}
							}
							else if (arrayofwords[w][p] == arrayofarticles[x][u]) { //if they are equal characters
								p++; //increase p as well
								if (arrayofwords[w][p] == NULL) { //if they have gone through all the words (meaning exist in article)
									f++; //increase number of 'hit'
									arrayofhits[x] = f; //(create new array)
									f = 0;
									x++; //looking at second article
								}
							}
						}
					}
				}
			}

*/




/*char arrayofwords[33][45] = { 0 }; //creating a character array of words (how many words by how long each word reasonably can be)
	//for loop below seems wrong

int j = 0, k;
for (int i = 0; i < numwordsinEntire; i++) { //creating a for loop that goes through each word
	char currentWord[MAX_WORD_LENGTH]; //creating a character array for word number x
	for (k = 0; !(entire[j] == ' ' || entire[j] == '\0'); j++, k++) { //while we haven't pointed to all the letters yet in the word (SHOULD I USE ASTERISK HERE??)
		currentWord[k] = entire[j]; //add the character in entire to currentWord pointer 
	}
	j++;
	currentWord[k] = '\0';
	strcpy_s(arrayofwords[i], 45, currentWord); //copy currentword to a two-dimensional array of row i
}
printf("%s", arrayofwords[0]);



for (int articlebyarticle = 0; articlebyarticle < numblocksinInput; articlebyarticle++) { //creating a for loop that goes through each word
	char* currentarticle = malloc(articlelength[articlebyarticle] * sizeof(char)); //creating a character array for word number x
	if (currentarticle <= articlelength[articlebyarticle] + 1) { //while we haven't pointed to all the letters yet in the word (SHOULD I USE ASTERISK HERE??)
		if (input[t] != ' ' || input[t] != NULL) { //if we are not pointing to a space in entire
			*currentarticle = input[t]; //add the character in entire to currentWord pointer 
			currentarticle++; //pointer move to next space or sequence
			articlebyarticle--;
			t++;
		}
		else if (input[t] == ' ' || input[t] == NULL) { //if the character in entire is a space
			*currentarticle = NULL; //add null character to array
			t++; //wordbyword++; //increment number of words we've gone through 
		}
	}
	strcpy_s(arrayofarticles[l], MAX_LENGTH, currentarticle); //copying into two-dimensional arrayof articles in row number l
	l++;
}


/*
for (int articlebyarticle = 0; articlebyarticle < numblocksinInput; articlebyarticle++) { //creating for loop going through each article if number of blocks isn't reached
	char* currentarticle = malloc(articlelength[articlebyarticle] * sizeof(char)); //declaring separate arrays for each article of their lengths
	while (*currentarticle <= articlelength[articlebyarticle]) { //if we're length of this pointer is if this is wrong does currentarticle - *currentarticle work?
		if (*currentarticle != '@') { //if not pointing to @ sign
			*currentarticle = input[articlebyarticle]; //term in current article is the same as what we've gone through
			articlebyarticle++; //increment articlebyarticle (what article we're going through)
		}
		else if (input[articlebyarticle] == '@') { //if we hit the @sign
			*currentarticle = NULL;
			articlebyarticle++;
		}
	}
	strcpy_s(arrayofarticles[l], MAX_LENGTH, currentarticle); //copying into two-dimensional arrayof articles in row number l
	l++;
}
*/


//strcmp

/*
int main()
{
	char input[MAX_LENGTH];
	char entire[MAX_LENGTH];
	printf("StringSearch Initialized\n");
   printf("Please input the text in which you would like to search. (Max 1000 characters)\n");
   gets_s(input, MAX_LENGTH);
   printf("Please enter your search terms\n");
   gets_s(entire, MAX_LENGTH);
  int numwordsinEntire = 0;
  int z = 0;
  int wordlength[33];
   for (int searchTermincrement = 0; searchTermincrement <= strlen(entire); searchTermincrement++) {
	   if (entire[searchTermincrement] == ' ') {
		   numwordsinEntire++;
		   if (z == 0) {
				wordlength[z] = searchTermincrement;
		   }
		   else if (z > 0){
			   wordlength[z] = searchTermincrement - wordlength[z - 1] - 1;
		   }
		   z++; //math here is wrong
	   }
   }
   numwordsinEntire = numwordsinEntire + 1; 
   printf("%d\n", numwordsinEntire);
   printf("%d\n", wordlength[1]);
   int i = 0;
   char arrayofwords[33][45] = { 0 };
   for (int wordbyword = 0; wordbyword < numwordsinEntire; wordbyword++) {
	   char* currentWord = malloc(wordlength[wordbyword] * sizeof(char));
	   for (*currentWord < wordlength[wordbyword]) {
		   if (*currentWord != ' ') {
			   *currentWord = entire[wordbyword];
			   currentWord++;
		   }
		   else if (entire[wordbyword] == ' ') {
			   wordbyword++;
		   }
	   }
	   strcpy(arrayofwords[i], currentWord);
	   i++; 
   }
   int s = 0;
   int q = 0;
   int count = 0;
   for (int i = 0; i <= (strlen(input)); i++) {
	   for(int j = 0; j <= (strlen(entire)); j++)
		   if (entire[j] == input[i + j]) {
			   count++;
			   if (count == strlen(entire)) {
				   q++;
			   }
		   } 
		   else if (entire[j] != input[i + j]) {
			   j = 0;
			   count = 0;
			   break;
			} 
	}	
   if (q >= 1) {
	   printf("Congratulations, your string is included in your overall block of text!\n");
   }
   printf("Count: %d", q);
   if (q = 0) {

   }
}*/


/*
int main()
{
	char input[MAX_LENGTH];
	char entire[MAX_LENGTH];
	printf("StringSearch Initialized\n");
   printf("Please input the text in which you would like to search. (Max 1000 characters)\n");
   gets_s(input, MAX_LENGTH);
   printf("Please enter your search terms\n");
   gets_s(entire, MAX_LENGTH);
   int s = 0;
   int q = 0;
   for (int i = 0; i <= (strlen(input) + 1); i++) {
	   if (entire[s] != input[i]) {
		   s = 0;
		   if (input[i] == NULL && s == 0) {
			   printf("End of search.\n");
			   if (q >= 1) {
				   printf("Congratulations, the exact term you're looking for is in this block of articles");
			   }
			   printf("Number of occurences: %d\n", q);
			   char character;
			   scanf_s("%c", &character, sizeof(character));
		   }
	   }
		else if (entire[s] == input[i]){
			s++;
			if(entire[s] == NULL){
				q++;
			}
	   }
	}
}*/



/*

int* inputMemory = malloc(strlen(input) * sizeof(char));
   int* entireMemory = malloc((strlen(input)) * sizeof(char));


for (int* inputMemory = 0; inputMemory < strlen(input); inputMemory++) {
	   for (int* entireMemory = 0; entireMemory < strlen(entire); entireMemory) {
		   if (*entireMemory != *inputMemory) {
			   *inputMemory = 0;
			   if (*entireMemory = NULL) {
				   printf("Sorry, the exact term that you're looking for does not exist");
			   }
		   }
		   else if (*entireMemory == *inputMemory) {
			   entireMemory++;
			   if (*inputMemory == NULL) {
				   printf("Congratulations, what you're looking for is in this block of text");
			   }
		   }
	   }
   }

*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
