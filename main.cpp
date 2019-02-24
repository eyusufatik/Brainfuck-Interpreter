#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    int array[30000];
    int index = 0;

    string bfCode;
    string line;
    ifstream file;
    file.open(argv[1]);
    while(getline(file,line)){
        bfCode+=line;
    }

    int i=0;
    while(i<bfCode.size()){
        if(bfCode[i]=='>'){
            index++;
            i++;
        }else if(bfCode[i]=='<'){
            if(index>0){
                index--;
                i++;
            }
        }else if(bfCode[i]=='+'){
            array[index]++;
            i++;
        }else if(bfCode[i]=='-'){
            if(array[index]>0){
                array[index]--;
            }
            i++;
        }else if(bfCode[i]=='['){
            i++;
        }else if(bfCode[i]==']'){
            if(array[index]!=0){
                int loop = 1;
                while(loop>0){
                    i--;
                    if(bfCode[i]==']'){
                        loop++;
                    }else if(bfCode[i]=='['){
                        loop--;
                    }
                }
            }else{
                i++;
            }
        }else if(bfCode[i]=='.'){
            cout<<"print: "<<(char)array[index]<<endl;
            i++;
        }else if(bfCode[i]==','){
            char in;
            cin>>in;
            array[index] = (int)in;
            i++;
        }else{
            i++;
        }
        //cout<<i<<" ";
    }

    /*for(int i=0; i<bfCode.size(); i++){
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
            //cout<<nestLevel<<" ";
        }else if(bfCode[i]==']' && array[index]>0){
            if(array[index]!=0){
                i=nestStartIndex[nestLevel];
            }else{
                nestLevel--;
            }
            //cout<<nestLevel<<" ";
        }else if(bfCode[i]=='.'){
            cout<<(char)array[index];
        }else if(bfCode[i]==','){
            char in;
            cin>>in;
            array[index] = (int)in;
        }
    }*/
    cout<<endl;
    return 0;
}