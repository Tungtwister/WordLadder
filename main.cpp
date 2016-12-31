#include <iostream>
#include <list>
#include <fstream>
#include <queue>
#include <stack>
#include "WordLadder.h"

using namespace std;

int main()
{

   string filename, wordBegin, wordEnd;
   string cheese = "cheese.txt";
   cout << "Enter the name of the dictionary file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter the first word: ";
   cin >> wordBegin;
   cout << endl;
   while (wordBegin.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the first word: ";
      cin >> wordBegin;
      cout << endl;
   }
   cout << "Enter the last word: ";
   cin >> wordEnd;
   cout << endl;
   while (wordEnd.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the last word: ";
      cin >> wordEnd;
      cout << endl;
   }
   
	WordLadder wl(filename);
	
	wl.outputLadder(wordBegin, wordEnd, cheese);
	cout << endl;
	
	return 0;
}
