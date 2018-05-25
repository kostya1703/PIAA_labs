#include <iostream>
#include "../hdr/func.h"


using namespace std;

double summ(vector<double> array, int index)
{
if(index){
    return array[index] + summ(array, index-1);
}
else{
    return array[index];
}
}

int getIndex(vector<double> values)
{
    double random = (rand()%100);

    for(unsigned int i=0;i<values.size();++i)
    {
        if (random <=values[i])
        return i;

    }
return 0;
}


char myRand(std::string arr, vector<double> freq)
{
vector <double> values;
int i=0;
for(auto &fr: freq)
{
   values.push_back(summ(freq, i));
   i++;
}
    int index = getIndex(values);
    return arr[index];
}

string RandString(int size){
    std::string arr="abcdefghijklmnopqrstuvwxyz";
    std::string result = "";
    vector<double>freq  = {8.167, 1.492, 2.782, 4.253,12.702,2.228,2.015,6.094,6.966,0.153,0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,2.758,0.978,2.360,0.150,1.974,0.074};

    srand(time(NULL));
    for(int i=0;i<size;i++){
    result+=myRand(arr, freq);
    }
    return result;
    }



int main(){
    srand(time(NULL));
    vector<string> texts(3);
    for(int i=0;i<3;i++){
        texts[i]=RandString(10000);
    }
    vector<string> temps(300);
    for(int i=0;i<3;i++){
        for(int j=0;j<100;j++){
            temps[j+i*100]=RandString(10);
        }
    }
    int counter=0;
    for(int i=0; i<3;i++){
        for(int j=0;j<100;j++){
            int count1=0,count2=0;
            vector<int> index1=KMP(texts[i],temps[j+i],count1);
            vector<int> index2=naive(texts[i],temps[j+i*100],count2);
            if(count1+temps[j+i*100].size()<count2)
                counter++;
        }
    }
    cout<<"Длина шаблона 100-200 символов.Длина текста 50000-150000 символов.\n";
    cout<<"Кол-во случаев, в которых алгоритм КМП сработал за меньшее число операций "<<counter<<" из 300\n";
    return 0;
}
