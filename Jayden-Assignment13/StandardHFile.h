///*****************************
/// Jayden Campbell
///Standard H File
///1.0 - Introduced.
/// 
/// 1.1 -
/// -Added getFloat and holdFloat
/// -Added getDouble and holdDouble
/// -Simplified exit function names
/// -Removed ignore()
/// 
/// 1.1.1 -
/// -Added isVowel
/// 
/// 1.1.2 -
/// -Added getRandom
/// 
/// 1.1.3 -
/// -Added [vector] and [fstream]
/// 
/// 1.2
/// -Removed all hold functions
/// -Converted all get functions to a single overloaded function
/// -Fixed some typing errors in all get functions.
/// 
/// Added searchLinear
/// Added searchBinary
/// 
/// Added 1 sortSelection command. 
/// 
/// 1.2.1
/// 
/// Added sortSelection in float and vector^int^
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


void get(int&, string = "Please enter an integer: ");
void get(int&, int, int, string);
void get(float&, string = "Please enter a floating-point number: ");
void get(float&, float, float, string);
void get(double&, string = "Please enter a double: ");
void get(double&, double, double, string);

string getFile();

int getRandom(int, int);

bool isVowel(char);

void leave();

void searchLinear(const int[], int, int, vector<int> &);
void searchLinear(const float[], int, float, vector<int> &);
void searchLinear(const double[], int, double, vector<int> &);
void searchLinear(const vector<int>, int, vector<int> &);
void searchLinear(const vector<float>, float, vector<int> &);
void searchLinear(const vector<double>, double, vector<int> &);

int searchBinary(const int[], int, int, bool = true);
int searchBinary(const float[], int, float, bool = true);
int searchBinary(const double[], int, double, bool = true);
int searchBinary(const vector<int>, int, bool = true);
int searchBinary(const vector<float>, float, bool = true);
int searchBinary(const vector<double>, double, bool = true); 

void sortSelection(int[], int, bool = true); // May not work..?
void sortSelection(float[], int, bool = true);
void sortSelection(vector<int>, bool = true); // ERROR: Does not sort.



