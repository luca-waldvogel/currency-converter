// ***************************************************
// Projekt:		Currency Converter
// Author:		Luca Waldvogel    
// Datum:		22.10.2024  
// ***************************************************

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

void start();
double getRate();
double getNumber();
void getAmounts(double amount[], int n);
int getChoice();
void output(int choice, int n, double amount[], double rate);
string getRestart();

int main()
{
    double amount[15];
    string restart;
    
    start();
    
    do{
		double rate = getRate();
		int n = getNumber();
		getAmounts(amount, n);
		int choice = getChoice();
		output(choice, n, amount, rate);
	    restart = getRestart(); 
	}while(restart == "1");
    
	return 0;
}

void start(){
	cout << "**************************************" << endl;
	cout << "Program: Currency Converter" << endl;
	cout << "Author:  Luca Waldvogel" << endl;
	cout << "Date:    22.10.2024" << endl;
	cout << "**************************************" << endl << endl;
}

double getRate(){
	double rate;
	while (true) {
	        cout << "Type in the exchange rate (1 EUR = X.XX CHF): ";
	        cin >> rate;

	        if (cin.fail()) {
	            cin.clear();
	            cin.ignore(10000, '\n');
	            cout << endl << "***************************************************************" << endl;
	            cout << "Invalid input! Please enter a valid exchange rate (e.g., 0.95)." << endl;
	            cout << "***************************************************************" << endl << endl;
	        } else if (cin.peek() != '\n') {
	            cin.clear();
	            cin.ignore(10000, '\n');
	            cout << endl << "***************************************************************" << endl;
	            cout << "Invalid input! Please enter a valid exchange rate (e.g., 0.95)." << endl;
	            cout << "***************************************************************" << endl << endl;
	        } else {
	            break;
	        }
	    }
	    cout << endl;
	    return rate;
	}

double getNumber(){
	int n;
	
	while (true) {
	    cout << "How many amounts do you want to convert (1-15)? ";
	    cin >> n;
	
	    if (cin.fail()) { 
	        cin.clear();
	        cin.ignore(10000, '\n');
	        cout << endl << "***********************************************" << endl;
	        cout << "Invalid input! Please enter a number from 1-15." << endl;
	        cout << "***********************************************" << endl << endl;
	    } else if (cin.peek() != '\n') {
	        cin.clear();
	        cin.ignore(10000, '\n');
	        cout << endl << "***********************************************" << endl;
	        cout << "Invalid input! Please enter a number from 1-15." << endl;
	        cout << "***********************************************" << endl << endl;
	    } else if (n < 1 || n > 15) {
	    	cout << endl << "************************************" << endl;
			cout << "The number must be between 1 and 15." << endl;
			cout << "************************************" << endl << endl;
	    } else {
	        break;
	    }
	    }
	cout << endl;
	return n;
}

void getAmounts(double amount[], int n){	
	cout << "Please enter all " << n << " amounts one by one (please separate them with [Enter]):" << endl;
		for (int i = 0; i < n; i++) {
			while (true) {
				cout << "Enter amount " << i + 1 << ": ";
				cin >> amount[i];
	
				if (cin.fail()) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << endl << "*******************************************" << endl;
					cout << "Invalid input! Please enter a valid amount." << endl;
					cout << "*******************************************" << endl << endl;
				} else if (cin.peek() != '\n') {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << endl << "*******************************************" << endl;
					cout << "Invalid input! Please enter a valid amount." << endl;
					cout << "*******************************************" << endl << endl;
				} else {
					break;
				}
			}
		}
}

int getChoice(){
	int choice;
	
	cout << endl << "Do you want to convert the amount from EUR to CHF or from CHF to EUR?";
	do{
		cout << endl << "1. from EUR to CHF" << endl;
		cout << "2. from CHF to EUR" << endl;
		cin >> choice;
		cout << endl;
			    
		if(choice != 1 && choice != 2){
			cout << "Invalid input! Please type 1 or 2 and confirm with [Enter]";
		}  
	}while(choice != 1 && choice != 2);
	
	return choice;
}

void output(int choice, int n, double amount[], double rate){
	switch (choice)
		{
		case 1:
		    for (int i=0;i<n;i++)
		       cout << "EUR " << fixed << setprecision(2) << amount[i] << " -> " << "CHF " << fixed << setprecision(2) << (amount[i] * rate) << endl;
		    break;
		
		case 2:
		    for (int i=0;i<n;i++)
				cout << "CHF " << fixed << setprecision(2) << amount[i] << " -> " << "EUR " << fixed << setprecision(2) << (amount[i] / rate) << endl;
		    break;
		    }
}

string getRestart(){
	string restart;
	cout << endl << endl << "*********************************************************" << endl;
	cout << "Click [Enter] to end programm or 1 (+ [Enter]) to restart" << endl;
	cout << "*********************************************************" << endl;
			
	cin.ignore();
	getline(cin, restart);	
	cout << endl << endl;
	
	return restart;
}
