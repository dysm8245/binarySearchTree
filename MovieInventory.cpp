#include "MovieInventory.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieItem: node struct that will be stored in the MovieInventory BST

MovieInventory::MovieInventory() {
  //write your code
}

void destroyMovie(MovieItem *currMovie){
  if(currMovie != NULL){
    destroyMovie(currMovie->left);
    destroyMovie(currMovie->right);
    delete currMovie;
    currMovie = NULL;
  }
}

MovieInventory::~MovieInventory() {
  //write your code
  destroyMovie(root);
}

void printMovieHelper(MovieItem *currMovie){
  if(currMovie){
    printMovieHelper(currMovie->left);
    cout << "Movie: " << currMovie->title << " " << currMovie->rating << endl; 
    printMovieHelper(currMovie->right);
  }
}

void MovieInventory::printMovieInventory()
{
    // Your code here
    if(root == NULL){
        cout << "Tree is Empty. Cannot print" << endl;
    }
    printMovieHelper(root);
}

MovieItem *addMovieHelper(MovieItem *currMovie, string movie, int rank, int year, float rate){
  if(currMovie == NULL){
    MovieItem *newMovie = new MovieItem(rank, movie, year, rate);
    currMovie = newMovie;
  }
  else if(currMovie->title > movie){
    currMovie->left = addMovieHelper(currMovie->left, movie, rank, year, rate);
  }
  else if(currMovie->title < movie){
    currMovie->right = addMovieHelper(currMovie->right, movie, rank, year, rate);
  }
  return currMovie;
}
void MovieInventory::addMovieItem(int ranking, std::string title, int year, float rating)
{
    // Your code here
    root = addMovieHelper(root, title, ranking, year, rating);
}

void getMovieHelper(MovieItem *currMovie, string movie){
  if(currMovie->title == movie){
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << currMovie->ranking << endl; 
    cout << "Title :" << currMovie->title << endl; 
    cout << "Year :" << currMovie->year << endl; 
    cout << "rating :" << currMovie->rating << endl;
    return;
  }
  else if(currMovie->title > movie){
    if(currMovie->left == NULL){
      cout << "Movie not found." << endl;
      return;
    }
    getMovieHelper(currMovie->left, movie);
  }
  else if(currMovie->title < movie){
    if(currMovie->right == NULL){
      cout << "Movie not found." << endl;
      return;
    }
    getMovieHelper(currMovie->right, movie);
  }
}

void MovieInventory::getMovie(string title)
{
    // Your code here
    getMovieHelper(root, title);
}

void searchMovieHelper(MovieItem *currMovie, float rate, int year){
  if(currMovie){
    searchMovieHelper(currMovie->left, rate, year);
    if(currMovie->rating >= rate && currMovie->year > year){
      cout << currMovie->title << "(" << currMovie->year << ") " << currMovie->rating << endl;
    }
    searchMovieHelper(currMovie->right, rate, year);
  }
}

bool searchMovieHelper2(MovieItem *currMovie, float rate, int year, bool flag){
  if(currMovie){
    searchMovieHelper2(currMovie->left, rate, year, flag);
    if(currMovie->rating >= rate && currMovie->year > year){
        flag = 1;
    }
    searchMovieHelper2(currMovie->right, rate, year, flag);
  }
  return flag;
}

void MovieInventory::searchMovies(float rating, int year)
{
    // Your code here
    bool flag = searchMovieHelper2(root, rating, year, flag);
    if(root == NULL){
        cout << "Movie not found." << endl;
    }
    else{
        cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
        searchMovieHelper(root, rating, year);
    }
}

void averageRatingHelper(MovieItem *currMovie, int &count, float &rate){
  if(currMovie){
    averageRatingHelper(currMovie->left, count, rate);
    count++;
    rate += currMovie->rating;
    averageRatingHelper(currMovie->right, count, rate);
  }
}

void MovieInventory::averageRating(){
  //write your code
  int count = 0;
  float rate = 0.0;
  if(root == NULL){
    cout << "Average rating:0.0" << endl;
  }
  else{
    averageRatingHelper(root, count, rate);
    cout << "Average rating:" << rate/count << endl;
  }
}

MovieItem* minMovie(MovieItem *currMovie){
  if(currMovie->left == NULL){
    return currMovie;
  }
  return minMovie(currMovie->left);
}

MovieItem* deleteMovieHelper(MovieItem *currMovie, string movie){
  if(currMovie == NULL){
    cout << "Movie: " << movie << " not found, cannot delete." << endl;
  }
  else if(movie < currMovie->title){
    currMovie->left = deleteMovieHelper(currMovie->left, movie);
  }
  else if(movie > currMovie->title){
    currMovie->right = deleteMovieHelper(currMovie->right, movie);
  }
  else{
    if(currMovie->left == NULL && currMovie->right == NULL){
      deleteMovieHelper(currMovie, movie);
    }
    else if(currMovie->left == NULL){
      MovieItem *temp = NULL;
      temp = currMovie;
      currMovie = currMovie->right;
      delete temp;
    }
    else if(currMovie->right == NULL){
      MovieItem *temp = NULL;
      temp = currMovie;
      currMovie = currMovie->left;
      delete temp;
    }
    else{
      MovieItem *temp = minMovie(currMovie->right);
      currMovie = temp;
      deleteMovieHelper(currMovie->right, movie);
    }
  }
  return currMovie;
}

void MovieInventory::deleteMovieItem(string title)
{
  //write your code
  root = deleteMovieHelper(root, title);
}

MovieItem* rotateHelper(MovieItem *currMovie, string movie){
  if(currMovie == NULL){
    return currMovie;
  }
  else if(currMovie->title == movie){
    return currMovie;
  }
  else if(movie < currMovie->title){
    currMovie->left = rotateHelper(currMovie->left, movie);
  }
  else if(movie > currMovie->title){
    currMovie->right = rotateHelper(currMovie->right, movie);
  }
}

void rotation(MovieItem *currMovie){
  if(currMovie == NULL){
    return;
  }
  if(currMovie->right == NULL){
    return;
  }
  else{
    MovieItem *temp = currMovie->right;
    MovieItem *temp2 = temp->left;
    currMovie->right = temp2;

    if(temp2 != 0){
      temp = currMovie;
    }

    temp->left = currMovie;
    temp;
  }
}

void MovieInventory::leftRotate(string title)
{
  //write your code
}