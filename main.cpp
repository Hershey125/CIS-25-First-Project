#include "markov.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    std::string testWords[] = {"the", "cat", "sat", "down"};
    std::cout << joinWords(testWords, 0, 2) << std::endl;  // Should print: the cat
    std::cout << joinWords(testWords, 1, 3) << std::endl;  // Should print: cat sat down

}