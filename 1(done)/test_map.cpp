#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void test_operator_square_bracket();
void sellStocks(map<string, int>& stocks, int threshold);
int countStocks(const map<string, int>& stocks);

int main(){
    typedef map<string, vector<string> > chordMap;
    chordMap jazzChords;

    vector<string> cmajor;
    cmajor.push_back("C"); cmajor.push_back("E"); cmajor.push_back("G");

    // example of using 'insert', and check the return result of it
    pair<chordMap::iterator, bool> result = jazzChords.insert(make_pair(string("C Major"), cmajor));
    if(!result.second){ 
        cerr << "ERROR: \" " << result.first->first << "\" already present!";
        cerr << endl;
        exit(1);
    }

    // example of using 'find'
    chordMap::const_iterator found = jazzChords.find("F# minor 11");
    if(found == jazzChords.end()){
        cout << "Chord was never recorded." << endl;
    }
    else{
        cout << "Notes of the " << found->first << " chord: " << endl;
        for(vector<string>::const_iterator note = found->second.begin(); note != found->second.end(); ++note){
            cout << "\t" << *note << endl;
        }
    }

    // example of using '[]'
    test_operator_square_bracket();
	return 0;
}


void test_operator_square_bracket(){
    map<string, int> portfolio;

    portfolio["LU"] = 400;
    portfolio["AAPL"] = 80;
    portfolio["GOOG"] = 6500;

    for(map<string, int>::iterator curr = portfolio.begin(); curr != portfolio.end(); curr++){
        cout << curr->first << " = " << curr->second << endl;
    }

    portfolio["AAPL"] += 100;
    for(map<string, int>::iterator curr = portfolio.begin(); curr != portfolio.end(); curr++){
        cout << curr->first << " = " << curr->second << endl;
    }
}

// other form of traverse of map
void sellStocks(map<string, int>& stocks, int threshold){
    map<string, int>::iterator curr = stocks.begin();
    while(curr != stocks.end()){
        if(curr->second >= threshold) curr->second /= 2;
        ++curr;
    }
}

// othre form of traverse of map
int countStocks(const map<string, int>& stocks){
    int stockCount = 0;
    map<string, int>::const_iterator curr = stocks.begin();
    while(curr != stocks.end()){
        stockCount += curr->second;
        ++curr;
    }
    return stockCount;
}
