#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void parseNumber(string line, int *value, int *beginRange, int *endRange){
    
    int n = 1;
    int i = 0;
    int values[3];
    std::stringstream stream(line);
    
    //initialize values to -1
    for (int j = 0; j < 3; j++){    
        values[j] = -1;
    }
    
    //count amount of numbers in line
    for(int i = 0; i < int(line.length()); i++){
        if(isspace(line[i])){
            n++;
        }
    }

    //assign each number to an int array
    for(i = 0; i < n; i++){
        stream >> values[i];
    }
    
    //change the pointer values
    *value = values[0];
    *beginRange = values[1];
    *endRange = values[2];
    return;
    
}

int* calculatePrimes(int value, int min, int max){
    
    int *primes;
    
    
    return primes;
}

void countCoins(int value, int beginRange, int endRange){
    
    int *primeArray;
    primeArray = calculatePrimes(value, beginRange, endRange);
    
}

void calculate(string *inputs, int nInputs){
    
    int beginRange = 0;
    int endRange = 0;
    int value = 0;
    
    for(int i = 0; i < nInputs; i++){
        parseNumber(inputs[i], &value, &beginRange, &endRange);
        countCoins(value, beginRange, endRange);
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