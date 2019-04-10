#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

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


bool isPrime(int x){
    
    for(int i = 2; i < x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
    
}

vector <int> calculatePrimes(int value, int min, int max){
    
    vector <int> primes;
    
    primes.push_back(1);
    for(int i = 2; i < value; i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
    
    
   /* if(min > -1 and max == -1){
        primes.push_back(1);
        
        for(int i = 2; i < value; i++){
            if(isPrime(i))
                primes.push_back(i);
        }    
        
    }else if(min == -1 or max == -1){
        primes.push_back(1);

        for(int i = 2; i < value; i++){
            if(isPrime(i))
                primes.push_back(i);
        }
    }else if(min > -1 and max > -1){
        
        for(int i = min; i < max; i++){
            if(isPrime(i))
                primes.push_back(i);
        }
    }*/
    
    return primes;
}

void sumNumbers(vector <int> primeArray, vector <int> currentSum, int value, int beginRange, int endRange, int *answers, int step){
    
    int size = primeArray.size();
    
    if(value == 0){
        if(beginRange != -1){
            
            if(currentSum.size() >= beginRange && currentSum.size() <= endRange){
                for(int i = 0; i < currentSum.size(); i++){
                    cout << currentSum.at(i);
                }
                cout << endl;
                *answers = *answers + 1;
                return;
            }
            
        }else if(endRange != -1){
            
            cout << "ONLY ONE NYMber";
            //TODO: KEEP GOING HERE, ADD FOR ONLY ONE NUMBER BEGIN RANGE > 0 BUT END RANGE < 0
            
        }else{
            
            for(int i = 0; i < currentSum.size(); i++){
                cout << currentSum.at(i);
            }
            cout << endl;
            *answers = *answers + 1;
            return;
        }
    }
    
    while(step < size && (value - primeArray[step]) >= 0){
        
        currentSum.push_back(primeArray[step]);
        sumNumbers(primeArray, currentSum, value - primeArray[step], beginRange, endRange, answers, step);
        step ++;
        currentSum.pop_back();        
    }
    
}

int countCoins(int value, int beginRange, int endRange){
    
    vector <int> primeArray;
    vector <int> currentSum;
    int answers = 0;    
        
    if(beginRange == -1){
        answers++;
    }
    
    primeArray = calculatePrimes(value, beginRange, endRange);
    sumNumbers(primeArray, currentSum, value, beginRange, endRange, &answers, 0);
    cout <<"Answers: " << answers << endl;
    
    return answers;
}


void calculate(string *inputs, int nInputs){
    
    int beginRange = 0;
    int endRange = 0;
    int value = 0;
    
    cout << endl;

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
        cout << "Inputs: " << endl;
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
    
    /*vector <int> test;
    test = calculatePrimes(100, 5, 20);
    for(int i = 0; i < test.size(); i++){
        cout << test.at(i) << endl;
    }*/
    
    
}