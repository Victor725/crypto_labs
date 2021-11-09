#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

double alpha_map[26]={0};
int count_of_letters=0;

void eval_letters_count(string s){
    for(int i=0;i<s.length();i++){
        if( s[i]>=65&&s[i]<=90 ){
            alpha_map[s[i]-'A']++;
            count_of_letters++;
        }
    }
}

void cal_and_show(){
    for(int i=0;i<26;i++){
        alpha_map[i]=alpha_map[i]/count_of_letters;
    }
    int max=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(alpha_map[j]>alpha_map[max]){
                max=j;
            }
        }
        cout<<(char)('A'+max)<<":"<<alpha_map[max]<<endl;
        alpha_map[max]=-1;
        max=0;
    }
}

int main(){
    string message;
    cout<<"please input a message:"<<endl;
    getline(cin,message,'\n');
    eval_letters_count(message);
    cout<<count_of_letters<<endl;
    cout<<"----------frequency----------"<<endl;
    cal_and_show();
}