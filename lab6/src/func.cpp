#include "../hdr/func.h"

vector<Bohr> bohr;

Bohr makeBohr(int p, char c){ //Функции создания новой вершины и инициализации бора
    Bohr b;
    b.parent = p; //передаем номер отца и символ на ребре в бор
    b.symb = c;
    b.flag = false;
    b.nextV[c]=b.auto_move[c]=-1;
    b.suff_link = -1; //изначально - суф. ссылки нет
    b.suff_flink = -1;
    return b;
}

void initBohr(){
    bohr.clear();
    bohr.push_back(makeBohr(0,'$'));
}

void addstrBohr(const string& s, vector<string>& pattern){ //Процедура добавление строки-образца в бор
    int num = 0;
    for (size_t i = 0; i < s.length(); ++i){
        char ch = s[i];
        if(bohr[num].nextV.find(ch)==bohr[num].nextV.end() || bohr[num].nextV[ch]==-1){
            bohr.push_back(makeBohr(num, ch));
            bohr[num].nextV[ch] = bohr.size() - 1;
        }
        num=bohr[num].nextV[ch];
    }
    bohr[num].flag = true;
    pattern.push_back(s);
    bohr[num].N_pattern.push_back(pattern.size() - 1);
}

int get_Suff_link(int b){
    if (bohr[b].suff_link == -1){ //если еще не считали
        if (b == 0 || bohr[b].parent == 0) //если v - корень или предок v - корень
            bohr[b].suff_link = 0;
        else
            bohr[b].suff_link=getAuto_move(get_Suff_link(bohr[b].parent), bohr[b].symb);
    }
    return bohr[b].suff_link;
}

int getAuto_move(int b, char ch){
    if (bohr[b].auto_move.find(ch)==bohr[b].auto_move.end() || bohr[b].auto_move[ch]==-1){
        if (bohr[b].nextV.find(ch)!=bohr[b].nextV.end() && bohr[b].nextV[ch]!=-1)
            bohr[b].auto_move[ch] = bohr[b].nextV[ch];
        else{
            if (b == 0)
                bohr[b].auto_move[ch] = 0;
            else
                bohr[b].auto_move[ch]=getAuto_move(get_Suff_link(b), ch);
        }
    }
    return bohr[b].auto_move[ch];
}

int get_Suff_flink(int b){
    if (bohr[b].suff_flink == -1) {
        int j = get_Suff_link(b);
        if (j == 0)
            bohr[b].suff_flink = 0;
    else
        bohr[b].suff_flink = (bohr[j].flag) ? j : get_Suff_flink(j);
    }
    return bohr[b].suff_flink;
}

void stand_check(int b,int i,const vector<string>& pattern, map<int,vector<int>>& answrs){
    for(int j = b; j != 0; j = get_Suff_flink(j)) {
        if (bohr[j].flag){
            answ[i - pattern[bohr[j].N_pattern[0]].size() + 1].push_back(bohr[j].N_pattern[0] + 1);
        }

    }
}



void stand_find_all_pos(const string& s,const vector<string>& pattern, map<int,vector<int>>& answrs){
    int j = 0;
    for(size_t i = 0; i < s.size(); i++) {
        j = getAuto_move(j, s[i]);
        stand_check(j, i+1, pattern, answrs);

    }
}


vector<int> split(stringstream& str_pat, char razd, vector<string>& pattern){
    vector<int> spliter;
    int len=0;
    string tmp;
    while(getline(str_pat,tmp,razd)){
      if(tmp.size()>0){
        len+=tmp.size();
        spliter.push_back(len);
        addstrBohr(tmp, pattern);
      }
      len++;
    }
    return spliter;
}
void joker_check(int b,int i,vector<int>& count, const vector<int>& spliter){
    for(int j = b; j != 0; j = get_Suff_flink(j)){
        if (bohr[j].flag){
            for(const auto& it: bohr[j].N_pattern){
                if((size_t)(i-spliter[it])<count.size()){
                    count[i-spliter[it]]++;
                }
            }
        }
    }
}

void joker_find_all_pos(const string& s,vector<int>& count, const vector<int>& spliter){
    int j = 0;
    for(size_t i = 0; i < s.size(); i++) {
        j = getAuto_move(j, s[i]);
        joker_check(j,i+1,count,spliter);
    }
}


vector<int> getPos(const vector<int>& count, int endd, int pattern_size){
    vector<int> pos;
    for(int i=0;i<stopper;i++){
        if(count[i]==pattern_size)
            pos.push_back(i+1);
    }
    return pos;
}