/**********************************
* Gets an integer value fom the user.
************************************/
void get(int& input, string desc) {
	cout << desc;	
	while (!(cin >> input) || cin.fail()) {
		cout << "ERROR: Please enter an integer.\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}


/**********************************************************
* Gets an integer value from the user between 'min' and 'max'
*
* NOTE: Description is required, unlike the simpler version.
**********************************************************/
void get(int& input, int min, int max, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail() || input < min || input > max) {
		cout << "ERROR: Please enter an integer between " << min << " and " << max << ".\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}


/***********************************************************
* Gets a floating-point value from the user.
************************************************************/
void get(float& input, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail()) {
		cout << "ERROR: Please enter a floating-point number.\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}


/******************************************************************
* Gets a floating point value from the user between 'min' and 'max'
*******************************************************************/

void get(float& input, float min, float max, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail() || input < min || input > max) {
		cout << "ERROR: Please enter a floating-point number between " << min << " and " << max << ".\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}



/***********************************************************
* Gets a double value from the user.
************************************************************/
void get(double& input, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail()) {
		cout << "ERROR: Please enter a double.\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}




/******************************************************************
* Gets a double value from the user between 'min' and 'max'
*******************************************************************/

void get(double& input, double min, double max, string desc) {
	cout << desc;
	while (!(cin >> input) || cin.fail() || input < min || input > max) {
		cout << "ERROR: Please enter a double between " << min << " and " << max << ".\n";
		cin.clear();
		cin.sync();
		cin.ignore(100, '\n');
		cout << desc;
	}
}




/*********************************
* Gets a file name from the user.
********************************/
string getFile() {
	string directory;
	string fileName;

	cout << "Please enter directory:";
	getline(cin, directory);
	cout << "Please enter file name:";
	getline(cin, fileName);
	
	return (directory + '\\' + fileName + ".txt");
}



/**************************************
* Gets a random number between min and max.
************************************/

int getRandom(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(min, max);
	return distr(gen);
}




/*************************************
* Checks to see if a character is a vowel.
**************************************/

bool isVowel(char character) {
	if (tolower(character) == 'a' || tolower(character) == 'e' || tolower(character) == 'i' || tolower(character) == 'o' || tolower(character) == 'u' || tolower(character) == 'y')
		return true;
	else
		return false;

}





/*****************************
* Exits the progam .
******************************/
void leave() {
	cout << "\nPress any key to continue...\n";
	cin.get();
	exit(0);
}




/*****************************
* All forms of searchLinear:
* look for an instance of value in the program.
* Inefficient, unless values aren't unique/sorted.
****************************/

void searchLinear(const int list[], int size, int value, vector<int> &elementNums) {
	int index = 0;
	while (index < size) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const float list[], int size, float value, vector<int> &elementNums) {
	int index = 0;
	while (index < size) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const double list[], int size, double value, vector<int> &elementNums) {
	int index = 0;
	while (index < size) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const vector<int> list, int value, vector<int> &elementNums) {
	int index = 0;
	while (index < list.size()) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const vector<float> list, float value, vector<int> &elementNums) {
	int index = 0;
	while (index < list.size()) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}

void searchLinear(const vector<double> list, double value, vector<int> &elementNums) {
	int index = 0;
	while (index < list.size()) {
		if (list[index] == value) {
			elementNums.push_back(index);
		}
		index++;
	}
}



/****************************
* All forms of searchBinary:
* Look for an instance of value in the program.
* Efficient, but only usable on unique, sorted arrays.
****************************/

int searchBinary(const int list[], int size, int value, bool isAscending) {
	int start = 0;
	int end = size - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const float list[], int size, float value, bool isAscending) {
	int start = 0;
	int end = size - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const double list[], int size, double value, bool isAscending) {
	int start = 0;
	int end = size - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const vector<int> list, int value, bool isAscending) {
	int start = 0;
	int end = list.size() - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const vector<float> list, float value, bool isAscending) {
	int start = 0;
	int end = list.size() - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}

int searchBinary(const vector<double> list, double value, bool isAscending) {
	int start = 0;
	int end = list.size() - 1;
	int mid;
	int position = -1;
	bool found = false;
	if (isAscending) {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] > value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	else {
		while (start <= end && !found) {
			mid = (start + end) / 2;
			if (list[mid] == value) {
				position = mid;
				found = true;
			}
			else if (list[mid] < value) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
	}
	return position;
}


/*******************************
* All forms of sortSelection:
* Sort the given array/vector in ascending/descending order.
******************************/

void sortSelection(int list[], int size, bool isAscending) {
	if (isAscending) {
		int startScan;
		int minIndex;
		float minValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			minIndex = startScan;
			minValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] < minValue) {
					minIndex = i;
					minValue = list[i];
				}
			}
			list[minIndex] = list[startScan];
			list[startScan] = minValue;
		}
	}
	else {
		int startScan;
		int maxIndex;
		float maxValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			maxIndex = startScan;
			maxValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] > maxValue) {
					maxIndex = i;
					maxValue = list[i];
				}
			}
			list[maxIndex] = list[startScan];
			list[startScan] = maxValue;
		}
	}
}

void sortSelection(float list[], int size, bool isAscending) {
	if (isAscending) {
		int startScan;
		int minIndex;
		float minValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			minIndex = startScan;
			minValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] < minValue) {
					minIndex = i;
					minValue = list[i];
				}
			}
			list[minIndex] = list[startScan];
			list[startScan] = minValue;
		}
	}
	else {
		int startScan;
		int maxIndex;
		float maxValue;
		for (startScan = 0; startScan < size - 1; startScan++) {
			maxIndex = startScan;
			maxValue = list[startScan];
			for (int i = startScan + 1; i < size; i++) {
				if (list[i] > maxValue) {
					maxIndex = i;
					maxValue = list[i];
				}
			}
			list[maxIndex] = list[startScan];
			list[startScan] = maxValue;
		}
	}
}

void sortSelection(vector<int> list, bool isAscending) {
	if (isAscending) {
		int startScan;
		int minIndex;
		float minValue;
		for (startScan = 0; startScan < list.size() - 1; startScan++) {
			minIndex = startScan;
			minValue = list[startScan];
			for (int i = startScan + 1; i < list.size(); i++) {
				if (list[i] < minValue) {
					minIndex = i;
					minValue = list[i];
				}
			}
			list[minIndex] = list[startScan];
			list[startScan] = minValue;
		}
	}
	else {
		int startScan;
		int maxIndex;
		float maxValue;
		for (startScan = 0; startScan < list.size() - 1; startScan++) {
			maxIndex = startScan;
			maxValue = list[startScan];
			for (int i = startScan + 1; i < list.size(); i++) {
				if (list[i] > maxValue) {
					maxIndex = i;
					maxValue = list[i];
				}
			}
			list[maxIndex] = list[startScan];
			list[startScan] = maxValue;
		}
	}
}


