#include "../hdr/func.h"


int main(){
    setlocale(LC_ALL, "");
    wstring text, pat;
    int n;
    wcin>>text>>n;
    vector<wstring> pattern;
    initBohr();
    for(int i=0; i<n; i++){
        wcin>>pat;
        addstrBohr(pat, pattern);
    }
    map<int,vector<int>> answrs;
    stand_find_all_pos(text, pattern, answrs);

    for(auto& it: answrs){
        sort(it.second.begin(),it.second.end());
        for(const auto& it_sec: it.second)
        cout<<it.first<<" "<<it_sec<<"\n";
    }
    return 0;
}
