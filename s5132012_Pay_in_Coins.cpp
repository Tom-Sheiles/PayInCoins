#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

// Takes an input string and assigns each number in the string to value,beginRange and endRange
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

// Takes an integer value and returns a boolean if the input is a prime number
bool isPrime(int x){
    
    for(int i = 2; i < x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
    
}

// takes a value and returns a vector of prime numbers between 0 and value
vector <int> calculatePrimes(int value, int min, int max){
    
    vector <int> primes;
    
    primes.push_back(1);
    for(int i = 2; i < value; i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
    
    return primes;
}

// Main function for calculating sum. takes array of possible numbers, an empty array and the range of values.
// increments answers int when a valid solution is found 
void sumNumbers(vector <int> primeArray, vector <int> currentSum, int value, int beginRange, int endRange, int *answers, int step){
    
    int size = primeArray.size();
    int sumSize = currentSum.size();
 
    if(value < 0){
        return;
    }

    if(value == 0){
        if(beginRange > 0 && endRange > 0){
            
            if(sumSize >= beginRange && sumSize <= endRange){
                *answers = *answers + 1;
                return;
            }
            
        }else if(beginRange > 0 && endRange < 0){
            
            if(sumSize == beginRange){
                *answers = *answers + 1;
                return;
            }
            
        }else{

            *answers = *answers + 1;
            return;
        }
    }
    
    while(step < size && (value - primeArray[step]) >= 0){
        
        // currentSum.push_back(primeArray[step]);
        currentSum.insert(currentSum.end(), primeArray[0], primeArray[step]);
        sumNumbers(primeArray, currentSum, value - primeArray[step], beginRange, endRange, answers, step);
        step ++;
        currentSum.pop_back();        
    }
    
}


// Calls the main calculation function as well as initializing values needed for calculation
int countCoins(int value, int beginRange, int endRange){
    
    vector <int> primeArray;
    vector <int> currentSum;
    int answers = 0;    
        
    primeArray = calculatePrimes(value, beginRange, endRange);
    if(beginRange == -1 || beginRange == 1){
        primeArray.push_back(value);
    }
    sumNumbers(primeArray, currentSum, value, beginRange, endRange, &answers, 0);
    cout <<"Answers: " << answers;
    
    return answers;
}


// appends the output to a file named Output.txt. Takes int number of solutions as input
void appendOutput(int n){
    
    ofstream output;
    output.open("Output.txt", ios_base::app);
    output << n << "\n";
    output.close();
}

// Takes array of input strings and calls calculation functions with each
void calculate(string *inputs, int nInputs){
    
    int beginRange = 0;
    int endRange = 0;
    int value = 0;
    int answers = 0;
    clock_t start_t, end_t;
    double cpu_time_used;
    
    cout << endl;

    for(int i = 0; i < nInputs; i++){
        parseNumber(inputs[i], &value, &beginRange, &endRange);
        start_t = clock();

        answers = countCoins(value, beginRange, endRange);
        end_t = clock();
        cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
        cout << " " << "Complete Time: " << cpu_time_used << endl;
        
        appendOutput(answers);
    }
    
    cout << endl << "Answers added to \"Output.txt\"" << endl;
    
}


int main(int argc, char **argv){
    
    string filePath;
    
    if(argc > 1){
        
        filePath = argv[1];

    }else{
        cout << "Enter the file path for \"input.txt\": ";
        cin >> filePath;
    
    }
    
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
    
    inputFile.close();
    
}