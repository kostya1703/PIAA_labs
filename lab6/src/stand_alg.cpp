#include "../hdr/func.h"


int main(){

    string text, pat;
    int n;
    cin>>text>>n;
    vector<string> pattern;
    initBohr();
    for(int i=0; i<n; i++){
        cin>>pat;
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
