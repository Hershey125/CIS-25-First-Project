#include "markov.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


string joinWords(const string words[], int startIndex, int count){
    string result = "";
    if(count > 0 && startIndex >= 0){
            for(int i = 0; i<count; i++){
                if(i != count - 1){
                result = result + words[startIndex + i]+ " ";
                }
                else{
                    result += words[startIndex + i];
                }
            }return result;
    }else{
        return "";
    }
}


int readWordsFromFile(string filename, string words[], int maxWords){
    ifstream inputFile;
    inputFile.open(filename);
    bool isOpen = inputFile.is_open();
    int counter = 0;
    if(isOpen){
        while(counter < maxWords && inputFile >> words[counter]) { //inputFile >> words[counter] stores and reads the next line?? - ask prof
                counter ++;
        }
        return counter;
    }else{
        return -1;
    }
}

int buildMarkovChain(const string words[], int numWords, int order, string prefixes[], string suffixes[], 
    int maxChainSize){

        if(order < 1 || order > 3 || numWords <= order || maxChainSize <= 0 ){
            return 0;
        }

        int count = 0;
        
        int i = 0;
        
        while( i<numWords - order && count < maxChainSize){
            string prefix = joinWords(words, i, order);
            string suffix = words[i+order];
            prefixes[count] = prefix;
            suffixes[count] = suffix;
            count ++;
            i++;
        }

        return count;
    }

    string getRandomSuffix(const string prefixes[], const string suffixes[], int chainSize, string currentPrefix){
        int matchCount = 0;
        for (int i =0; i < chainSize; i++){
            if(currentPrefix == prefixes[i]){
                matchCount++;
            }
        }
        if(matchCount == 0){
            return "";
        }

        int pick = rand() % matchCount;
        int matchCount2 = 0;
        for(int i =0; i<chainSize; i++){
            if(currentPrefix == prefixes[i]){
                if(matchCount2 == pick){
                    return suffixes[i];
                }
                matchCount2 ++;
            }
        }
        return "";
    }

    string getRandomPrefix(const string prefixes[], int chainSize){
        if(chainSize <= 0){
            return "";
        }else{
            int index = rand() % chainSize;
            return prefixes[index];
        }
    }

    string generateText(const string prefixes[], const string suffixes[], int chainSize, int order, int numWords){

        if(order < 1 || order > 3 || numWords < order || chainSize <= 0 ){
            return "";
        }
        string currentPrefix = getRandomPrefix(prefixes, chainSize); 
        

        string result = currentPrefix;

        string currentWords[3];

        int wordIndex = 0;                                                                                                                                                                 
    string temp = "";
    for (int i = 0; i < currentPrefix.length(); i++) {                                                                                                                                 
      if (currentPrefix[i] == ' ') {                                                                                                                                                 
          currentWords[wordIndex] = temp;                                                                                                                                            
          wordIndex++;                                                                                                                                                               
          temp = "";                 
      } else {                                                                                                                                                                       
          temp += currentPrefix[i];  
      }
  }
  currentWords[wordIndex] = temp;

    for(int i = 0; i<numWords-order; i++){
        string newWord = getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix);
        if(newWord == ""){
            break;
        }
        result = result + " " + newWord;
        for(int j = 0; j < order-1; j++){
            currentWords[j] = currentWords[j + 1];
        }
        currentWords[order - 1] = newWord;
        currentPrefix = joinWords(currentWords, 0, order);
    }
    return result;

    }

