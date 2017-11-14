#include<iostream>
#include<map>
#include<vector>
#include<windows.h>
#include<string>
using namespace std;
int isRepeat(map<string,string> m,string s){
	map<string,string>::iterator it;
	it = m.find(s);
	if(it == m.end())return 0;
   	return 1;
}
int find(string str,char c){
    int flag = str.find(c);
	if(flag != -1)  // 该命令存在 
		if(flag < str.length()-1 && str.at(flag+1) == ':')return 2;   //  有参数 
		else return 1;  // 无参数 
    return 0;  //命令不存在 
}
int main(){
    string str;
    int i,j,n;
    cin>>str;
    cin>>n;
    getchar();
    for(i = 0; i < n; i++){
        vector<string> v;
        map<string,string> m;
        string op;
        getline(cin,op);
        string line = op;
        int t; 
        for(t = line.find(" "); t != -1; t = line.find(" ")){
            v.push_back(line.substr(0,t));
            line = line.substr(t+1);
        }
        v.push_back(line);
        vector<string>::iterator it;
        for(it = v.begin()+1; it != v.end(); it++){ 
            string ss = *it;
            if(ss.at(0) == '-' && ss.length() == 2 && find(str,ss.at(1))){
                if(find(str,ss.at(1)) == 1)m.insert(pair<string,string>(ss,"null"));
                else if(find(str,ss.at(1)) == 2 && ++it != v.end()){
					if(isRepeat(m,ss))m[ss] = *it;   //修改key对应的值
					else m.insert(pair<string,string>(ss,*it));  
                }else break;
            }else break;
        }
        cout<<"Case "<<i+1<<":"; 
        map<string,string>::iterator itr;
        for(itr = m.begin(); itr != m.end(); itr++)
            if(itr->second != "null")cout<<" "<<itr->first<<" "<<itr->second;
            else cout<<" "<<itr->first;
        cout<<endl;
    }
    return 0;
}
