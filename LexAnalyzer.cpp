#include "LexAnalyzer.h"
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
                cout << "Added: " << lexeme << " -> " << token << endl;
        }


}

// pre: 1st parameter refers to an open text file that contains source
// code in the language, 2nd parameter refers to an open empty output
// file
// post: If no error, the token and lexeme pairs for the given input
// file have been written to the output file (token : lexeme).
// If there is an error, the incomplete token/lexeme pairs, as well as
// an error message have been written to the output file.
// A success or fail message has printed to the console.
void LexAnalyzer::scanFile(istream& infile, ostream& outfile) {
        string word;
        string builder;
        string symbol;
        bool assigning = false;
        while (infile >> word) {
                if (tokenmap.find(word) != tokenmap.end()){
                        outfile << tokenmap[word] << " : " << word << endl;
                }
                else {
                        for(int i = 0; i < word.length(); i++) {
                                char currentChar = word.at(i);
                                if (isalpha(currentChar) || currentChar == '_'  || (assigning == false && isdigit(currentChar))){
                                        builder += word.at(i);
                                        //delete this later
                                        cout << word.at(i) << endl;
                                }
                                else if (currentChar == '=' ) {
                                        //First sees = then checks if its actually ==
                                        if (i+1 < word.length() && word.at(i + 1) == '=') {
                                                symbol = "==";
                                        }
                                        else {
                                                symbol = "=";
                                                assigning = true;
                                        }
                                        cout << symbol << endl;
                                        outfile << tokenmap[symbol] << " : " << symbol << endl;

                                }
                                else if (currentChar == '"') {
                                        // we need to be able to get the text within "" without creating another for loop
                                        // we just need whatever is inside doesnt matter what so no need to check
                                        }
                                else {
                                        //this runs when a symbol get found and adds the word builder then the symbol and reiterates to the next word
                                        symbol = currentChar;
                                        if (!builder.empty())
                                                outfile << tokenmap[builder] << " : " << builder << endl;
                                        outfile << tokenmap[symbol] << " : " << symbol << endl;
                                        builder = "";
                                }
                        }
                }
        }
}
