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

        while (infile >> word) {
                if (tokenmap.find(word) != tokenmap.end()){
                        outfile << tokenmap[word] << " : " << word << endl;
                } else {
                        outfile << "ERROR: Unrecognized lexeme '" << word << "'" << endl;
                }
        }
}
