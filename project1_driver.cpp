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
** Date Last Modified: 10/29/23 
** 
** 
*/
#include<stdio.h>
#include<iostream>

using namespace std;
string getSocialSecurityNumber();
int getIncome();
double evaluateFederalIncomeTax(int income);
void showFederalIncomeTax(string socialSecurityNumber, double tax);
bool checkUserChoice();

int main() 
{
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


string getSocialSecurityNumber() 
{
	while (true)
	{
		bool validSsn = true;
		string ssn;
		cin >> ssn;
		for (int i = 0; i < ssn.size(); i++) 
		{
			if (!(ssn.at(i) <= '0' && ssn.at(i) >= '9'))
			{
				validSsn = false;
				break;
			}
		}
		if (!cin || ssn.size() != 8 || validSsn == false) 
		{
			cerr << "Invalid input please input an integer Social Security Number 8 characters long in the form xxxxxxxxx." << endl << endl;
			cin.ignore(1000000, '\n');
		}
	}
}

bool checkUserChoice() 
{
	while (true)
	{
		cout << "Please input if you want to still continue y/n" << endl << endl;
		string choice;
		cin >> choice;
		if (choice == "y" || choice == "yes" || choice == "Y")
		{
			return true;
		}
		else if (choice == "n" || choice == "no" || choice == "N")
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


double evaluateFederalIncomeTax(string socialSecurityNumber, int income) 
{
	double tax = 0;
	if (income > 0 && income < 24'650)
		tax += (income * .15);
	else if (income > 24'650 && income < 59'750)
	{
		tax += 3'697.5 + ((income -= 24'650) * .28);
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



void showFederalIncomeTax(string socialSecurityNumber, int income) 
{
	cout << "Hello " << socialSecurityNumber << "here is your federal income tax ";

}
