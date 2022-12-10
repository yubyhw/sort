#include "csvstream.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    // Open file
    csvstream csvin("D:\\CTDL&GT\\Sort\\Sort_big_data\\intput_done_1.csv");
    ofstream List_Id("D:\\CTDL&GT\\Sort\\Sort_big_data\\List_Id.txt");

    //   Rows have key = column name, value = cell datum
    map<string, string> row;

    // Extract the "Id" column
    while (csvin >> row)
    {
        List_Id << row["Id"] << "\n";
        cout << row["Id"] << "\n";
    }
    List_Id.close();
    return 0;
}
