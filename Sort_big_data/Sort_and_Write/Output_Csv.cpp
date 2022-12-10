#include "csvstream.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<string> inF{
    "out.csv" };
const string Out{ "D:\\CTDL&GT\\Sort\\Sort_big_data\\sorted_books_rating.csv" };

int main()
{

    ifstream In;
    int a[1000];
    In.open("D:\\CTDL&GT\\Sort\\Sort_big_data\\Id_Sort.txt");
    int n = 0;
    while (In >> a[n])
        n++;
    In.close();

    // Open file
    csvstream csvin("D:\\CTDL&GT\\Sort\\Sort_big_data\\intput_done_1.csv");

    //    vector<pair<string, string>> row;
    //
    //    while (csvin >> row) {
    //        cout << "\n" << "row:" << "\n";
    //        for (unsigned int i=0; i < row.size(); ++i) {
    //            const string &column_name = row[i].first;
    //            const string &datum = row[i].second;
    //            cout << "  " << column_name << ": " << datum << "\n";
    //        }
    //    }

    csvstream iFile("out.csv");

    //read file
    vector<pair<string, string>> row;

    while (iFile >> row)
    {
        cout << "\n"
            << "row:"
            << "\n";
        for (unsigned int i = 0; i < row.size(); ++i)
        {
            const string& column_name = row[i].first;
            const string& datum = row[i].second;
            cout << "  " << column_name << ": " << datum << "\n";
        }
    }

    if (std::ofstream destinationFileStream{ Out }; destinationFileStream)
    {
        bool ignoreHeader{};
        for (std::string& filename : inF)
        {

            if (std::ifstream sourceFileStream{ filename }; sourceFileStream)
            {

                if (std::string throwAway{}; std::exchange(ignoreHeader, true))
                    std::getline(sourceFileStream, throwAway);
                destinationFileStream << sourceFileStream.rdbuf();
            }
            else
                std::cerr << "\nError: Could not open source file '" << filename << "'\n";
        }
    }
    else
        std::cerr << "\nError: Could not open destination file '" << Out << "'\n";

    return 0;
}
