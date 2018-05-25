#include<iostream>
#include<string>
#include<vector>

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


int main()
{
    std::string arr="abcdefghijklmnopqrstuvwxyz";
    std::string result = "";

       vector<double>freq  = {8.167, 1.492, 2.782, 4.253,12.702,2.228,2.015,6.094,6.966,0.153,0.772,4.025,2.406,6.749,7.507,1.929,0.095,5.987,6.327,9.056,2.758,0.978,2.360,0.150,1.974,0.074};

    srand(time(NULL));
     for (int i = 0; i < 10000; i++)
     result+=myRand(arr, freq);

    std::string str = "abcdefghijklmnopqrstuvwxyz";
    for(int j=0;j<str.length();++j){
    char checkCharacter = str[j];
    double count = 0;
    for (unsigned int z = 0; z < result.size(); z++)
    {
        if (result[z] == checkCharacter)
        {
            ++ count;
        }
    }
    double r=(count*100)/10000;
    cout << "Number of " << checkCharacter << " = " <<r<<"%"<<endl ;
   }
    return 0;
}
