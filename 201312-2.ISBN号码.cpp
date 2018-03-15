#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	string str;
	int res=0;
	cin>>str;
	for(int cnt=1,i=0;i<str.length()-1;++i){
		if(str[i]=='-')continue;
		res+=(str[i]-'0')*cnt;
		++cnt;
	}
	int check=str[str.length()-1]-'0';
	res%=11;
	if(res==check||(res==10&&str[str.length()-1]=='X'))cout<<"Right";
	else{ 
		cout<<str.substr(0,str.length()-1);
		if(res==10)cout<<'X';
		else cout<<res;
	}
	return 0;
}
