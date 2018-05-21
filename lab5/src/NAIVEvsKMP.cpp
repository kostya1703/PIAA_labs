#include <iostream>
#include "../hdr/func.h"

using namespace std;

string RandString(int size1, int size2){
    string str="";
    int strsize=size2+rand()%size1;
    for(int i=0; i< strsize;i++){
        str+=(char)(rand()%26 +97);
    }
    return str;
}

int main(){
    srand(time(NULL));
    vector<string> texts(3);
    for(int i=0;i<3;i++){
        texts[i]=RandString(100000,50000);
    }
    vector<string> temps(1000);
    for(int i=0;i<3;i++){
        for(int j=0;j<200;j++){
            temps[j+i*200]=RandString(100,100);
        }
    }
    int counter=0;
    for(int i=0; i<3;i++){
        for(int j=0;j<200;j++){
            int count1=0,count2=0;
            vector<int> index1=KMP(texts[i],temps[j+i*2],count1);
            vector<int> index2=naive(texts[i],temps[j+i*200],count2);
            if(count1+temps[j+i*200].size()<count2)
                counter++;
        }
    }
    cout<<"Длина шаблона 100-200 символов.Длина текста 50000-150000 символов.\n";
    cout<<"Кол-во случаев, в которых алгоритм КМП сработал за меньшее число операций "<<counter<<" из 600\n";
    return 0;
}
