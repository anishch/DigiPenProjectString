#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100000

int splitEntire() {
	
}

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
			   wordlength[z] = searchTermincrement - wordlength[z - 1];
		   z++; //math here is wrong
		   }
	   }
   }
   numwordsinEntire = numwordsinEntire + 1; 
   for (int wordbyword = 0; wordbyword < numwordsinEntire; wordbyword++) {
	   char* words = malloc(wordlength[wordbyword] * sizeof(char));
	   words++;
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
}


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
