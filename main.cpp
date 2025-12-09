#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() 
{
    ifstream file("210-xc2-FA25.txt");
    string title;
    int rating;
    double maxAverageRating;

    map<string, vector<int>> movies;

    while (file >> title >> rating) 
    {
        double averageRating = 0.0;

        auto &ratings = movies[title];
        ratings.push_back(rating);
        
        for (int r : ratings) 
        {
            averageRating += r;
        }

        if (averageRating / ratings.size() > maxAverageRating) 
        {
            maxAverageRating = averageRating / ratings.size();
        }
    }

    file.close();
    
    for (auto &p : movies) 
    {
        double averageRating = 0.0;
        cout << p.first <<  endl;
        cout << "\tRatings: ";
        for (int r : p.second) 
        {
            cout << r << " ";
            averageRating += r;
        }
        cout << endl;
        cout << "\tAverage Rating: " << averageRating / p.second.size() << endl;
    }

    cout << endl;
    cout << "Total movies: " << movies.size() << endl;

    cout << "Highest Average Rating: " << maxAverageRating << endl;
    
    return 0;
}