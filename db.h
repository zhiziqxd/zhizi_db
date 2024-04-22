#ifndef db_H
#define db_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;
struct db{
	int ans;
	vector<string> text;
	vector<int> number;
}db[20];//°æ±¾¿â
string password;
int ku;
void init(){
	freopen("db.in","r",stdin);
	cin>>ku>>password;
	for(int i=0;i<password.length();i++){
		password[i]+=2;
	}
	for(int i=1;i<=ku;i++){
		cin>>db[i].ans;
		for(int j=1;j<=db[i].ans;j++){
			short int l;
			cin>>l;
			if(l==1){
				string str;
				cin>>str;
				db[i].text.push_back(str);
			}
			else{
				int a;
				cin>>a;
				db[i].number.push_back(a);
			}
		}
	}
	freopen("CON","r",stdin);
}
void db_find(int k,bool x,string txt,int n){
	int cnt=1;
	if(x==true){
		if(k==0){
			for(int i=1;i<=ku;i++){
				for(int j=1;j<=db[i].text.size();j++){
					string flag=db[i].text[j];
					if(flag.find(txt)<=flag.length()){
						cout<<cnt<<"."<<flag<<endl;
						cnt++;
					}
				}
			}
		}
		else{
			for(int i=1;i<=db[i].text.size();i++){
				
			}
		}
	}
}
#endif
