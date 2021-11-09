#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int key=0;
string alpha="abcdefghijklmnopqrstuvwxyz";

//try randomly
/*string try_decode(string en_s){ 
    string s;
    key=rand()%26;
    for(int i=0;i<en_s.length();i++){
        if( en_s[i]>=97&&en_s[i]<=122 ){
            s.push_back(alpha[(en_s[i]-'a'-key+26)%26]);
        }
        if(en_s[i]==' ') s.push_back(' ');
    }
    return s;
}*/

string try_decode(string en_s){ //try by order
    string s;
    for(int i=0;i<en_s.length();i++){
        if( en_s[i]>=97&&en_s[i]<=122 ){
            s.push_back(alpha[(en_s[i]-'a'-key+26)%26]);
        }
        if(en_s[i]==' ') s.push_back(' ');
    }
    return s;
}

int main(){
    srand(time(0));
    string en_s,s;
    cout<<"please input encoded s(en_s)"<<endl;
    getline(cin,en_s,'\n');
    char opt;
    while(1){
        key++;
        s=try_decode(en_s);
        cout<<s<<endl;
        cout<<"does it make sense?(y/n):";
        cin>>opt;
        if(opt=='y'){
            cout<<"the key is:"<<key<<endl;
            break;
        }
    }   
}