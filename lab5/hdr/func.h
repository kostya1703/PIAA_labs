#ifndef func_h
#define func_h


#include <string>
#include <vector>

using namespace std;

vector<int> preKMP(const string& temp);
vector<int>KMP(const string& text, const string& temp, int& count);
int SHIFT(const string& str1, const string& str2);
vector<int> naive(const string& text, const string& temp, int& count);

#endif
