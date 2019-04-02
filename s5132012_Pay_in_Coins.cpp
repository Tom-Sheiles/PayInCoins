#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void parseNumber(string line){
    cout << line << endl;
}

void calculate(string *inputs, int nInputs){
    
    for(int i = 0; i < nInputs; i++){
        parseNumber(inputs[i]);
    }
    
}


int main(int argc, char **argv){
    
    string filePath;
    cout << "Enter the file path for \"input.txt\": ";
    cin >> filePath;
    filePath.append("\\input.txt");
    cout << "Opening: " << filePath << endl;
    
    ifstream inputFile(filePath.c_str());
    string lines;
    string inputs[100];

    int i = 0;
    if(inputFile.is_open())
    {
        while(!inputFile.eof()){
            getline(inputFile, lines);
            inputs[i] = lines;
            cout << inputs[i] << endl;
            i++;            
        }
    }else{
        cout << "Could not Find \"input.txt\"" << endl;
        exit(1);
    }   

    calculate(inputs, i);
 
}