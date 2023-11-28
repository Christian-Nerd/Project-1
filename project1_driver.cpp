/*************************************************
//  
// Project Name: P1
// 
// Project Purpose: Process indivual federal taxes, users will be indentified through a social security number. The program will get income and Social Security Number then return federal income taxes. This program will run until user wishes to quit.
// 
// Author: Trey Davis
// 
// Date Created: 10/29/2023
// 
// Date Last Modified: 1/2/23 
// 
// 
*************************************************/
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
// This displays a message of this format "Hello user [Social Security Number] here is your federal income tax [tax]."
void ShowFederalIncomeTax(string SocialSecurityNumber, // IN: Stores social security number obviously. 
				         double Tax); // IN: Stores taxes obviously.
bool CheckUserChoice(); // This checks if the user wants to continue.

int main() 
{
	cout << fixed << setprecision(2) << showpoint; // Adds manipulators to cout to show fixed decimals, with two significant figures, and showing trailing zeroes.
	bool Still = true; // This stores whether the user wants to continue or not.
	while (Still) // Keeps going until user chooses to exit 
	{
		string SocialSecurityNumber = GetSocialSecurityNumber(); // This variable stores Social Security Number.
		int Income = GetIncome(); // This variable stores income
		double Tax = EvaluateFederalIncomeTax(Income); // This stores the tax
		ShowFederalIncomeTax(SocialSecurityNumber, Tax); // This shows federal income tax
		Still = CheckUserChoice(); // Check if user wants to continue
	} // Keeps going until user chooses to exit 
	return 0; // This means main returns with no errors.
}

//************************************************
//  Function Name: GetIncome()
//  Purpose: It gets the user's income and returns income
//  Parameters:  You expected parameters?
//  Return Value: The income
//  Non-Local Variables Used: 0
//  Functions Called: iostream.clear(), iostream.ignore()
//************************************************
int GetIncome() 
{
	int Income = 0; // Stores income
	// Checks for invalid input and repeats program if invalid until it's valid 
	while (true)
	{
		cout << endl << "Please enter income: " << endl << endl; // Prompt Line for inputting income
		cin >> Income; // Inputs User input into income
		// Checks for input failure
		if (!cin) 
		{
			cerr << endl << "Invalid input please enter integer income " << endl << endl; // Gives an error for invalid integer income.
		    /* Lines 55 and 56 clear the buffer of input failure, and the characters that cause the failure. */
			cin.clear(); // Clear the buffer of input failure.
			cin.ignore(1e7, '\n'); // Clears the characters that cause the failure.
			Income = 0; // Resets income
			continue; // Skips to beginning of looprestarting the prompt with minimal memory losses.
		}
	    // If input succeeded 
		else
		{
			cin.ignore(1e7, '\n'); // Clear buffer for next input and output operations
			break; // Breaks out of loop, as input is valid
		}
	}

	return Income; // Returns the income
}



//************************************************
// Function Name: GetSocialSecurityNumber
// Purpose: The function gets the user's Social Security Number and returns it.
// Parameters: 0.0 recursive
// Return Values: The obvious the string Social Security Number.
// Non-local Variables called: 0.0 recursive)
// Functions Called: string.size(), string.at(), iostream.ignore() 
//************************************************
string GetSocialSecurityNumber() 
{
	string SocialSecurityNumber; // Social Security Number
	// This loop keeps going until a valid Social Security Number is inputed
	while (true) 
	{
		bool validSsn = true; // This stores is Social Security Number is valid
		int noOfZeroes = 0; // Checks number of zeroes
		cout << "Please input Social Security Number: "; // Promnt Line for social security number
		cin >> SocialSecurityNumber; // Puts input into social security number
		// Checks if social security number is only composed of digits 0-9, is only 9 digits long, and is not all zero
		for (int i = 0; i < SocialSecurityNumber.size(); i++)  
		{
			char index = SocialSecurityNumber.at(i); // Stores current character in string
			// Checks if digit is valid and if there's any all zero Social Security Number
			if (index <= '9' && index >= '0') 
			{
				// This both increments noOfZeroes and if the Social Security Number
				if (index == '0') 
				{
					noOfZeroes++; // Increments zeroes by one.
					// Checking if the Social Security Number is all zeroes.
					if (noOfZeroes == 9)
					{
						validSsn = false; // Sets validSsn false 
						break; // breaks out of loop
					}
				}
				validSsn = true; // Set valid ssn true for another iteration
				continue; // Start loop again
			}
			// If invalid digit...
			else 
			{
				validSsn = false; // Sets validSsn
				break; // Breaks out of while loop
			}
		} // Checks if digit is valid and if there's any all zero Social Security Number
		// Checks if Social Security Number is valid
		if (!cin || SocialSecurityNumber.size() != 9 || validSsn == false)
		{
			cerr << "Invalid input please input an integer Social Security Number 9 characters long, in the form xxxxxxxxx"; // Explains the input requirements of the function after the user fails.
			cerr <<	",and at least one non-zero character." << endl << endl; // Next line version or previous line
			cin.ignore(1000000, '\n'); // Clear the buffer for receiving income.
		}
		// if Social Security Number is valid...
		else
			break; // get out of the while loop
	} // This loop keeps going until a valid Social Security Number is inputed
	return SocialSecurityNumber; // Return Social Security Number 
}


