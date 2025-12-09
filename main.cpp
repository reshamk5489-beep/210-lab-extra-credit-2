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
        movies.insert({title, vector<int>()});
    }

    file.close();
    
    for (auto &p : movies) 
    {
        cout << p.first << ": ";
        for (int r : p.second) cout << r << " ";
        cout << endl;
    }

    return 0;
}
