#include<iostream>
#include<string>
using namespace std;

int main(){
    string alpha="abcdefghijklmnopqrstuvwxyz";
    int key=0;
    string s,en_s;
    cout<<"please input a key:"<<endl;
    cin>>key;
    getchar();
    cout<<"please input a str:"<<endl;
    getline(cin,s,'\n');
    //cout<<s<<endl;
    for(int i=0;i<s.length();i++){
        if( s[i]>=97&&s[i]<=122 ){
            en_s.push_back(alpha[(s[i]-'a'+key)%26]);
        }
        if(s[i]==' ') en_s.push_back(' ');
    }
    cout<<"result is:"<<endl<<en_s<<endl;
}
