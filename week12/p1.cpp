/*
CH-231-A
a12_p1.cpp
Timofei Podkorytov
tpodkoryto@jacobs-university.de
tpodkoryto@constructor.university
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//=============================================================================
//my custom split function for the input
vector<int> split(string input, char sep){
    int i=0;
    string subStr="";//initial string is empty
    vector<int> out;
    while(i<(int)input.size()){//go through all elements
        if(input[i]==sep){//found the separator
            out.push_back(stoi(subStr));
            subStr="";
        }else{
            subStr+=(input[i]);//add elements
        }
        i++;
    }
    //put the last element in
    out.push_back(stoi(subStr));
    return out;

}
//=============================================================================
int main(){
    string inp;
    getline(cin,inp);//input
    vector<int> array=split(inp, ' ');//we get the array with ints
    int n=array.size();
    //here starts the algorithm
    vector<int> prev(n,-1);//previous elements
    vector<int> len(n,1);//how many elements in a sequence
    vector<int> out;
    int maxLen=0;//maximum length
    int maxInd=-1;
    //here we find the optimal solution for each element O(n^2)
    for(int el=1;el<n;el++){
        /*we search for first elements that is smaller* and has most
         predecossors in its sequence*/
        for(int i=0;i<el;i++){
            if((array[i]<array[el])&&(len[i]+1>=len[el])){
                len[el]=len[i]+1;//we update value
                prev[el]=i;
            }
        }
        //here we save the end of the longest sequence
        if(len[el]>maxLen){
            maxLen=len[el];
            maxInd=el;
        }
    }
    //we form the maximum sequence based on indicies we saved O(n)
    int current=maxInd;
    while(current!=-1){
        out.push_back(array[current]);//we put the element into output
        current=prev[current];
    }
    //we print the output O(n)
    for(int i=out.size()-1;i>-1;i-- ){
        cout<< out[i]<<" ";
    }
    cout<<endl;
    return 0;
}