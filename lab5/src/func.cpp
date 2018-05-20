#include "../hdr/func.h"


using namespace std;


vector<int> naive(const string& target, const string& pattern, int& count){
    vector<int> results;
    for(size_t i=0; i < target.size()-pattern.size()+1;i++){
        for(size_t j=0; j < pattern.size();j++){
            count++;
            if(pattern[j]==target[i+j]){
                if(j==pattern.size()-1)
                    results.push_back(i);
            }
            else
                break;
        }
    }
    return results;
}

vector<int> preKMP(const string& pattern){
    size_t n = pattern.size();
    vector<int> f(n);
    for (size_t i=1; i<n; ++i){
        size_t j = f[i-1];
        while ((j > 0) && (pattern[i] != pattern[j]))
            j = f[j-1];
        if (pattern[i] == pattern[j])
            ++j;
        f[i] = j;
     }
     return f;
}





vector<int> KMP(const string& pattern,const string& target,int& count){

    vector<int> results;
    vector<int> f=preKMP(pattern);

    size_t j=0;
    preKMP(pattern);
    for (size_t i=0; i<target.size(); ++i){
        while ((j > 0) && target[i] != pattern[j]){
            j = f[j-1];
        }
        if (target[i] == pattern[j])
            ++j;
        if (j==pattern.size())
            results.push_back(i-j+1);
            count++;

    }
    if(results.size())
    return results;
    else {
    results.push_back(-1);
    return results;
    }
}

int SHIFT(const string& str1, const string& str2){
    if(str1.size()!=str2.size()){
        return -1;
    }
    int count=0;
    vector<int> result=KMP(str2,str1+str1,count);
    return result[0];
}


