#include <iostream>
#include "../hdr/func.h"

using namespace std;

int main(){

string pattern;
string target;
cin>>pattern;
cin>>target;
int count=0;
vector<int> results=KMP(pattern,target,count);

    for(const auto& el: results){
        cout<<el;
        if(el!=results[results.size()-1])
            cout<<",";
}
cout<<"\n";
}

