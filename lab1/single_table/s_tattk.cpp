#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

double alpha_map[26]={0};
int count_of_letters=0;
unordered_map<char,char> map;

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

string try_decode(string message,char original,char new_one){
    map[original]=new_one;
    string true_message;
    for(int i=0;i<message.length();i++){
        if(message[i]==original){
            true_message.push_back(new_one);
        }
        else{
            true_message.push_back(message[i]);
        }
    }
    return true_message;
}

void print_map(){
    cout<<"the map is:"<<endl;
    for(int i='A';i<='Z';i++){
        cout<<map[i];
    }
    cout<<endl;
}

int main(){
    string message;
    cout<<"please input a message:"<<endl;
    getline(cin,message,'\n');
    eval_letters_count(message);
    cout<<count_of_letters<<endl;
    cout<<"----------frequency----------"<<endl;
    cal_and_show();
    cout<<endl;
    cout<<"Now,you can start decoding it. Please input your map:"<<endl;
    char original,new_one;
    char opt=0;
    string true_message=message;
    while(1){
        cin>>original>>new_one;
        true_message=try_decode(true_message,original,new_one);
        cout<<true_message<<endl;
        cout<<"is it correct?(y/n):";
        cin>>opt;
        if(opt=='y'){
            print_map();
            cout<<"the true message is:"<<endl<<true_message<<endl;
            break;
        }
    }
}