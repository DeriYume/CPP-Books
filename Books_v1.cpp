#include <iostream>
#include <string>
using namespace std;

class book {
	string title, author;
	float price;
	int year;

public:
	book();
	void printInfo();
	void printTitleAndPrice();
	void printTitleAndYear();
	int get_year() { return year; }
	float get_price() { return price; }
};

book::book() {
	cout << "Input book..." << endl;

	do {
		cout << "title: ";
		cin >> title;
	} while (title.length() < 2 || title.length() > 50);
	cin.ignore();

	do {
		cout << "author: ";
		cin >> author;
	} while (author.length() < 4 || author.length() > 30);
	cin.ignore();

	do {
		cout << "year: ";
		cin >> year;
	} while (year < 1800 || year > 2023);
	cin.ignore();

	do {
		cout << "price: ";
		cin >> price;
	} while (price < 5.00 || price > 100.00);
	cin.ignore();

	cout << endl;
}

void book::printInfo() {
	cout << title << " by " << author
		<< ", published in " << year
		<< ", for " << price << "$.\n";
}

void book::printTitleAndPrice() {
	cout << title << " for " << price << "$.\n";
}

void book::printTitleAndYear() {
	cout << title << " (" << year << ")\n";
}

book comparePublishYear(book b1, book b2) {
	if (b1.get_year() < b2.get_year()) return b1;
	else return b2;
}

void sortBooks(int size, book bookshelf[]) {
	for (int i = 1; i < size; i++)
		for (int j = 0; j <= size - i - 1; j++)
			if (bookshelf[j].get_year() < bookshelf[j + 1].get_year()) {
				book temp = bookshelf[j];
				bookshelf [j] = bookshelf[j + 1];
				bookshelf[j + 1] = temp;
			}
			else {
				if (bookshelf[j].get_price() < bookshelf[j + 1].get_price()) {
					book temp = bookshelf[j];
					bookshelf[j] = bookshelf[j + 1];
					bookshelf[j + 1] = temp;
				}
			}

	for (int i = 0; i < size; i++) {
		bookshelf[i].printInfo();
	}
}

book cheapestBook(int size, book bookshelf[]) {
	int index = 0;
	double min = bookshelf[0].get_price();

	for (int i = 1; i < size; i++) {
		if (bookshelf[i].get_price() < min) {
			min = bookshelf[i].get_price();
			index = i;
		}
	}

	return bookshelf[index];
}

void avgPrice(int size, book bookshelf[]) {
	double sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		sum += bookshelf[i].get_price();
		count++;
	}
	cout << sum / count << "$.\n";
}

int main()
{
	cout << "Part 1: Input info about 2 books.\n";
	book a, b;
	cout << "Input info:\n";
	a.printInfo();
	b.printInfo();

	cout << "\nThe book published earlier is: ";
	comparePublishYear(a, b).printTitleAndYear();
	cout << endl;

	cout << "Part 2: Input info about 2-10 books.\n";
	int numberOfBooks;
	do {
		cout << "How many books would you like to input?\nPick a number in range [ 2 ; 10 ]: ";
		cin >> numberOfBooks;
	} while (numberOfBooks < 2 || numberOfBooks > 10);
	cin.ignore();

	book* bookList = new book[numberOfBooks];
	cout << "\nHere's your input descending by year (and then by price): \n";
	sortBooks(numberOfBooks, bookList);
	cout << "\nHere's the average of the prices: ";
	avgPrice(numberOfBooks, bookList);
	cout << "Here's the cheapest book: ";
	cheapestBook(numberOfBooks, bookList).printTitleAndPrice();

	return 0;
}