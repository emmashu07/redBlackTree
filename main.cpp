#include <iostream>
#include <cstring> 
#include <cmath>
#include <fstream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	int redBlack;
	Node* parent;
};

int convertToInt(char* num);
int inputToInt(char* input, int* array);
int fileToInt(char* fileName, int* array);
void add(Node* &currRoot, int num);
bool search(Node* currRoot, int num);
void print(Node* currRoot, int tabNum);
void build(int* array, int size, Node* &root);
bool remove(Node* &currRoot, int num); 
void removeNode(Node* &currRoot);
void display(Node* currRoot);
Node*& largest(Node* root);

int main() {
	char input[200];
	char fileName[50];
	char forC[10];
	char input2[20];
	int* array = new int[100];
	int size;
	Node* root = NULL;
	bool running = true;

	cout << "Please enter whether you would like to input through file or console: ";
	cin.get(forC, 10);
	cin.ignore(10, '\n');

	if (strcmp(forC, "FILE") == 0) {
		cout << "Please enter a file name: ";
		cin.get(fileName, 50);
		cin.ignore(50, '\n');
		size = fileToInt(fileName, array);
	}
	else if (strcmp(forC, "CONSOLE") == 0) {
		cout << "Please enter a series of numbers separated by a space: ";
		cin.get(input, 200);
		cin.ignore(200, '\n');
		size = inputToInt(input, array);	
	}
	else {
		cout << "Please enter FILE or CONSOLE." << endl;
	}	

	while (running) {
	}
	

	return 0;
}

int convertToInt(char* num) { // Using a char array, make an int.
	int fin = 0;
	int power = strlen(num) - 1;
	for (int i = 0; i < strlen(num); i++) {
		int digit = num[i] - '0';
		fin += digit * pow(10, power-i);
	}
	return fin;
}

int inputToInt(char* input, int* array) { // Take the input and convert it into an int array.
	int arrayIndex = 0;
	for (int i = 0; i < strlen(input); i++) {
		if (!isspace(input[i]) && isdigit(input[i])) {
			int index = 0;
			char* num = new char[3];
			num[index] = input[i];
			index++;
			while (!isspace(input[i+1])) {
				i++;
				num[index] = input[i];
			        index++;
			}
			num[index] = '\0';
			array[arrayIndex] = convertToInt(num);
		        arrayIndex++;
		}
	}
	return arrayIndex;
}

int fileToInt(char* fileName, int* array) { // File input to int array, utilizes input to int.
	char input[200];
	int size;
	ifstream file(fileName);
	if (file.is_open()) {
		file.getline(input, 200);
		file.close();
		size = inputToInt(input, array);	
		return size;
	}
	else {
		cout << "Unable to open file." << endl;
		return -1;
	}
}	


