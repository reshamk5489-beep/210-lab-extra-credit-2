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
    double averageRating = 0.0;

    map<string, vector<int>> movies;

    while (file >> title >> rating) 
    {
        movies[title].push_back(rating);
    }

    file.close();
    
    for (auto &p : movies) 
    {
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

    return 0;
}