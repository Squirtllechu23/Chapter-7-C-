#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 15;
const int SEATS_PER_ROW = 30;

// Globals
double seatPrices[ROWS];
char seats[ROWS][SEATS_PER_ROW];
double totalSales = 0.0;

// Function definition
void Seat_Prices();
void Display_Seating();
void Purchase_Ticket();
void Ticket_Sales();
void Show_Statistics();

// Calls all other functions
int main()
{
	Seat_Prices();
	Initialize_Seating();

	int choice = 0;
	do
	{
		cout << "\nTheater Ticket Seating Menu\n";
		cout << "1. Display Seating Chart\n";
		cout << "2. Purchase Ticket\n";
		cout << "3. View total ticket sales\n";
		cout << "4. View sales and availability statistics\n";
		cout << "Enter choice (1-5): ";
		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number between 1 and 5." << endl;
			continue;
		}

		switch (choice)
		{
		case 1:
			Display_Seating();
			break;
		case 2:
			Purchase_Ticket();
			break;
		case 3:
			Ticket_Sales();
			break;
		case 4:
			Show_Statistics();
			break;
		case 5:
			cout << "Exiting.\n";
			break;
		default:
			cout << "Invalid choice. Please try again\n";
			break;
		}
	} while (choice != 5);

	return 0;
}

void Show_Statistics()
{
	int totalSold = 0;
	int totalAvailable = 0;

	cout << "\nAvailability per row:\n";

	for (int r = 0; r < ROWS; ++r)
	{
		int soldPerRow = 0;
		int availablePerRow = 0;
		for (int seat = 0; seat < SEATS_PER_ROW; ++seat)
		{
			if (seats[r][seat] == '*') ++soldPerRow;
			else ++availablePerRow;
		}

		totalSold += soldPerRow;
		totalAvailable += availablePerRow;

		cout << "Row " << setw(2) << (r + 1) << ": SOld = " << setw(3) << soldPerRow
			<< ", Available = " << setw(3) << availablePerRow
			<< ", Price = $" << fixed << setprecision(2) << seatPrices[r] << '\n';
	}

	cout << "\nTotal seats sold: " << totalSold;
	cout << "\nTotal seats available: " << totalAvailable;
	cout << "\nTotal auditorium capacity: " << (ROWS * SEATS_PER_ROW) << '\n';
}