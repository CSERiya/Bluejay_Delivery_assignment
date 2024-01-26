/* b. Printing the Employee name and position ID of the employees who have less than 10 hours of time between shifts
but greater than 1 hour.
Here, I have considered time shifts as sum of TimecardHours occurring in the same day although in the different row, combinedly if
time duration is greater than 1 hr and less than 10 hrs. 
And, if the same employee satisfies the condition for multiple number of times I have console their name and position id 
for the one time and in the orderly manner using set.*/

#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "xlsxwriter.h"

using namespace std;

int days(string s) {
    string help = "";
    if(s==""){return 0;}
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/'){
            continue;}
        else if (s[i] == ' '){
            break;}
        else {
            help += s[i];
        }
    }
    return stoi(help);
}

int timecnt(string s){
     string help = "";
    if(s==""){return 0;}
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ':'){
            continue;}
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
set<vector<string>>st;

for (int i = 0; i < employee.size(); i++) {

    while (i < employee.size() - 1 && (days(employee[i + 1][2]) == days(employee[i][2]))) {
        int x = timecnt(employee[i][4]);
        int y = timecnt(employee[i + 1][4]);
        int sum = x + y;

        if (sum > 60 && sum < 960) {
            st.insert({employee[i][7], employee[i][0]});
        } else {
            break;
        }

        i++;
    }
    }
for (auto j : st) {
        cout << "Name of employee " << j[0] << " and position of employee " << j[1] << endl;
    }
    return 0;
}
