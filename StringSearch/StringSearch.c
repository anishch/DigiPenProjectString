#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100000
#define MAX_WORDS 33;
#define MAX_WORD_LENGTH 45;

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
	for (int searchTermincrement = 0; searchTermincrement <= strlen(entire); searchTermincrement++) { //for increment going through characters in entire (add)
		if (entire[searchTermincrement] == ' ') { //if we have hit a space, increment numwords by one
			numwordsinEntire++; //incrementing number of words
			if (z == 0) { //if z is zero, 
				wordlength[z] = searchTermincrement; //correct and verified by anish at 9:41 P.M.
			}
			else if (z > 0) { //if z is greater than zero
				wordlength[z] = searchTermincrement - wordlength[z - 1]; //THIS IS WRONG
			}
			z++;  //incrementing z for next round 
		}
	}
	numwordsinEntire = numwordsinEntire + 1; //number of words is 1 more than how many spaces exist.
	printf("%d\n", numwordsinEntire); //PRINTCHECKS
	printf("%d\n", wordlength[1]); //PRINTCHECKS
	int i = 0; //setting i to zero
	char arrayofwords[33][45] = { 0 }; //creating a character array of words (how many words by how long each word reasonably can be)
	int g = 0;
	for (int wordbyword = 0; wordbyword < numwordsinEntire; wordbyword++) { //creating a for loop that goes through each word
		char* currentWord = malloc(wordlength[wordbyword] * sizeof(char)); //creating a character array for word number x
		if (currentWord <= wordlength[wordbyword] + 1) { //while we haven't pointed to all the letters yet in the word (SHOULD I USE ASTERISK HERE??)
			if (entire[g] != ' ' || entire[g] != NULL) { //if we are not pointing to a space in entire
				*currentWord = entire[g]; //add the character in entire to currentWord pointer 
				currentWord++; //pointer move to next space or sequence
				wordbyword--;
				g++;
			}
			else if (entire[g] == ' ' || entire[wordbyword] == NULL) { //if the character in entire is a space
				*currentWord = NULL; //add null character to array
				g++; //wordbyword++; //increment number of words we've gone through 
			}
		}
		strcpy_s(arrayofwords[i], 45, currentWord); //copy currentword to a two-dimensional array of row i
		i++;  //increment i or row number 
	}
	int m = 0; //setting m to zero
	int numblocksinInput = 0; //setting numblocksinInput to zero
	int articlelength[MAX_LENGTH]; //creating a one-dimensional int array of lengths of each article
	char arrayofarticles[45][MAX_LENGTH]; //creating a two-dimensional array of articles -> 45 potential articles (a stretch) * MAXIMUM LENGTH OF BLOCK (A STRETCH)
	for (int charsoftext = 0; charsoftext <= strlen(input); charsoftext++) { //creating for loop that goes through characters of text, # is incremented
		if (input[charsoftext] == '@') {  //if we hit an @
			numblocksinInput++; //incrementing number of blocks
			if (m == 0) {  //if 1st position in one-d array of lengths)
				articlelength[m] = charsoftext;  //setting length of first article to chars of text (we already know the length of the article)
			}
			else if (m > 0) { //(if greater than 1st position in one-d array of lengths) 
				articlelength[m] = charsoftext - wordlength[m - 1] - 1; //MATH WRONG
			}
			m++; //incrementing m
		}
	}
	numblocksinInput = numblocksinInput + 1; //adds one, same principle
	int l = 0; //setting integer l to zero
	int t = 0;
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
			int arrayofhits[MAX_LENGTH];
			/* **arrayofhits = malloc(MAX_LENGTH * sizeof(int));
			*/
			int x = 0;
			if (q < 3) {
				printf("Suggested Results\n");
				printf("-----------------\n");
				int f = 0; //f is the count of how many 'hits'
				for (int x = 0; x < l; x) { //loops over each article
					for (int w = 0; w < 33; w) { //loops over each word in search term
						for (int p = 0; p < 45; p) { //loops over each character in each word in search term
							for (int u = 0; u < MAX_LENGTH; u++) { //loops over each character in article
								if (arrayofwords[w][p] != arrayofarticles[x][u]) { //if they aren't equal to each other
									p = 0; //set p to 0
									if (arrayofarticles[x][u] == NULL) {
										w++; //look at next word
										u = 0; //start over for original article
										break;
									}
									else if (arrayofwords[w][p] == arrayofarticles[x][u]) { //if they are equal characters
										p++; //increase p as well
										if (arrayofwords[w][p] == NULL) { //if they have gone through all the words
											f++; //increase number of 'hit'
											arrayofhits[x] = f;
											*arrayofhits = arrayofarticles[x];
											f = 0;
											x++; //looking at second article
										}
									}
								}
							}
						}
					}
				}
				for (int r = 0; r < MAX_LENGTH; r++) {
					//*arrayofarticles[x] = arrayofhits[r];
				}
				for (int y = 0; y < MAX_LENGTH; y++)                     //Loop for ascending ordering
				{
					for (int c = 0; c < MAX_LENGTH; c++)             //Loop for comparing other values
					{
						if (arrayofhits[c] < arrayofhits[y])                //Comparing other array elements
						{
							int tmp = arrayofhits[c];         //Using temporary variable for storing last value
							arrayofhits[y] = arrayofhits[c];            //replacing value
							arrayofhits[c] = tmp;             //storing last value
						}
					}
				}
			}
		}
	}
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
