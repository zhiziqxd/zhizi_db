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
}db[20];//版本库
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
			for(int i=1;i<=db[k].text.size();i++){
				string flag=db[i].text[i];
				if(flag.find(txt)<=flag.length()){
					cout<<cnt<<"."<<flag<<endl;
					cnt++;
				}
			}
		}
	}
	else{
		if(k==0){
			for(int i=1;i<=ku;i++){
				for(int j=1;j<=db[i].number.size();j++){
					int flag=db[i].number[j];
					if(flag==n){
						cout<<cnt<<"."<<flag<<endl;
						cnt++;
					}
				}
			}
		}
		else{
			for(int i=1;i<=db[k].number.size();i++){
				string flag=db[i].number[i];
				if(flag==n){
					cout<<cnt<<"."<<flag<<endl;
					cnt++;
				}
			}
		}
	}
}
void str_del(string str){
	for(int i=db[k].text.begin();i<=db[k].text.end;i++){
		if(db[k].text.find(str)){
			auto f=db[k].text.erase(i);
		}
	}
	return;
}
void add_to(){
	ku++;
	for(int i=1;i<=db[ku-1].text.size();i++){
		db[ku].text.push_back(db[ku-1].text[i]);
	}
	for(int i=1;i<=db[ku-1].number.size();i++){
		db[ku].number.push_back(db[ku-1].number[i]);
	}
	return;
}
void sub_to(){
	db[ku].text.clear();
	db[ku].number.clear();
	ku--;
}
void number_add(int a){
	db[ku].ans++;
	db[ku].number.push_back(a);
}
void str_add(string a){
	db[ku].ans++;
	db[ku].text.push_back(a);
}
void end(){
	freopen("db.in","w",stdout);
	for(int i=0;i<password.length();i++){
		password[i]-+=2;
	}
	cout<<ku<<password<<endl;
	for(int i=1;i<=ku;i++){
		cout<<db[i].ans
		for(int j=1;j<=db[i].ans;j++){
			if(j<=db[i].text.size()){
				cout<<1<<endl<<db[i].text[j]<<endl;
			}
			else{
				cout<<2<<endl<<db[i].number[j]<<endl;
			}
		}
	}
	freopen("CON","w",stdout);
}
#endif
