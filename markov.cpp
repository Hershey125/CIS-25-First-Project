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
