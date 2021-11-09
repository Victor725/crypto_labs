#include<iostream>
#include<string>
using namespace std;

string s_t;
int a[26]={0};

void filter(string message){
    for(int i=0;i<message.length();i++){
        if(message[i]>=97&&message[i]<=122){
            if(a[message[i]-'a']==0){//not added
                a[message[i]-'a']=1;
                s_t.push_back(message[i]);
            }
        }
    }
    for(int i=0;i<26;i++){ //add the remaining ones
        if(a[i]==0){
            s_t.push_back('a'+i);
        }
    }
}

string encode(string message){
    string en_message;
    for(int i=0;i<message.length();i++){
        if( message[i]>=97&&message[i]<=122 ){
            en_message.push_back(s_t[(int)(message[i]-'a')]);
        }
        if(message[i]==' ') en_message.push_back(' ');
    }
    return en_message;
}

int main(){
    string message;
    cout<<"input your key:"<<endl;
    getline(cin,message,'\n');
    filter(message);
    cout<<"the full table is:  "<<s_t<<endl;

    cout<<"input your information to be encoded:"<<endl;
    getline(cin,message,'\n');
    string en_message=encode(message);
    cout<<"encoded information:"<<endl<<en_message<<endl;
}