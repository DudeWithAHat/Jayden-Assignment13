#include "Publication.h"
#include <string>
#include <iostream>

using namespace std;
//Setters
void Publication::setTitle(string title) {
	this->title = title;
}
void Publication::setPublisher(string publisher) {
	this->publisher = publisher;
}
void Publication::setPrice(float price) {
	this->price = price;
}
void Publication::setYear(int year) {
	this->year = year;
}
void Publication::setType(int type) {
	this->type = static_cast<PublicationType>(type);
}
void Publication::setStock(int stock) {
	this->stock = stock;
}

//Stores info for a publication.
void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, int itemType, int itemStock){
	setTitle(itemTitle);
	setPublisher(itemPublisher);
	setPrice(itemPrice);
	setYear(itemYear);
	setType(itemType);
	setStock(itemStock);
}

//Displays the contents of the publication member variables by calling the getters
void Publication::displayInfo() {
	cout << endl << "Title: " << getTitle() << endl
		<< "Publisher: " << getPublisher() << endl
		<< "Price: " << getPrice() << endl
		<< "Year: " << getYear() << endl
		<< "Type: " << getType() << endl
		<< "Stock: " << getStock() << endl << endl;
}

void Publication::checkOut() {
	if (getStock() <= 0)
		cout << "I'm sorry, but your stock cannot go below 0.\n";
	else
		setStock(stock - 1);
}

void Publication::checkIn() {
	setStock(stock + 1);
}

