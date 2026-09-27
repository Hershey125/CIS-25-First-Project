#include "markov.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    std::string words[1000];
    int count = readWordsFromFile("test.txt", words, 1000);
    std::cout << "Read " << count << " words" << std::endl;
    for (int i = 0; i < 10 && i < count; i++) {
        std::cout << words[i] << std::endl;
}


}