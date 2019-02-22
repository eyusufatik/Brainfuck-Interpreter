#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int array[10000];
    int index = 0;
    int startIndex[100];
    int nestLevel = -1;
    string input;
    cin>>input;
    for(int i=0;i<input.size();i++){
        if(input[i]=='>'){
            index++;
        }else if(input[i]=='<'){
            index--;
        }else if(input[i]=='+'){
            array[index]++;
        }else if(input[i]=='-'){
            array[index]--;
        }else if(input[i]=='['){
            nestLevel++;
            startIndex[nestLevel] = i+1;
        }else if(input[i]==']'){
            if(array[index]!=0){
                i = startIndex[nestLevel]-1;
            }else{
                nestLevel--;
            }
        }else if(input[i]=='.'){
            cout<<(char)array[index];
        }else if(input[i]==','){
            char in;
            cin>>in;
            array[index] = (int)in;
        }
    }
    cout<<endl;
    return 0;
}