//************************************************
// Function Name: CheckUserChoice
// Purpose: Return whether the user wants to continue or not. 
// Parameters: None obviously.
// Return Value: If the user wants to continue or not
// Functions Called: none
//************************************************
bool CheckUserChoice() 
{
	// This while loop checks for valid choices, and keeps running until a valid choice is chosen.
	while (true) 
	{
		cout << "\n\nPlease input if you want to still continue y/n" << endl << endl; // Promnt line to indicate if the user wants to continue.
		string Choice; // This stores user choice.
		cin >> Choice; // Assigns user input into choice.
		// Checks if the input is yes(case-insensitive)
		if (CHECKIFYES)
			return true; // Return that the user wants to continue.
		// Checks if the input is no(case-insensitive)
		else if (CHECKIFNO)
			break; // End while loop
		// If invalid input...
		else 
		{
			cerr << "Invalid input please input either y or n"; // error line stating what's wrong  
			continue; // Run the loop again
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
	// Makes income positive if negative.
	if (Income < 0) 
		Income *= -1; // Makes input positive
	// Checks for if it falls for the first part of the tax forumn
	if (Income >= 0)
	{
		Tax += (Income * .15); // Uses the first part of the tax forumn 0 + 15% of income to tax.
	}
	// Checks for if it falls for the second part of the tax forumn
	if (Income >= 24'650)
	{
		Tax += 3'697.5 + ((Income - 24'650) * .28); // Uses the second part of the tax forumn adding 3.697.5 + 28% of the amount over 24,650.
	}
	// Checks for if it falls for the third part of the tax forumn
	 if (Income >= 59'750)
	{
		Tax += 13'525.5 + ((Income - 59'750) * .31); // Uses the third part of the tax forumn adding 13,524 + 31% of e Income - 59,750 to tax.
	}
	// Checks for if it falls for the fourth part of the tax forumn
	 if (Income >= 124'650)
	{
		Tax += 33'644.5 + ((Income - 124'650) * .36); // Uses the third part of the tax forumn adding 33,644.5 + 36%  of  Income - 124,650 to tax.
	}
	// Checks for if it falls for the final part of the tax forumn
	if (Income >= 271'050) 
	{
		Tax += 86'348.5 + ((Income - 271'050) * .396); // Uses the fourth part of the tax forumn adding 86,348.5 + 39.6%  of  Income - 271,050 to tax.
	}

	return Tax; // Returns tax
}



//************************************************
// Function Name: ShowFederalIncomeTax 
// Purpose: Outputs a message in this formal "Hello user [Social Security Number] here is your federal income tax [tax]" 
// Parameters
//     Input: string Social Security Number, double Tax
// Return Value: void tax	
// Functions Called: 0
//************************************************
void ShowFederalIncomeTax(string SocialSecurityNumber, double Tax) 
{
	cout << endl << "Hello " << SocialSecurityNumber << " here is your federal income tax  " << Tax << "."; // Outputs user federal income tax.
}
