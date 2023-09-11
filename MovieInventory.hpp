#include <string>

using namespace std;

struct MovieItem{
    int ranking;
    string title;
    int year;
    float rating;

    MovieItem* left = NULL;
    MovieItem* right = NULL;

    MovieItem(int rank, string t, int y, float r) {
        title = t;
        ranking = rank;
        year = y;
        rating = r;
    }
};

class MovieInventory{
    private:
        MovieItem* root;

    public:
        MovieInventory();

        ~MovieInventory();

        void printMovieInventory();

        void addMovieItem(int ranking, std::string title, int year, float rating);

        void deleteMovieItem(std::string title);

        void getMovie(std::string title);

        void searchMovies(float rating, int year);

        void averageRating();

		void leftRotate(std::string title);
};
