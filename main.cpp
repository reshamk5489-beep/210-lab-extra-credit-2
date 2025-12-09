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