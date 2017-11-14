#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	bool flag;
	int n;
	string s,tmp="";
	cin>>s>>flag>>n;
	if(!flag){
		for(int i=0;i<s.length();++i)tmp+=tolower(s[i]);
		s=tmp;
	}
	while(n--){
		string str;
		cin>>str;
		tmp=str;
		if(!flag){
			tmp="";
			for(int i=0;i<str.length();++i)tmp+=tolower(str[i]);
			swap(str,tmp);
		}
		if(str.find(s)!=string::npos)cout<<tmp<<endl;
	}
	return 0;
}
