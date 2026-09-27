#include "markov.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    

    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);



    std::string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(words, count, 2, prefixes, suffixes, 1000);
    for (int i = 0; i < 20 && i < chainSize; i++) {
    std::cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
}


}


