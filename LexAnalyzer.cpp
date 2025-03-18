#include "LexAnalyzer.h"
using namespace std;
// pre: parameter refers to open data file consisting of token and
// lexeme pairs i.e.  s_and and t_begin begin t_int 27
// Each pair appears on its own input line.
// post: tokenmap has been populated - key: lexeme, value: token

LexAnalyzer::LexAnalyzer(istream& infile) {
        if (!infile) {
                cerr << "Error: Failed to open lexemes.txt!" << endl;
                return;
        }
        string token;
        string lexeme;

        while (infile >> token >> lexeme) {
                tokenmap[lexeme] = token;
//                cout << "Added: " << lexeme << " -> " << token << endl;
        }


}

void LexAnalyzer::scanFile(istream& infile, ostream& outfile) {
    string word;
    string builder;
    string symbol;
    while (infile >> word) {
        cout << word;
        if (tokenmap.find(word) != tokenmap.end())
            outfile << tokenmap[word] << " : " << word << endl;
        else {
            for(int i = 0; i < word.length(); i++) {
                builder += word.at(i);
                else if (isdigit(word.at(i))){
                    builder += word.at(i);
                    //put throw exception in here
                    //if word.at(i + 1) is == to a-z
                    //throws an error
                    // a number cannot have letter directly after it
                }else if (word.at(i) == '"'){
                    quotefunc(builder, symbol,word,i,outfile);
                }
                else{
                    if (word.at(i) == '(' || word.at(i) == ')' || word.at(i) == ';' || word.at(i) == '='){
                        appendOutfile(word, builder,symbol, i, outfile);
                        builder = "";
                    }
                }
            }
        }
    }
}


//declares variables at the very beginning
void varDeclaration(string word) {
        string concat= "";
        if (islower(isalpha(word.at(0)))){
               concat += word.at(0);
        }
}


//todo better function name
//for the assignment operator = code
void LexAnalyzer::assignment(string word, int i, string symbol, ostream& outfile) {
    //First sees = then checks if its actually ==
    if (i+1 < word.length() && word.at(i + 1) == '=') {
        symbol = "==";
    }
    else {
        symbol = "=";
    }
    cout << symbol << endl;
    outfile << tokenmap[symbol] << " : " << symbol << endl;
}

//todo better function name
//function for reading inside of double quotes
void LexAnalyzer::quotefunc(string builder,string symbol,string word, int i, ostream& outfile ) {
    if (builder != ""){
        outfile << tokenmap[builder] << " : " << builder << endl;
        builder = "";
    }

    symbol = word.at(i);
    outfile << tokenmap[symbol] << " : " << symbol << endl;
}

//appends to sourcelexemes
void LexAnalyzer::appendOutfile(const string word,const string builder, string symbol, int i, ostream& outfile){
    if (builder != ""){
        outfile << tokenmap[builder] << " : " << builder << endl;
    }
    symbol = word.at(i);
    outfile << tokenmap[symbol] << " : " << symbol << endl;
}