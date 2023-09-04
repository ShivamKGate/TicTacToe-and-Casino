#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();
int main() {
	string playerName;
	int balance;
	int bettingAmount;
	int guess;
	int dice;
	int age;
	char choice;
	srand(time(0));
	cout << "\t\t\t WELCOME TO THE SHIVAM INDIAN CASINO! \n";
	cout << "Enter your name: ";
	getline(cin, playerName);
	cout << "Enter your age: ";
	cin >> age;
	if (age < 18) {
		cout << "I am sorry, you are too young to play this game!";
		return 0;
	}
	else {
		cout << "Great, you are eligible to play this game, but kindly play responsibly! \n";
	}
	cout << "Enter the starting balance to play the game: $";
	cin >> balance;
	do {
		system("cls");
		rules();
		cout << "Your current balance is $" << balance << "\n";
		do {
			cout << "Hello " << playerName << ", please enter the amount to bet: $";
			cin >> bettingAmount;
			if (bettingAmount > balance)
				cout << "The betting balance cannot be more than the total amount! \n" << "Please re-enter the balance\n";

		} while (bettingAmount > balance);
		do {
			cout << "Choose any number from 1 to 10 to place your bet on: ";
			cin >> guess;
			if (guess <= 0 && guess > 10)
				cout << "The number should be between 1 to 10 \n" << "Please re-enter the number: ";
		} while (guess <= 0 && guess > 10);
		dice = rand() % 10 + 1;
		if (dice == guess) {
			cout << "Today's your lucky day!! You have won $" << bettingAmount * 10;
			balance = balance + bettingAmount * 10;
		}
		else {
			cout << "Bad luck! You lost $" << bettingAmount << "\n";
			balance = balance - bettingAmount;
		}
		cout << "The winning number was: " << dice << "\n";
		cout << playerName << ", you have a remaining balance of $" << balance << "\n";
		if (balance == 0) {
			cout << "Sorry, you have no remaining money to play.";
			break;
		}
		cout << "\n\n Do you wish to play again (y/n)? ";
		cin >> choice;

		do {
			if (choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n') {

				cout << "It seems like you have entered a invalid command!!" << endl;
				cout << "Please enter your choice again" << endl;
				cin >> choice;
			}
			else
				break;

		} while (choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n');


	} while (choice == 'Y' || choice == 'y');
	cout << "\n\n\n";
	cout << "Thanks for playing the game. Your balance is $ " << balance << "\n\n";
	return 0;
	if (choice == 'N' || choice == 'n') {
		cout << "Thanks for playing the game. Your balance is $ " << balance << "\n\n";
		return 0;
	}
	else {
		cout << "Check what you have put, please either put 'y' or 'n'.";
	}
}
void rules() {
	system("cls");
	cout << "\t\t\t CASINO NUMBER GUESSING RULES! \n";
	cout << "\t 1. Choose a number between 1 to 10. \n";
	cout << "\t 2. The winner gets 10 times of the money bet. \n";
	cout << "\t 3. If it is a wrong bet, you will lose the amount you bet. \n\n";
}