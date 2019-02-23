#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    int array[10000];
    int index = 5000;
    int nestStartIndex[100];
    int nestLevel = -1;

    string bfCode;
    string line;
    ifstream file;
    file.open(argv[1]);
    while(getline(file,line)){
        bfCode+=line;
    }

    for(int i=0; i<bfCode.size(); i++){
        if(bfCode[i]=='>'){
            index++;
        }else if(bfCode[i]=='<'){
            if(index>0){
                index--;
            }
        }else if(bfCode[i]=='+'){
            array[index]++;
        }else if(bfCode[i]=='-'){
            if(array[index]>0){
                array[index]--;
            }
        }else if(bfCode[i]=='['){
            nestLevel++;
            nestStartIndex[nestLevel] = i;
        }else if(bfCode[i]==']'){
            if(array[index]!=0){
                i=nestStartIndex[nestLevel];
            }else{
                nestLevel--;
            }
        }else if(bfCode[i]=='.'){
            cout<<(char)array[index];
        }else if(bfCode[i]==','){
            char in;
            cin>>in;
            array[index] = (int)in;
        }
        //cout<<nestLevel<<" ";
    }
    cout<<endl;
    return 0;
}