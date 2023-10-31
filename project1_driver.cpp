/*
**  
** Project Name P1
** 
** Project Purpose: Process indivual federal taxes, users will be indentified through a social security number. The program will get income and ssn then return federal income taxes. This program will run until user wishes to quit.
** 
** Author: Trey Davis
** 
** Date Created: 10/29/2023
** 
** Date Last Modified: 10/31/23 
** 
** 
*/
#include<stdio.h>
#include<iostream>
#include<iomanip>
#define checkIfYes choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YEs" || choice == "YES" || choice == "yES" || choice == "yEs" || choice == "yeS" || choice == "YeS"
#define checkIfNo choice == "n" || choice == "N" || choice == "no" || choice == "No" || choice == "nO" || choice == "NO" 

using namespace std;
string getSocialSecurityNumber();
int getIncome();
double evaluateFederalIncomeTax(int income);
void showFederalIncomeTax(string socialSecurityNumber, double tax);
bool checkUserChoice();

int main() 
{
	cout << fixed << setprecision(2) << showpoint;
	bool still = true;
	while (still)
	{
		string socialSecurityNumber = getSocialSecurityNumber();
		int income = getIncome();
		double tax = evaluateFederalIncomeTax(income);
		showFederalIncomeTax(socialSecurityNumber, tax);
		still = checkUserChoice();
	}
	return 0;
}


int getIncome() 
{
	int income = 0;
	while (true)
	{
		cout << "Please enter income: " << endl << endl;
		cin >> income;
		if (!cin)
		{
			cerr << "Invalid input please enter integer income " << endl << endl;
			cin.clear();
			cin.ignore(1e7, '\n');
			income = 0;
			continue;
		}
		else
		{
			cin.ignore(1e7, '\n'); // Clear buffer for next input and output operations
			break;
		}
	}

	return income;
}

string getSocialSecurityNumber() 
{
	string ssn; 
	while (true)
	{
		cout << "Please input Social Security Number: ";
		bool validSsn = true;
		cin >> ssn;
		for (int i = 0; i < ssn.size(); i++) 
		{
			char index = ssn.at(i);
			if (index <= '9' && index >= '0')
			{
				validSsn = true;
				break;
			}
			else 
			{
				validSsn = false;
				break;
			}
		}
		if (!cin || ssn.size() != 9 || validSsn == false)
		{
			cerr << "Invalid input please input an integer Social Security Number 8 characters long in the form xxxxxxxxx." << endl << endl;
			cin.ignore(1000000, '\n');
		}
		else
			break;
	}
	return ssn;
}

bool checkUserChoice() 
{
	while (true)
	{
		cout << "\n\nPlease input if you want to still continue y/n" << endl << endl;
		string choice;
		cin >> choice;
		if (checkIfYes)
		{
			return true;
		}
		else if (checkIfNo)
		{
			break;
		}
		else 
		{
			cerr << "Invalid input please input either y or n";
			continue;
		}
	}
	return false;
}

string strToLower()
{
	return "";
}


double evaluateFederalIncomeTax(int income) 
{
	double tax = 0;
	if (income > 0 && income < 24'650)
	{
		tax += (income * .15);
	}
	else if (income > 24'650 && income < 59'750)
	{
		tax += 3'697.5 + (income * .28);
	}

	else if (income > 59'750 && income < 124'650)
	{
		tax += 13'524.5 + ((income -= 59'750) * .31);
	}

	else if (income > 124'650 && income < 271'050)
	{
		tax += 33'644.5 + ((income -= 124'650) * .36);
	}

	else if (income > 271'050) 
	{
		tax += 86'348.5 + ((income -= 271'050) * .396);
	}

	return tax;
}



void showFederalIncomeTax(string socialSecurityNumber, double tax) 
{
	cout << "Hello " << socialSecurityNumber << " here is your federal income tax  " << tax;
}
