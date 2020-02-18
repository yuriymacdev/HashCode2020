//
//  main.cpp
//  TestPizzaHashcode
//
//  Created by George on 2/18/20.
//  Copyright © 2020 Yuri. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

string input =
"10 5\n"
"2 4 6 12 15\n";

std::string loadFileIntoString(string filepath) {
    std::ifstream fs(filepath);
    if(!fs.is_open()) throw invalid_argument("file " +filepath+" doesn't seem to exist or cant be opened");
    std::stringstream buffer;
    buffer << fs.rdbuf();
    return buffer.str();
}

void saveStringToFile(string &str, string filepath) {
    std::ofstream fs(filepath);
    fs << str;
    fs.close();
}

std::vector<long long> getElementsFromString(const std::string& str, int lineNo)
{
    std::string line;
    std::istringstream stream(str);
    while (lineNo-- >= 0)
        std::getline(stream, line);

    std::stringstream iss( line );
    long long number;
    std::vector<long long> myNumbers;
    while ( iss >> number )
      myNumbers.push_back( number );
    return myNumbers;
}

int main(int argc, const char * argv[]) {
    
    const string problemFilename = "e_also_big";
    input = loadFileIntoString("/Users/george/Desktop/HashCode2020/TestPizzaHashcode/"+problemFilename+".in");
    
    // parsing that shit
    vector<long long> firstLine = getElementsFromString(input, 0);
    if(firstLine.size() != 2) throw std::invalid_argument("First line must have 2 elements");
    long long M = firstLine[0]; //max num of pizza slices to order
    long long N = firstLine[1]; //num of diff types of pizza
    
    vector<long long> slicesPerEachType = getElementsFromString(input, 1); // N elements
    if(firstLine.size() != 2) throw std::invalid_argument("Second line doesn't have corrent number of elements");

    vector<long long> orderedPizzaTypes;
    
    long long totalSlicesOrdered = 0;
    for(long long i=N-1; i>=0; i--) { // for all pizza types
        long long currentPizzaSlicesNum = slicesPerEachType[i];
        
        if (totalSlicesOrdered+currentPizzaSlicesNum <= M) {
            totalSlicesOrdered += currentPizzaSlicesNum;
            orderedPizzaTypes.push_back(i);
        }
    }
    
    std::reverse(orderedPizzaTypes.begin(), orderedPizzaTypes.end());
    
    string output;
    stringstream outss;
    outss << orderedPizzaTypes.size() << "\n";
    
    for(long long i=0; i<orderedPizzaTypes.size(); i++) {
        outss << orderedPizzaTypes[i] << " ";
    }
    
    outss<<"\n";
    
    output = outss.str();
    
    saveStringToFile(output, "/Users/george/Desktop/HashCode2020/TestPizzaHashcode/"+problemFilename+".out");
    
    cout << output;
        
    return 0;
}
