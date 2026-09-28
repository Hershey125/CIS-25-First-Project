#include "markov.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string filename;
int order;
int maxOutputWords;



int main(){
    int orderinput = 0;
    srand(time(0)); //what is this?

    cout << "Enter input filename: ";
    cin >> filename;
    bool y = true;
    while(y){
        cout<< "Please enter the order #: ";
        cin >> orderinput;
        
        if(cin.fail()){
            cout<<"Pleaes enter an integer, we cannot take strings" << endl;
            cin.clear();
            cin.ignore(1000000, '\n');
        }else if(orderinput == 1 || orderinput == 2 || orderinput ==3){
            order = orderinput;
            y = false;
        }else{
            cout << "The order has to be one of the following options: 1,2,3. Please try again and choose one of the three " << endl;
        }
    }
    bool z = true;

    while(z){
        cout << "Enter maximum number of words to generate: ";
        cin >> maxOutputWords;

        if(cin.fail()){
            cout << "Please enter an integer." << endl;

            cin.clear();
            cin.ignore(1000000, '\n');
        }
        else if(maxOutputWords < order){
            cout << "The number of words must be at least " << order << "." << endl;
        }
        else{
            z = false;
        }
    }
    const int MAX_WORDS = 5000;

    string words[MAX_WORDS];
    string prefixes[MAX_WORDS];
    string suffixes[MAX_WORDS];

    int count = readWordsFromFile(filename, words, MAX_WORDS);

    if(count == -1){
        cout << "Error: Could not open the file, did you put a virus in there?" << endl;
        return 0;
    }

    if(count <= order){
        cout << "You need at least " << order + 1 << " words in the file for this order." << endl;
        return 0;
    }

    if(count == MAX_WORDS){
        cout << "Only the first " << MAX_WORDS << " words were used. Any additional words were ignored." << endl;
    }

    int chainSize = buildMarkovChain(words,count,order,prefixes,suffixes,MAX_WORDS);

    if(chainSize <= 0){
        cout<< "ERROR, we could not build the markov chain, 0 prefix and suffix pairs were created from your file" << endl;
        return 0;
    }

    string output = generateText(prefixes,suffixes,chainSize,order,maxOutputWords);

    int generatedwords = 0;
    if(output != ""){
        generatedwords ++;
        for(int i =0; i<output.length(); i++){
            if(output[i] == ' '){
                generatedwords ++;
            }
        }
    }
    cout << endl; cout<<output<< endl; cout << endl;
    cout << "Generated " << generatedwords << " of at most "<< maxOutputWords << " words." << endl;

    if(generatedwords < maxOutputWords){
    cout << "Generation stopped early because the chain reached a dead end."<< endl;
    }


    return 0;
}




