#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

bool verificaID(const string &str);
bool verificaLiteral(const string &str);
bool verificaKeyword(const string &str);
void montagemToken(const vector<string> &tokens);
void run(const string &arquivo);