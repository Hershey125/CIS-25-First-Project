#include "markov.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0)); //what is this?

    string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);



    std::string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(words, count, 2, prefixes, suffixes, 1000);

    for (int i = 0; i < 10; i++) {
    std::cout << getRandomSuffix(prefixes, suffixes, chainSize, "I am") << std::endl;
}

}




