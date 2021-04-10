//Jayden Campbell
//CIS 1202 101
//March 26, 2021

#include "Publication.h"
#include "StandardHFile.h"

#include <Windows.h>

void getPublicationInfo(Publication&);
int getMenuChoice();
void getPublications(Publication[], int&, int);
void showPublications(Publication[], int);
void showTitles(Publication[], int);
int findPublication(Publication[], int, string);
int main(){
    int maxSize = 20;
    get(maxSize, "Please enter the maximum number of publications you wish to read: ");
    while (maxSize <= 0) {
        cout << "Please enter a number of publications above zero.\n";
        get(maxSize, "Please enter the maximum number of publications you wish to read: ");
    }
    Publication *publication = new Publication[maxSize];
    int size;
    getPublications(publication, size, maxSize);
    int menuChoice = 0;
    string titleChoice;
    int publicationLocation;
    while (menuChoice != 6) {
        menuChoice = getMenuChoice();
        switch (menuChoice) {
        case 1:
            showPublications(publication, size);
            break;
        case 2:
            showTitles(publication, size);
            break;
        case 3:
            cout << "Please enter the title of the publication you wish to see: ";
            cin.ignore(100, '\n');
            getline(cin, titleChoice);
            transform(titleChoice.begin(), titleChoice.end(), titleChoice.begin(), tolower);
            publicationLocation = findPublication(publication, size, titleChoice);
            if (publicationLocation > -1)
                publication[publicationLocation].displayInfo();
            else
                cout << "Publication could not be found.\n\n";
            break;
        case 4:
            cout << "Please enter the title of the publication you wish to check out: ";
            cin.ignore(100, '\n');
            getline(cin, titleChoice);
            transform(titleChoice.begin(), titleChoice.end(), titleChoice.begin(), tolower);
            publicationLocation = findPublication(publication, size, titleChoice);
            if (publicationLocation > -1)
                publication[publicationLocation].checkOut();
            else
                cout << "Publication could not be found.\n\n";
            break;
        case 5:
            cout << "Please enter the title of the publication you wish to check in: ";
            cin.ignore(100, '\n');
            getline(cin, titleChoice);
            transform(titleChoice.begin(), titleChoice.end(), titleChoice.begin(), tolower);
            publicationLocation = findPublication(publication, size, titleChoice);
            if (publicationLocation > -1)
                publication[publicationLocation].checkIn();
            else
                cout << "Publication could not be found.\n\n";
            break;
        default:
            cin.ignore();
            leave();
        }
        
    }

    cin.ignore();
    leave();
}

//Gets the info required for the publication.
void getPublicationInfo(Publication& publication) {
    string tempTitle;
    string tempPublisher;
    float tempPrice;
    int tempYear;
    int tempType;
    int tempStock;
    cout << "Please enter the title of your publication: ";
    getline(cin, tempTitle);
    cout << "Please enter the publisher name of your publication: ";
    getline(cin, tempPublisher);
    get(tempPrice, "Please enter the price of your publication: ");
    while (tempPrice < 0) {
        cout << "Negative prices are not allowed.\n";
        get(tempPrice, "Please enter the price of your publication: ");
    }
    get(tempYear, "Please enter the year of your publication: ");
    while (tempYear < 0) {
        cout << "Negative years are not allowed.\n";
        get(tempYear, "Please enter the year of your publication: ");
    }
    get(tempType, 0 ,5 ,"Please pick the type of publication:\n 1. Book\\2. Magazine\\3. Newspaper\\4. Audio\\5. Video\nType: ");
    get(tempStock, "Please enter the stock for your publication: ");
    while (tempStock < 0) {
        cout << "Negative stock is not allowed.\n";
        get(tempStock, "Please enter the stock for your publication: ");
    }

    publication.storePublication(tempTitle, tempPublisher, tempPrice, tempYear, tempType, tempStock);
}

int getMenuChoice() {
    int temp;
    cout << "Please enter one of the options below:\n";
    cout << "1. Show all publications\n";
    cout << "2. Show all titles\n";
    cout << "3. Find a specific publication\n";
    cout << "4. Check out a book\n";
    cout << "5. Check in a book\n";
    cout << "6. Exit the program\n\n";
    get(temp, 1, 6, "Please enter your menu choice: ");
    return temp;
}

void getPublications(Publication publication[], int& size, int maxSize) {
    string directory;
    string fileName;
    size = 0;
    cin.ignore(100, '\n');
    cout << "Please enter the directory: ";
    getline(cin, directory);
    cout << "Please enter the file name: ";
    getline(cin, fileName);

    ifstream input;
    input.open(directory + "\\" + fileName + ".txt");

    if (input.is_open()) {
        cout << "Opened Successfully. Reading...\n";
        string tempTitle;
        string tempPublisher;
        double tempPrice;
        int tempYear;
        int tempType;
        int tempStock;
        while (getline(input,tempTitle) && size < maxSize) {
            getline(input, tempPublisher);
            input >> tempPrice;
            input >> tempYear;
            input >> tempType;
            input >> tempStock;
            input.ignore(100, '\n');
            publication[size].storePublication(tempTitle, tempPublisher, tempPrice, tempYear, tempType, tempStock);
            size++;
        }
    }
    else
        cout << "Failed to load file.\n";
}

void showPublications(Publication publication[], int size) {
    for (int i = 0; i < size; i++) {
        publication[i].displayInfo();
    }
}

void showTitles(Publication publication[], int size) {
    for (int i = 0; i < size; i++) {
        cout << publication[i].getTitle() << endl;
    }
    cout << endl;
}

int findPublication(Publication publication[], int size, string titleChoice) {
    for (int i = 0; i < size; i++) {
        string lowerTitle = publication[i].getTitle();
        transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), tolower);
        if (lowerTitle.compare(titleChoice) == 0) {
            return i;
        }
    }
    return -1;
}