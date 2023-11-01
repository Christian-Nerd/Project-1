/*
//  
// Project Name P1
// 
// Project Purpose: Process indivual federal taxes, users will be indentified through a social security number. The program will get income and ssn then return federal income taxes. This program will run until user wishes to quit.
// 
// Author: Trey Davis
// 
// Date Created: 10/29/2023
// 
// Date Last Modified: 10/31/23 
// 
// 
*/
#include<stdio.h> // Streller you said always include this...
#include<iostream> // For input and output operations
#include<iomanip> // For flag setprecision()
/* Lines 19 and 20 define checking user choice for yes and no for all cases */
#define CHECKIFYES Choice == "y" || Choice == "Y" || Choice == "yes" || Choice == "Yes" || Choice == "YEs" || Choice == "YES" || Choice == "yES" || Choice == "yEs" || Choice == "yeS" || Choice == "YeS"
#define CHECKIFNO Choice == "n" || Choice == "N" || Choice == "no" || Choice == "No" || Choice == "nO" || Choice == "NO" 

using namespace std;
// This gets the social security of the user and returns it.
string GetSocialSecurityNumber(); 
// This function returns the income.
int GetIncome();  
// This computes the federal income tax of the user
double EvaluateFederalIncomeTax(int Income /* IN: This value stores income obviously */);
// This displays a message of this format "Hello user [ssn] here is your federal income tax [tax]."
void ShowFederalIncomeTax(string SocialSecurityNumber, // IN: Stores social security number obviously. 
				         double Tax); // IN: Stores taxes obviously.
bool CheckUserChoice(); // This checks if the user wants to continue.

int main() 
{
	cout << fixed << setprecision(2) << showpoint;
	bool Still = true; // This stores whether the user wants to continue or not.
	while (Still) // Keeps going until user chooses to exit 
	{
		string SocialSecurityNumber = GetSocialSecurityNumber(); // This variable stores ssn.
		int Income = GetIncome(); // This variable stores income
		double Tax = EvaluateFederalIncomeTax(Income); // This stores the tax
		ShowFederalIncomeTax(SocialSecurityNumber, Tax);
		Still = CheckUserChoice(); // Check if user wants to continue
	} // Keeps going until user chooses to exit 
	return 0;
}

//************************************************
//  Function Name: GetIncome()
//  Purpose: It gets the user's income and returns income
//  Parameters:  You expected parameters?
//  Return Value: The income
//  Non-Local Variables Used: 0
//  Functions Called: iostream.clear(), iostream.ignore()
//
//
//
//************************************************
//
int GetIncome() 
{
	int Income = 0; // Stores income
	while (true)
	{
		cout << "Please enter income: " << endl << endl;
		cin >> Income;
		if (!cin) // Checks for input failure
		{
			cerr << "Invalid input please enter integer income " << endl << endl;
		    /* Lines 55 and 56 clear the buffer of input failure, and the characters that cause the failure. */
			cin.clear();
			cin.ignore(1e7, '\n'); 
			Income = 0;
			continue;
		}
		else
		{
			cin.ignore(1e7, '\n'); // Clear buffer for next input and output operations
			break;
		}
	}

	return Income;
}



//************************************************
// Function Name: GetSocialSecurityNumber
// Purpose: The function gets the user's ssn and returns it.
// Parameters: 0.0 recursive
// Return Values: The obvious the string ssn.
// Non-local Variables called: 0.0 recursive)
// Functions Called: string.size(), string.at(), iostream.ignore() 
//************************************************
string GetSocialSecurityNumber() 
{
	string ssn; 
	while (true) // This loop keeps going until a valid ssn is inputed
	{
		cout << "Please input Social Security Number: ";
		bool validSsn = true; // This stores is Social Security Number is valid
		cin >> ssn;
		for (int i = 0; i < ssn.size(); i++) // Checks if social security number is only composed of digits 0-9 and is only 9 digits long
		{
			char index = ssn.at(i); // Stores current character in string
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
			cerr << "Invalid input please input an integer Social Security Number 9 characters long in the form xxxxxxxxx." << endl << endl;
			cin.ignore(1000000, '\n');
		}
		else
			break;
	} // This loop keeps going until a valid ssn is inputed
	return ssn;
}


//************************************************
// Function Name: CheckUserChoice
// Purpose: Return whether the user wants to continue or not. 
// Parameters: None obviously.
// Return Value: If the user wants to continue or not
// Functions Called: none
// 
//************************************************
bool CheckUserChoice() 
{
	while (true) // This while loop checks for valid choices, and keeps running until a valid choice is chosen.
	{
		cout << "\n\nPlease input if you want to still continue y/n" << endl << endl;
		string Choice; // This stores user choice
		cin >> Choice;
		if (CHECKIFYES)
		{
			return true;
		}
		else if (CHECKIFNO)
		{
			break;
		}
		else 
		{
			cerr << "Invalid input please input either y or n";
			continue;
		}
	} // This while loop checks for valid choices, and keeps running until a valid choice is chosen.

	return false; // When the loop is broken out of it returns false goes back to main ending the program.
}



//************************************************
// Function Name: EvaluateFederalIncomeTax
// Purpose: Computes the federal income tax of user than returns it
//   Input: int Income
// Return Value: Double tax
// Functions Called: none
//************************************************
double EvaluateFederalIncomeTax(int Income) 
{
	double Tax = 0; // Stores taxes
	if (Income > 0 && Income < 24'650)
	{
		Tax += (Income * .15);
	}
	else if (Income >= 24'650 && Income < 59'750)
	{
		Tax += 3'697.5 + (Income * .28);
	}

	else if (Income >= 59'750 && Income < 124'650)
	{
		Tax += 13'524.5 + ((Income -= 59'750) * .31);
	}

	else if (Income >= 124'650 && Income < 271'050)
	{
		Tax += 33'644.5 + ((Income -= 124'650) * .36);
	}

	else if (Income >= 271'050) 
	{
		Tax += 86'348.5 + ((Income -= 271'050) * .396);
	}

	return Tax;
}



//************************************************
// Function Name: ShowFederalIncomeTax 
// Purpose: Outputs a message in this formal "Hello user [ssn] here is your federal income tax [tax]" 
// Parameters
//     Input: string SocialSecurityNumber, double Tax
// Return Value: void tax	
// Functions Called: 0
//************************************************
void ShowFederalIncomeTax(string SocialSecurityNumber, double Tax) 
{
	cout << "Hello " << SocialSecurityNumber << " here is your federal income tax  " << Tax; // Outputs user federal income tax.
}
