/* a. Printing the Employee name and position ID of the employees who has worked for 7 consecutive days.
Here, I have considered consecutive days as either Same or 1 day difference Time_in date. (means either 09/12/2023 and 
09/12/2023 or 09/12/2023 and 09/13/2023).
Also if same employee has worked for 14 days means 7 days separately multiple times I have print their
name that many time. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "xlsxwriter.h"
  
using namespace std;

int days(string s) {
    string help = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/')
            continue;
        else if (s[i] == ' ')
            break;
        else {
            help += s[i];
        }
    }
    return stoi(help);
}

int main() {
    // Path for the csv file
    std::string filepath = "C:/Users/lenovo/Desktop/Assignment/Assignment_Timecard.xlsx - Sheet1.csv";

    ifstream inputFile(filepath);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filepath << endl;
        return 1;
    }

    vector<vector<string>> employee;

    string line;

    getline(inputFile, line);

    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<string> record;
        string token;

        while (getline(ss, token, ',')) {
            record.push_back(token);
        }

        employee.push_back(record);
    }

    inputFile.close();

    // Process the employee records
    for (int i = 0; i < employee.size(); i++) {
        int cnt = 0;
        while (i < employee.size() - 1 && employee[i][7] == employee[i + 1][7]) {
            if (cnt<7 &&(((days(employee[i + 1][2]) - days(employee[i][2])) == 10000) || 
            (days(employee[i + 1][2]) == days(employee[i][2])))) {
                cnt++;
                i++;
            } 
            else {
                break;
            }
        }
        if (cnt == 7) {
            cout << "Name of employee " << employee[i][7] << " and position of employee " << employee[i][0] << endl;
        }
    }

    return 0;
}
