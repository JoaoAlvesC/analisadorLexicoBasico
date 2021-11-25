#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::vector;

bool verificaID(const string &str)
{
  if (std::isdigit(str[0]))
    return false;
  int counter = 0;
  if (str[0] == '_')
    counter++;

  for (; counter < str.size(); counter++)
    if (!(isalnum(str[counter])))
      return false;

  return true;
}

bool verificaLiteral(const string &str)
{
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool verificaKeyword(const string &str)
{
  const vector<string> keywords{"if", "int", "while",  "float", "(", ")", "{", "}", ";", "+", "-", "/", "*", "=", "=="};
  for (const auto &keyword : keywords)
    if (keyword == str)
      return true;

  return false;
}

bool invalid(const string &str)
{
  return str == " " || str == "\n";
}

void montagemToken(const string &token)
{
  if (verificaKeyword(token))
  {
    cout << "<keyword, " << token << ">\n";
  }
  else if (verificaID(token))
  {
    cout << "<variable, " << token << ">\n";
  }
  else if (verificaLiteral(token))
  {
    cout << "<number, " << token << ">\n";
  }
  else
  {
    int size = token.length();
    for (int i = 0; i < size; i++)
    {
      string s(1, token[i]);
      montagemToken(s);
    }
  }
}

void run(const string &arquivo)
{
  char ch;
  string buffer;
  std::fstream file(arquivo, std::fstream::in);

  if (!file.is_open())
  {
    cout << "Erro ao abrir arquivo\n";
    exit(0);
  }

  while (file >> std::noskipws >> ch)
  {
    if (invalid(string(1, ch)))
    {
      if (!buffer.empty())
      {
        montagemToken(buffer);
        buffer = "";
      }
      continue;
    }

    buffer += ch;
  }
  file.close();
}
