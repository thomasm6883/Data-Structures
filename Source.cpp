#include <iostream>
#include <string>
#include<algorithm>
#include<ctime>

using namespace std;

const int MAX_SIZE = 1000;

void sortArray(char myCharList[]);
void printChars(char myCharList[]); 
int removeDuplicateChars(char myCharList[]);

char myCharList[MAX_SIZE];

int main() {
	srand(time(nullptr));
	//A-Z = [65-90]
	for (int i = 0; i < 1000; i++) {
		int temp = (rand() % 26) + 65;
		myCharList[i] = static_cast<char>(temp);
	}
	//sort array
	printChars(myCharList);
	sortArray(myCharList);
	printChars(myCharList);
	//remove Dups
	removeDuplicateChars(myCharList);
	printChars(myCharList);
}

void sortArray(char mycharList[]) {
	//counting sort
	int count[26];
	char temp[MAX_SIZE];
	//create count list according to each value in the original list
	for (int i = 0; i < 26; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		int countIndex = mycharList[i] - 65;
		count[countIndex]++;
	}
	//update count list so that the 'nth' element is equal to itself+the 'n-1'th element
	for (int i = 1; i < 26; i++) {
		count[i] += count[i - 1];
	}
	//sort & decrease count for each when used
	for (int i = 0; i < MAX_SIZE; i++) {
		temp[count[(mycharList[i]-65)]-1] = mycharList[i];
		count[mycharList[i]-65]--;
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		myCharList[i] = temp[i];
	}
}

int removeDuplicateChars(char mycharList[]) {
	/*
	* loop through the character list until it is detected that there are the 26 
	* different characters. *This only works with a sorted array* If a non dup is 
	* found, it can be moved to the front. From the point at which 26 characters 
	* are placed at the front, since i know it is a sorted array for alphabetical 
	* characters, then for the rest of the array, fill it with '$'
	* 
	* 
	*/

	int j = 0;
	int i = 0;

	while(j < 26) {
		if (mycharList[i] != mycharList[i + 1]) {
			mycharList[j] = mycharList[i];
			j++;
		}
		i++;
		if (j == 26) {
			for (int x = j; x < MAX_SIZE; x++) {
				mycharList[x] = '$';
			}
		}
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		myCharList[i] = mycharList[i];
	}
	
	return j;
}

void printChars(char mycharList[]) {
	cout << "[" << mycharList[0];
	for (int i = 1; i < MAX_SIZE; i++) {
		cout << ", " << mycharList[i];
	}
	cout << "]";
	cout << "\n========================================================================================================================" << endl;
}