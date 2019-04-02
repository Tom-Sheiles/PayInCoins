#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
    
    ifstream inputFile("input.txt");
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
 
}