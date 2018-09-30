/*
Author:			Annie Wu
Assignment:		Homework #2

Class:		  	CS 2560.01 - C++ Programming
Date:			29 September 2018

Purpose:	  	This program allows the user to enter the sales item's name and cost into parallel vectors.
				It gives the user the options to add a sale, edit a sale, view all sales, and remove a sale. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void addSale(vector<string> &itemNames, vector<double> &itemCosts) {
	string name;
	double cost;
	
	bool loop = true;
	while (loop) {
		cout << "\nEnter an item or say STOP: ";
		//use one word item names
		cin >> name;

		if (name == "STOP" or name == "stop" or name == "Stop")
			loop = false;
		else {
			cout << "Enter the cost for " << name << ": ";
			cin >> cost;
			itemNames.push_back(name);
			itemCosts.push_back(cost);
		}
	}
}

void viewSales(vector<string> &itemNames, vector<double> &itemCosts) {
	cout << "\n   ITEM              $$ COST";
	cout << "\n-----------------------------\n";
	
	for (int i = 0; i < itemNames.size(); i++) {
		cout << i+1 << "  " << left << setw(15) << itemNames.at(i);
		printf("%10.2f\n", itemCosts.at(i));
	}
}

void editSale(vector<string> &itemNames, vector<double> &itemCosts) {
	int index;
	cout << "\nEnter the number for the sale you want to edit: ";
	cin >> index;

	//number on the print out list is index +1, so need to -1 to get actual index in the vector
	index = index - 1;
	
	if (index > itemNames.size() - 1) {
		cout << "That sales item does not exist!" << endl;
	}
	else {
		cout << "Enter the new cost for " << itemNames.at(index) << ": ";
		cin >> itemCosts[index];
	}
}

void removeSale(vector<string> &itemNames, vector<double> &itemCosts) {
	int index;
	cout << "\nEnter the number for the sale you want to remove: ";
	cin >> index;

	//number on the print out list is index +1, so need to -1 to get actual index in the vector
	index = index - 1;

	if (index > itemNames.size() -1) {
		cout << "That sales item does not exist!" << endl;
	}
	else if (index == 0) {
		//begin() is the first index of the vector
		itemNames.erase(itemNames.begin());
		itemCosts.erase(itemCosts.begin());
	}
	else {
		itemNames.erase(itemNames.begin() + index);
		itemCosts.erase(itemCosts.begin() + index);
	}
}

int main() {
	//each string indicates the name of the item that was sold
	vector<string> itemNames;
	//each double indicates how much the corresponding item costs
	vector<double> itemCosts;

	string menu = "\n 1. Add a sale"
				  "\n 2. View sales"
				  "\n 3. Edit a sale"
				  "\n 4. Remove a sale"
				  "\n 0. Exit the program"
				  "\n Choose a task: ";

	bool exit = false;
	int choice;

	while (!exit) {
		//print menu
		cout << menu;
		//user inputs a choice
		cin >> choice;

		//switch case for tasks
		switch (choice) {
		case 1: //add
			addSale(itemNames, itemCosts);
			break;
		case 2: //view
			viewSales(itemNames, itemCosts);
			break;
		case 3: //edit
			editSale(itemNames, itemCosts);
			break;
		case 4: //remove
			removeSale(itemNames, itemCosts);
			break;
		case 0: //exit
			cout << "\nExiting the program.\n";
			exit = true;
			break;
		default:
			cout << "\nInvalid input!\n";
			break;
		}
	}

	system("pause");
	return 0;
}

