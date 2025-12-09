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

    map<string, vector<int>> movies;

    while (file >> title >> rating) 
    {
        movies[title].push_back(rating);
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
        cout << averageRating << endl;
        cout << "\tAverage Rating: " << averageRating / p.second.size() << endl;
    }

    cout << endl;
    cout << "Total movies: " << movies.size() << endl;

    return 0;
}