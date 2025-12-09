#include <fstream>
#include <iostream>
using namespace std;

class Movie 
{
    private:
        string title;
        int rating;

    public:
        Movie(string t, int r) : title(t), rating(r) {}

        string getTitle() const { return title; }
        int getRating() const { return rating; }
};

int main() 
{
    ifstream file("210-xc2-FA25.txt");
    string line;

    while (getline(file, line)) 
    {
        cout << line << endl;
    }

    file.close();

    return 0;
}