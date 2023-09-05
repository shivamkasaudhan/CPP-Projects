#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
public:
    string title;
    int seatCount;

    Movie(string t, int seats) : title(t), seatCount(seats) {}

    bool bookSeats(int numSeats) {
        if (seatCount >= numSeats) {
            seatCount -= numSeats;
            return true;
        }
        return false;
    }
};

class Cinema {
private:
    vector<Movie> movies;

public:
    Cinema() {
        // Some sample movies for the simulation
        movies.push_back(Movie("Jawan", 100));
        movies.push_back(Movie("Salaar", 50));
        movies.push_back(Movie("Blue Beetle", 75));
        movies.push_back(Movie("Exorcist", 50));
    }

    void showMovies() {
        cout << "Available movies: " << endl;
        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". " << movies[i].title << " - Seats available: " << movies[i].seatCount << endl;
        }
    }

    bool bookMovie(int movieIndex, int numSeats) {
        if (movieIndex > 0 && movieIndex <= movies.size()) {
            return movies[movieIndex - 1].bookSeats(numSeats);
        }
        return false;
    }
};

int main() {
    Cinema cinema;
    while (true) {
        cinema.showMovies();

        cout << "Enter the number of the movie you want to book or 0 to exit: ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        cout << "How many seats do you want to book? ";
        int seats;
        cin >> seats;

        if (cinema.bookMovie(choice, seats)) {
            cout << "Booking successful!" << endl;
            cout << "Total cost: Rs." << seats * 100 << " (Rs.100 per seat)" << endl; // Assuming each ticket costs ₹100
        } else {
            cout << "Sorry, not enough seats available for the selected movie." << endl;
        }

        cout << "-------------------------------------------" << endl;
    }

    return 0;
}
