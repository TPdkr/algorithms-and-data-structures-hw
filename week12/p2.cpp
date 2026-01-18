/*
CH-231-A
a12_p2.cpp
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
    string a;//for input
    vector<vector<int>> triangle;//our data
    vector<vector<int>> path;//for dynamic programing
    int rows=0;//number of rows
    //the input part 
    do{
        getline(cin,a);//input
        if(a!=""){
            triangle.push_back(split(a,' '));
            rows+=1;
        }
    } while(a!="");
    //the main algorithm is here
    vector<int> rowAcc;//row accumulator
    rowAcc.push_back(triangle[0][0]);//1st element
    path.push_back(rowAcc);
    for(int row=1; row<rows;row++){
        rowAcc.clear();
        for(int col=0;col<=row;col++){
            int mx;
            if(col==0){//corner cases
                mx=path[row-1][col];
            } else if(col==row){
                mx=path[row-1][col-1];
            //middle elements can be compared
            } else if(path[row-1][col]>path[row-1][col-1]){
                mx=path[row-1][col];
            } else{
                mx=path[row-1][col-1];
            }
            rowAcc.push_back(mx+triangle[row][col]);
        }
        path.push_back(rowAcc);

    }
    //this is for printing the data if needed
    /*for(int row=0; row<rows;row++){
        for(int col=0;col<=row;col++){
            cout<< path[row][col]<< " ";
        }
        cout<<"\n";

    }*/
    //we find the maximum path length and end spot
    int mx=path[rows-1][0];
    int mxIdx=0;
    for(int i=1;i<rows;i++){
        if(path[rows-1][i]>mx){
            mx=path[rows-1][i];
            mxIdx=i;
        }
    }
    int current=mx;//current value accumulated
    vector<int> outPath;//for output
    outPath.push_back(triangle[rows-1][mxIdx]);
    //we search the path backwards
    for(int row=rows-1; row>0;row--){
        current-=triangle[row][mxIdx];
        if((mxIdx>0)&&(current==path[row-1][mxIdx-1])){
            mxIdx-=1;
        }
        outPath.push_back(triangle[row-1][mxIdx]);
    }
    //outPath printing as well as maximum
    cout<<mx<< endl;
    for(int i=outPath.size()-1;i>-1;i--){
        cout << outPath[i]<< " ";
    }
    cout<< endl;
    return 0;
}