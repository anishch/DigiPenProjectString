// StringSearch.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[sizeof(input)];
char entire[sizeof(entire)];

int main()
{
   printf("StringSearch Initialized\n");
   printf("Please input the text in which you would like to search.\n");
   gets(input);
   printf("Please enter your search terms");
   gets(entire);
   for (int i = 0; i < input; i++) {
	   for (int s = 0; s < entire; s) {
		   if (entire[s] != input[i]) {
			   s = 0;
			   if (input[entire] = NULL) {
				   printf("Sorry, the exact term that you're looking for does not exist");
			   }
		   }
		   else if (entire[i] == input[s]){
			   s++;
			   if (input[s] == NULL) {
				   printf("Congratulations, what you're looking for is in this block of text");
			   }
		   }
	   }
   }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
