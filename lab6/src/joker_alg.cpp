#include "../hdr/func.h"


int main(){
    string text, pat;
    char jok;
    cin>>text>>pat>>jok;
    stringstream str_pat(pat);
    vector<string> pattern; //вектор для частей шаблона
    initBohr();
    vector<int> spliter = split(str_pat, jok, pattern);//места, где части шаблона заканчиваются в самом шаблоне
    vector<int> count(text.size(),0);
    joker_find_all_pos(text, count, spliter);

    int t=text.size()-pat.size()+1;
    int p_s=pattern.size();
    for(int i=0;i<t;i++){
        if(count[i]==p_s)
            cout<<i+1<<"\n";
    }

    return 0;
}
