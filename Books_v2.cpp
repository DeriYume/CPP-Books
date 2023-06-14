#include <iostream>
using namespace std;

void input(int& bookCount, double pages[]) {
	do {
		cout << "Input number of books in the range of [ 3 ; 5 ]: ";
		cin >> bookCount;
	} while (bookCount < 3 || bookCount > 5);

	for (int i = 0; i < bookCount; i++) {
		cout << "Input book " << (i + 1) << "\'s number of pages : ";
		cin >> pages[i];
	}
}

void sortBooks(int size, double pages[]) {
	for (int i = 1; i <= size - 1; i++)
		for (int j = 0; j <= size - i - 1; j++)
			if (pages[j] < pages[j + 1]) {
				double temp = pages[j];
				pages[j] = pages[j + 1];
				pages[j + 1] = temp;
			}

	for (int i = 0 ; i < size; i++) {
		cout << pages[i] << endl;
	}
}

void pagesMoreThan400(int size, double pages[]) {
	for (int i = 0; i < size; i++) {
		if (pages[i] > 400)
			cout << "Book " << (i + 1) << " - " << pages[i] << " pages\n";
	}
}

double sumPages(int size, double pages[]) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum = sum + pages[i];
	}

	return sum;
}

double minPages(int size, double pages[]) {
	double min = pages[0];

	for (int i = 0 ; i < size; i++) {
		if (pages[i] < min) 
			min = pages[i];
	}

	return min;
}

int main() {
	int switchKey;
	int bookCount;
	double pageCount[20];
	input(bookCount, pageCount);

	cout << "\n\n=====MENU=====\n\n";
	cout << "1) Book with >400 pages\n";
	cout << "2) Pages in total\n";
	cout << "3) The book with least pages\n";
	cout << "4) Order books\n";
	cout << "5) Terminate\n";
	cout << "-> Please pick an option from the Menu <-\n";
	cout << endl;

	do {
		cin >> switchKey;
		switch (switchKey) {
		case 1: {
			cout << "Book with >400 pages:\n"; pagesMoreThan400(bookCount, pageCount);
			break;
		}
		case 2: {
			cout << "The total is " << sumPages(bookCount, pageCount) << " pages.\n";
			break;
		}
		case 3: {
			cout << "The book with least pages is " << minPages(bookCount, pageCount) << endl;
			break;
		}
		case 4: {
			cout << "Ordered list:\n"; sortBooks(bookCount, pageCount);
			break;
		}
		default: if (switchKey != 5) cout << endl << "Please pick an option from the MENU!\n";
		}
	} while (switchKey != 5);

	return 0;
}