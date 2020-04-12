#include <iostream>
#include <cstring> 
#include <cmath>
#include <fstream>

using namespace std;

struct Node {
	int data;
	int redBlack;
	Node* left;
	Node* right;
	Node* parent;
};

int convertToInt(char* num);
int inputToInt(char* input, int* array);
int fileToInt(char* fileName, int* array);
void read(Node* root, int* array, int size);
void display(Node* currRoot);
void print(Node* currRoot, int tabNum);
Node* getParent(Node* node);
Node* getGrandparent(Node* node);
Node* getSibling(Node* node);
Node* getUncle(Node* node);
void rotateLeft(Node* node);
void rotateRight(Node* node);

const int BLACK = 0;
const int RED = 1;

int main() {
	char fileName[50];
	char input[20];
	int* array = new int[100];
	int size;
	Node* root = NULL;
	bool running = true;
	
	cout << "Please enter a file name: ";
	cin.get(fileName, 50);
	cin.ignore(50, '\n');
	size = fileToInt(fileName, array);	

	read(root, array, size);

	while (running) {
		cout << "Please enter whether you would like to search, remove, insert, print, or quit: ";
		cin.get(input, 20);
		cin.ignore(20, '\n');
		
		if (strcmp(input, "INSERT") == 0) {
			int num;
			cout << "Please enter a number: ";
			cin >> num;
			cin.ignore(20, '\n');
			//add(root, num);
		}
		else if (strcmp(input, "SEARCH") == 0) {
			/*bool in;
			int num;
			cout << "Please enter a number: ";
			cin >> num;
			cout << endl;
			cin.ignore(20, '\n');
			in = search(root, num);
			if (in) {
				cout << "The number is in the tree." << endl;
			}
			else {
				cout << "The number is not in the tree." << endl;
			}*/	
		}
		else if (strcmp(input, "REMOVE") == 0) {
			/*bool in;
			int num;
			cout << "Please enter a number: ";
			cin >> num;
			cout << endl;
			cin.ignore(20, '\n');
			in = remove(root, num);
			if (in) {
				cout << "Deleted." << endl;
			}
			else {
				cout << "The number is not in the tree." << endl;
			}*/
		}	
		else if (strcmp(input, "PRINT") == 0) {
			print(root, 0);
			cout << "Inorder traversal: ";
			display(root);
			cout << endl;
		}
		else if (strcmp(input, "QUIT") == 0) {
			running = false;
		}	
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

void print(Node* currRoot, int tabNum) { // Print the tree.
	if (currRoot -> right) {
		print(currRoot -> right, tabNum+1);
	}
	int i = 0;
	while (i < tabNum) {
		cout << '\t';
		i++;
	}
	cout << currRoot -> data << endl;
	if (currRoot -> left) {
		print(currRoot -> left, tabNum+1);
	}
}

void display(Node* currRoot) { // An inorder traversal of the tree.
	if (currRoot) {
		display(currRoot -> left);
		cout << currRoot -> data << ' ';
		display(currRoot -> right);
	}
}


void read(Node* root, int* array, int size) {

}



		
