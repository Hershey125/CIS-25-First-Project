#ifndef MARKOV_H
#define MARKOV_H
#include <string>

std::string joinWords(const std::string words[], int startIndex, int count);

int readWordsFromFile(std::string filename, std::string words[], int maxWords);


int buildMarkovChain(const std::string words[], int numWords, int order, std::string prefixes[], std::string suffixes[], 
    int maxChainSize);





#endif