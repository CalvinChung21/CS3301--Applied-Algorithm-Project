// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

int main()
{
	// data types for input
	unordered_map<int, int> um; // storing the frequencies of input data
	vector<int> input; // storing all the input data
	int tempInt = 0; // for getting individual num input
	char checkInput = 'n'; // for confirming the input

	// for getting input for a single array
	while (checkInput == 'n') {
		// getting input into the vector
		while (tempInt != -1) {
			system("CLS");
			printf("Please enter number for your input array one by one(-1 to finish the input process).\n");
			cin >> tempInt;
			if(tempInt > 0) input.push_back(tempInt);
		}

		// display the input array
		system("CLS");
		printf("Your input for array is:\n");
		printf("[");
		for (unsigned int i = 0; i < input.size(); i++) {
			if (i != input.size() - 1) cout << input[i] << ", ";
			else cout << input[i];
		}
		cout << "]\n";

		// confirmation process
		printf("Confirm?(y/n) ");
		cin >> checkInput;
		if (checkInput == 'y') {
			//save the input data happening frquency into a hash table
			for (unsigned int i = 0; i < input.size(); i++) um[input[i]]++;
		}
		else {
			// reset data
			input.clear();
		}
	}
	system("CLS");

	vector<vector<int>> mainSub;// an array to store all the subsequence
	char checkInputForSub = 'n'; // for confirmation of input

	// for getting the input for subsequnces
	while (checkInputForSub == 'n') {
		vector<int> sub;
		while (tempInt != -2) {
			system("CLS");
			printf("Please enter number of your subsequence one by one.\n");
			printf("(-1 to finish this subsequence and move on to next subsequence)\n");
			printf("(-2 to finish the process)\n");
			cin >> tempInt;
			if (tempInt == -1) {
				system("CLS");
				mainSub.push_back(sub);
				sub.clear();
			}
			else if(tempInt>0)sub.push_back(tempInt);
		}
		mainSub.push_back(sub);
		sub.clear();
		
		// display input subsequences
		system("CLS");
		printf("Your input for subsequences is:\n");
		for (unsigned int i = 0; i < mainSub.size(); i++) {
			vector<int> tempSub = mainSub[i];
			printf("[");
			for (unsigned int j = 0; j < tempSub.size(); j++) {
				if (j != tempSub.size() - 1) cout << tempSub[j] << ", ";
				else cout << tempSub[j];
			}
			printf("]\n");
		}

		printf("\n");
		// confirmation process
		printf("Confirm?(y/n) :");
		cin >> checkInputForSub;
		if (checkInputForSub == 'n') {
			mainSub.clear();
		}
	}
	system("CLS");

	// greedy algorithm
	// sorting the subsequences base on their size
	// from biggest to smallest
	std::sort(mainSub.begin(), mainSub.end(), 
		[](const vector<int>& a, const vector<int>& b) { return a.size() > b.size(); });

	// finding the minimum number of matching subsequences
	// start first by checking the biggest size subsequebce
	// then smaller size subsequence
	vector<int> resultIndex;
	int totalCheckAmount = input.size();
	for (unsigned int i = 0; i < mainSub.size(); i++) {
		vector<int> tempSub = mainSub[i];
		bool overlap = false;
		for (unsigned int j = 0; j < tempSub.size(); j++) {
			if (um[tempSub[j]] != 0) {
				totalCheckAmount--;
				um[tempSub[j]]--;
				overlap = true;
			}
		}
		if (overlap) resultIndex.push_back(i);
	}

	// display result
	if (totalCheckAmount == 0) {
		printf("The minimum number of subsequences : \n");
		for (auto& i : resultIndex) {
			vector<int> tempSub = mainSub[i];
			printf("[");
			for (unsigned int j = 0; j < tempSub.size(); j++) {
				if (j != tempSub.size() - 1) cout << tempSub[j] << ", ";
				else cout << tempSub[j];
			}
			printf("]\n");
		}
	}
	else {
		printf("The programme has encounter an error");
	}
	
}