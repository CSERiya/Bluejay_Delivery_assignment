/* c. Printing the Employee name and position ID of the employee Who has worked for more than 14 hours in a single shift.
Here, I have printed the name and position-id of the employee whose Timecard Hours are greater than 14 in a single row
for one time and in the ordered fashion.
*/

#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "xlsxwriter.h"

using namespace std;


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

    if(timecnt(employee[i][4])>1400){
        st.insert({employee[i][7], employee[i][0]});
    }
    }
    
for (auto j : st) {
        cout << "Name of employee " << j[0] << " and position of employee " << j[1] << endl;
    }
    return 0;
}

