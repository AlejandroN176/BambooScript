#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

#include "LexAnalyzer.h"

int main() {
    ifstream lexemes("lexemes.txt");
    ifstream source("source.txt");
    ofstream sourcelexemes("sourcelexemes.txt");
    LexAnalyzer lexanalyzer(lexemes);
    lexanalyzer.scanFile(source, sourcelexemes);
    return 0;
}