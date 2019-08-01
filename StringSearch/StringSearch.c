#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100000
#define MAX_WORDS 33;
#define MAX_WORD_LENGTH 45;

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
		   z++; //math here may be wrong
	   }
   }
   numwordsinEntire = numwordsinEntire + 1; 
   printf("%d\n", numwordsinEntire);
   printf("%d\n", wordlength[1]);
   int i = 0;
   char arrayofwords[33][45] = { 0 };
   for (int wordbyword = 0; wordbyword < numwordsinEntire; wordbyword++) {
	   char* currentWord = malloc(wordlength[wordbyword] * sizeof(char));
	   while (*currentWord < wordlength[wordbyword]) {
		   if (*currentWord != ' ') {
			   *currentWord = entire[wordbyword];
			   currentWord++;
		   }
		   else if (entire[wordbyword] == ' ') {
			   *currentWord = NULL;
			   wordbyword++;
		   }
	   }
	   strcpy_s(arrayofwords[i], 45, currentWord);
	   i++; 
   }
   int m = 0;
   int numblocksinInput = 0;
   int articlelength[MAX_LENGTH];
   char arrayofarticles[45][MAX_LENGTH];
   for (int blocksoftext = 0; blocksoftext <= strlen(input); blocksoftext++) {
	   if (input[blocksoftext] == '@') {
		   numblocksinInput++;
		   if (m == 0) {
			   articlelength[m] = blocksoftext - 1;
		   }
		   else if (m > 0) {
			   articlelength[m] = blocksoftext - wordlength[m - 1] - 1;
		   }
		   m++; //math here may be wrong
	   }
   }
   numblocksinInput = numblocksinInput + 1;
   int l = 0;
   for (int articlebyarticle = 0; articlebyarticle < numblocksinInput; articlebyarticle++) {
	   char* currentarticle = malloc(articlelength[articlebyarticle] * sizeof(char));
	   while (*currentarticle < articlelength[articlebyarticle]) {
		   if (*currentarticle != '@') {
			   *currentarticle = input[articlebyarticle];
			   articlebyarticle++;
		   }
		   else if (input[articlebyarticle] == '@') {
			   *currentarticle == NULL;
			   articlebyarticle++;
		   }
	   }
	   strcpy_s(arrayofarticles[l], MAX_LENGTH, currentarticle);
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
				   for (int z = 0; z <= (strlen(input) + 1); z++){
					   printf("%c", arrayofarticles[b][z]);
				   }
				   printf("\n");
			   }
		   }
	   }
   }
}


if (q < 3) {
	printf("Suggested Results\n");
	printf("-----------------\n");
	for (int x = 0; x < l; x) { //loops over each article
		for (int w = 0; w < 33; w) { //loops over each word in search term
			for (int p = 0; p < 45; p) { //loops over each character in each word in search term
				for (int u = 0; u < MAX_LENGTH; u++) { //loops over each character in article
					if (arrayofwords[w][p] != arrayofarticles[x][u]{ //if they aren't equal to each other
						p = 0; //set p to 0
						if (arrayofarticles[x][u] = NULL) {
							w++; //look at next word
							u = 0; //start over for original article
							break;  
						}
					}
					else if (arrayofwords[w][p] == arrayofarticles[x][u]) {
						p++;
					}
				}
			}
		}
	}
}

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
