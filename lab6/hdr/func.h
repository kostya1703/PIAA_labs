#ifndef func_h
#define func_h

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <clocale>





using namespace std;
using std::wstring;


struct Bohr{
    size_t parent; //parent - вершина-отец в дереве
    int suff_link; //suff_link - суф ссылка
    int suff_flink; //suff_flink - "хорошая" суф. ссылка
    bool flag; //flag — бит, указывающий на то, является ли наша вершина исходной строкой
    wchar_t symb; //символ на ребре от parent к этой вершине
    map<wchar_t,int> nextV; //nextV[i] — номер вершины, в которую мы придем по символу с номером i в алфавите
    vector<int> N_pattern; //N_pattern — номер строки-образца, обозначаемого этой вершиной
    map<wchar_t,int> auto_move; //auto_move - запоминание перехода автомата
};

Bohr makeBohr(int p, wchar_t c);
void initBohr();
void addstrBohr(const wstring& s, vector<wstring>& pattern);
int getAuto_move(size_t v, wchar_t ch);
int get_Suff_link(size_t v);
int get_Suff_flink(size_t v);
void stand_check(size_t v,int i,const vector<wstring>& pattern, map<int,vector<int>>& answ);
void joker_check(size_t v,int i,vector<int>& count, const vector<int>& spliter);
void stand_find_all_pos(const wstring& s,const vector<wstring>& pattern, map<int,vector<int>>& answ);
void joker_find_all_pos(const wstring& s,vector<int>& count, const vector<int>& spliter);
vector<int> split(wstringstream& str_pat, wchar_t razd, vector<wstring>& pattern);
vector<int> getPos(const vector<int>& count, int endd, int pattern_size);

#endif

