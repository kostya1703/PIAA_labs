#ifndef func_h
#define func_h

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>


using namespace std;

struct Bohr{
    int parent; //parent - вершина-отец 
    int suff_link; //suff_link - суф. ссылка
    int suff_flink; //suff_flink - "хорошая" суф. ссылка
    bool flag; //flag — указывает является ли наша вершина исходной строкой
    char symb; //символ на ребре от отца к этой вершине
    map<char,int> nextV; //nextV[i] — номер вершины, в которую мы придем по символу с номером i в алфавите
    vector<int> N_pattern; //N_pattern номер строки-образца, обозначаемого вершиной
    map<char,int> auto_move; //auto_move - запоминание перехода автомата
};

Bohr makeBohr(int p, char c);
void initBohr();
void addstrBohr(const string& s, vector<string>& pattern);
int getAuto_move(int v, char ch);
int get_Suff_link(int v);
int get_Suff_flink(int v);
void stand_check(int v,int i,const vector<string>& pattern, map<int,vector<int>>& answ);
void joker_check(int v,int i,vector<int>& count, const vector<int>& lenght);
void stand_find_all_pos(const string& s,const vector<string>& pattern, map<int,vector<int>>& answ);
void joker_find_all_pos(const string& s,vector<int>& count, const vector<int>& lenght);
vector<int> split(stringstream& str_pat, char razd, vector<string>& pattern);
vector<int> getPos(const vector<int>& count, int stopper, int pattern_size);

#endif
