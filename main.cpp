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
    double maxAverageRating = 0.0;

    map<string, vector<int>> movies;

    while (file >> title >> rating) 
    {
        movies[title].push_back(rating);
    }

    file.close();

    // Extra Milestone 1
    cout << "------Milestone 1------" << endl;
    cout << "Movies and their ratings:" << endl;
    for (auto &p : movies) 
    {
        cout << "\t" << p.first << ": ";
        for (int r : p.second) cout << r << " ";
        cout << endl;
    }

    cout << endl;

    // Extra Milestone 2
    cout << "------Milestone 2------" << endl;
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
    cout << endl;

    // Extra Milestone 3
    cout << "------Milestone 3------" << endl;
    for (auto &p : movies) 
    {
        double averageRating = 0.0;
        for (int r : p.second) 
        {
            averageRating += r;
        }

        if (averageRating / p.second.size() > maxAverageRating) 
        {
            maxAverageRating = averageRating / p.second.size();
        }
    }
    
    cout << "Highest Average Rating: " << maxAverageRating << endl;
    cout << "Movies with highest average rating:" << endl;

    for (auto &p : movies) 
    {
        double averageRating = 0.0;
       
        for (int r : p.second) 
        {
            averageRating += r;
        }

        if (averageRating / p.second.size() >= maxAverageRating) 
        {
            cout << "\t" << p.first <<  endl;
        }
    }

    return 0;
}

// Extra Milestone 4