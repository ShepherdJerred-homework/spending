// Retirement Fund Duration by Jerred Shepherd

#include <iostream>
#include <iomanip>

using namespace std;

void main() {

	// Initialize variables
	double amount, withdrawl, interest;
	int years, months;
	bool infinite;

	// Set cout otions
	cout.precision(2);
	cout.setf(ios::fixed | ios::showpoint);



	// Ask for variable values
	cout << setw(14) << "   Initial amount? ";
	cin >> amount;

	cout << setw(14) << "Monthly withdrawl? ";
	cin >> withdrawl;

	cout << setw(14) << "    Interest rate? ";
	cin >> interest;



	// Calculate the monthly interest rate
	// For example if the year rate were 12% (.12)
	// The monthly rate will be 1% (.01) per month
	interest = interest / 12 / 100;

	// Set the years/months to 0
	years = 0;
	months = 0;

	// Check if the fund
	// will last forever
	infinite = (((amount + (amount * interest)) - withdrawl) >= amount);


	// Loop while the amount left is greater
	// than or equal to the monthly withdrawl
	if (!(infinite)) {

		while (amount >= withdrawl) {

			// Calculate interest
			amount = amount + (amount * interest);

			// Subtract the withdrawl amount
			amount = amount - withdrawl;

			// Increment months
			months++;

			// Increment years if we're at 12 months
			if (months == 12) {

				months = 0;
				years++;

			}

		}
	}



	if (infinite) {

		// Output that interest will sustain the
		// account forever at this rate
		cout << endl << "The fund will last indefinitely" << endl << endl;

	}
	else {

		// Output how long the fund will last,
		// and how much will be left over
		cout << endl << "The fund will last for " << years << " years and " << months << " months." << endl;
		cout << "The amount of money left will be " << amount << ", which is less than " << withdrawl << "." << endl << endl;

	}



	system("pause");

}