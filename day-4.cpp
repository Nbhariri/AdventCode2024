// day-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <map>
#include <cctype>
#include <cmath> // Include for pow

using namespace std;



int countWinningNumb(vector<int> v1, vector<int> v2) {
    int count = 0; 
    int result = 0;
    for (auto i : v1) {
        for (auto j : v2) {
            if (i == j ) {
                count += 1;
               // cout << j << i << endl;
                //cout << i << endl;
            }
        }
    }
    
    count = count - 1; 
   // cout << count << endl;
    return count;
}
int makeLists(string line) {
    size_t found = line.find(":");
    size_t stop = line.find("|");
    int start = found + 1; 
    int cardNum = found - 1; 
    int win = 0;
    int count = 0;
   // cout << "Card: " << line[cardNum] << endl;
    std::vector<int> listOne;
    std::vector <int> ListTwo;
    int number = 0;
   string str = ""; //for concation 
   for (int i = start; i < stop; i++)
   {
       if (isspace(line[i])) {
           if (str.length() != 0) {
               listOne.push_back(atoi(str.c_str()));
           }
           str = "";

       }
       else {
           str += line[i];
       }
   }
   if (str.length() > 0)
   {
       listOne.push_back(atoi(str.c_str()));
   }

    for (int i = stop; i < line.size(); i++)
    {
        if (isspace(line[i])) {
            if (str.length() != 0) {
                ListTwo.push_back(atoi(str.c_str()));
            }
            str = "";

        }
        else {
            str += line[i];
        }
    }
    if (str.length() > 0)
    {
        ListTwo.push_back(atoi(str.c_str()));
    }
    count =  countWinningNumb(listOne, ListTwo);
    //cout << "count for each line " << count << endl;
    if (count == -1) {
        return 0; 
    }
    else
    {
        win = pow(2, count);
        return win;
    }
}


int main()
{
    std::cout << "Hello World!\n";
    fstream myfile;
    string line;
    vector<int> resultvec;
    int resultf = 0;
    int k = 0;
    int final = 0;
    myfile.open("day-4.txt");
    //final += makeLists("Card 2: 13 32 20 16 61 1 | 61 30 68 82 17 32 24 19 1 ");
    while (getline(myfile, line)) {
   final +=   makeLists(line);
      //cout << final << endl;
    }
    cout << final << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
