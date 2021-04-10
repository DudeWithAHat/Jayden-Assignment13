#pragma once


#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <string>

using namespace std; 

enum PublicationType{BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO};

class Publication {
private:
	string title;
	string publisher;
	float price;
	int year;
	PublicationType type;
	int stock;
public:

	//Getters
	string getTitle() {
		return title;
	};
	string getPublisher() {
		return publisher;
	};
	float getPrice() {
		return price;
	};
	int getYear() {
		return year;
	};
	string getType() {
		switch (type) {
		case 0:
			return "Book";
			break;
		case 1:
			return "Magazine";
			break;
		case 2:
			return "Newspaper";
			break;
		case 3:
			return "Audio";
			break;
		default:
			return "Video";

		}
	};
	int getStock() {
		return stock;
	};

	void setTitle(string);
	void setPublisher(string);
	void setPrice(float);
	void setYear(int);
	void setType(int);
	void setStock(int);

	void storePublication(string, string, double, int, int, int);

	void displayInfo();

	void checkOut();

	void checkIn();

};

#endif