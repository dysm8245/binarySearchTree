#include "MovieInventory.hpp"
#include "MovieInventory.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void displayMenu() {
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Search movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Average Rating of movies" << endl;
    cout << "5. Delete movie" << endl;
	cout << "6. Rotate movies around" << endl;
    cout << "7. Quit" << endl;
}

int main(int argc, char** argv) {
    int input;

    // Tree
    MovieInventory* tree = new MovieInventory();

    ifstream iFile(argv[1]);
    string line;

    // Variables for each line
    int ranking;
    int year;
    float rating;
    string title;

    // File IO
    while(getline(iFile, line)) {
        stringstream ss(line);
        string field;

        int counter = 0;
        while(getline(ss, field, ',')) {
            if (counter == 0)
                ranking = stoi(field);
            else if (counter == 1)
                title = field;
            else if (counter == 2)
                year = stoi(field);
            else if (counter == 3)
                rating = stof(field);
            counter++;
        }
        tree->addMovieItem(ranking, title, year, rating);
    }

    displayMenu();
    cin >> input;

    while (1) {
        if (input == 1) {
            string movie_title;
            cout << "Enter a movie title:" << endl;
            cin.ignore();
            getline(cin, movie_title);
            tree->getMovie(movie_title);
        }
        else if (input == 2){
            float search_rating;
            int search_year;
            cout << "Enter a minimum rating:" << endl;
            cin.ignore();
            cin >> search_rating;
            cout << "Enter a minimum year:" << endl;
            cin.ignore();
            cin >> search_year;
            tree->searchMovies(search_rating, search_year);
        }
        else if (input == 3){
            tree->printMovieInventory();
        }
        else if (input == 4){
            tree->averageRating();
        }
        else if (input == 5){
            string delete_movie_title;
            cout << "Enter a movie title:" << endl;
            cin.ignore();
            getline(cin, delete_movie_title);
            tree->deleteMovieItem(delete_movie_title);
        }
		else if (input == 6){
			string rotate_movie_title;
            string nodename;
			cout<< "Enter a movie title:"<<endl;
			cin.ignore();
			getline(cin, nodename);
			tree->leftRotate(rotate_movie_title);
		}
        else if (input == 6){
            cout << "Goodbye!" << endl;
            break;
        }
        displayMenu();
        cin >> input;
    }
    return 0;
}
