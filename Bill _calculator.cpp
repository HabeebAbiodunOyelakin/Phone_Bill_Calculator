// Name: Habeeb Abiodun Oyelakin
// Matric N0:  2585877
// Question N0: 2

// Assumptions made in this assignment are as follows:
// 1. The program assumes that the user will input the following information :
//    -The total number of minutes used for the month(variable `NumberOfMin`).
//	  - The call type, where the user should enter 'N' for national calls or 'I' for international calls(variable `Call_type`).
//    - The data usage in gigabytes for the month(variable `Data_usage`).

// 2. The program assumes that the call rates and discount levels for phone calls and data usage are fixed and predefined as constants:
//     - Uk_Calls_Rate: The rate for national calls(0.12 pounds per minute).
//     - Intnl_Calls_Rate: The rate for international calls(0.30 pounds per minute).
//     - Data_rate: The rate for data usage(1.00 pound per gigabyte).
//     - DataDiscount_1, DataDiscount_2, and DataDiscount_3: Discount levels for data usage in gigabytes.

//  3. The program assumes that the user will provide valid input for the call type, i.e., 'N' for national or 'I' for international calls. 
//     If the user provides any other input, it will display an error message and exit.

// 4.  The program calculates the phone call and data bills based on the provided input and applies discounts for different levels of phone 
//     call minutes and data usage.

// 5.  The program assumes that the user's total monthly bill is the sum of the phone call bill and the data bill.




#include <iostream>
using namespace std;

int main() {

	cout << "Habeeb Network Service Provider Calculator." << endl << endl;

	cout << "UK Calls Plan @ 12pence per minute:" << endl;
	cout << "Level 1: Up to 100minutes    -    No discount" << endl;
	cout << "Level 2: 100 to 200minutes   -    3%" << endl;
	cout << "Level 3: 200 to 400minutes   -    5%" << endl;
	cout << "Level 4: Above 400minutes   -     10%" << endl << endl;

	cout << "International Calls Plan @ 30pence per minute:" << endl;
	cout << "Level 1: Up to 100minutes    -    No discount" << endl;
	cout << "Level 2: 100 to 200minutes   -    3% discount" << endl;
	cout << "Level 3: 200 to 400minutes   -    5% discount" << endl;
	cout << "Level 4: Above 400minutes    -    10% discount" << endl << endl;

	cout << "Data bills @ 1pounds per gigabye:" << endl;
	cout << "Level 1: Up to 5 gig         -    No discount" << endl;
	cout << "Level 2: 5 to 15gig          -    5% discount" << endl;
	cout << "Level 3: 15 to 25gig         -    10% discount" << endl;
	cout << "Level 4: Above 25gig         -    15% discount" << endl << endl;

	// Declaring variables
	int NumberOfMin;                             // monthly total number of minutes
	char Call_type;
	double Calls_bill = 0;
	double Data_usage;                           // data usage in gig by end of month
	double Data_bill = 0;
	double Monthly_bill = 0;				     // Total monthly bill


	//Declaring and initializing the current call rates;
	const double Uk_Calls_Rate = 0.12;           // 12pence per minute
	const double Intnl_Calls_Rate = 0.30;        // 30pence per minute
	const double Data_rate = 1.00;               // 1pounds per gig


	//Declaring and initializing the discount levels;
	const double Disc_level1 = 0.03;             // 3% refund
	const double Disc_level2 = 0.05;	         // 5% refund
	const double Disc_level3 = 0.10;             // 10% refund
	const double DataDiscount_1 = 0.05;          // 5% refund 
	const double DataDiscount_2 = 0.10;	         // 10% refund
	const double DataDiscount_3 = 0.15;          // 15% refund

	// Getting user input
	cout << "Please enter the total number of minutes used for the month: ";
	cin >> NumberOfMin;
	cout << endl;
	cout << "Please enter 'N' for national call and 'I' for international call: ";
	cin >> Call_type;
	cout << endl;
	cout << "Enter the data usage (in gig) for the month: ";
	cin >> Data_usage;
	cout << endl;


	// Calulating the bills based on the user number of mins and call type
	if (Call_type == 'N' || Call_type == 'n') {
		Calls_bill = NumberOfMin * Uk_Calls_Rate;
	}
	else if (Call_type == 'I' || Call_type == 'i') {
		Calls_bill = NumberOfMin * Intnl_Calls_Rate;
	}
	else {
		cout << "Invalid call type. Please enter 'N' or 'I'." << endl;
		return 0;
	}

	// Factoring in the phone bill discount levels 
	if (NumberOfMin < 100) {
		Calls_bill = Calls_bill;
	}
	else if (NumberOfMin <= 200) {
		Calls_bill *= (1.0 - Disc_level1);
	}
	else if (NumberOfMin <= 400) {
		Calls_bill *= (1.0 - Disc_level2);
	}
	else {
		Calls_bill *= (1.0 - Disc_level3);
	}

	//Declaring and initializing the discount levels;
	Data_bill = Data_rate * Data_usage;

	// Factoring in the data discount levels 
	if (Data_usage <= 5) {
		Data_bill = Data_rate * Data_usage;
	}
	else if (Data_usage < 15) {
		Data_bill = Data_rate * Data_usage * (1.0 - DataDiscount_1);
	}
	else if (Data_usage < 25) {
		Data_bill = Data_rate * Data_usage * (1.0 - DataDiscount_2);
	}
	else {
		Data_bill = Data_rate * Data_usage * (1.0 - DataDiscount_3);
	}

	// Display the monthly mobile phone bill to the user.
	cout << "Your monthly mobile phone bill for " << NumberOfMin << "minutes of calls is: \x9C " << Calls_bill << endl;

	// Display the monthly mobile phone bill to the user.
	cout << "Your monthly mobile data bill for " << Data_usage << "gig of data is: \x9C " << Data_bill << endl << endl;

	// Display total monthly bill to the user.
	Monthly_bill = Calls_bill + Data_bill;
	cout << "Your total monthly phone calls and data bill is: \x9C" << Monthly_bill << "." << endl;
}