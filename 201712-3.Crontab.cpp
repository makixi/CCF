#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
char vMon[][4] = { "","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec" };
char vWek[][4] = { "sun","mon","tue","wed","thu","fri","sat" };
int mtharray[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
map<string, int> mMon, mWek;
map<string, string> mrt;
int stoi_x(const string &str) {
	int len = str.size();
	int ans = 0;
	for (int i = 0; i<len; ++i) ans = ans * 10 + str[i] - '0';
	return ans;
}
string to_string_x(int n) {
	if (n == 0) return "0";
	string ans;
	while (n != 0) {
		ans += '0' + n % 10;
		n /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
void tostandard(string &str) {
	int len = str.size();
	for (int i = 0; i<len; ++i)str[i] = tolower(str[i]);
}
bool isleapyear(int y) {
	return (y % 4 == 0 && y % 100) || y % 400 == 0;
}
vector<string> splitStringAndbuildVector(string &str, int TAG) {
	str += ',';
	vector<string> res;
	size_t found = str.find(",");
	while (found != string::npos) {
		string x = str.substr(0, found);
		str = str.substr(found + 1, str.size() - found - 1);
		size_t fdx = x.find("-");
		if (fdx == string::npos) {//������ֵ
			if (TAG == 1 && isalpha(x[0]))x = to_string_x(mMon[x]);
			if (TAG == 2 && isalpha(x[0]))x = to_string_x(mWek[x]);
			if (x.size() == 1)x = "0" + x;
			res.push_back(x);
		}
		else {//����ֵ
			string L = x.substr(0, fdx), R = x.substr(fdx + 1, x.size() - fdx - 1);
			int left, right;
			if (TAG == 0)left = stoi_x(L), right = stoi_x(R);
			else if (TAG == 1) {
				left = (isalpha(L[0])) ? mMon[L] : stoi_x(L);
				right = (isalpha(R[0])) ? mMon[R] : stoi_x(R);
			}
			else if (TAG == 2) {
				left = (isalpha(L[0])) ? mWek[L] : stoi_x(L);
				right = (isalpha(R[0])) ? mWek[R] : stoi_x(R);
			}
			while (left <= right) {
				string num = to_string_x(left);
				if (num.size() == 1)num = "0" + num;
				res.push_back(num);
				++left;
			}
		}
		found = str.find(",");
	}
	return res;
}
string getWeekday(string year, string month, string day) {
	int y = stoi_x(year), m = stoi_x(month), d = stoi_x(day);
	if (isleapyear(y)) mtharray[2] = 29;
	else mtharray[2] = 28;
	int by = 1970, countday = 0;
	while (by<y) {
		countday += (isleapyear(by)) ? 366 : 365;
		++by;
	}
	for (int i = 1; i<m; ++i) countday += mtharray[i];
	countday += d - 1;
	return "0" + to_string_x((4 + countday % 7) % 7);
}
int main() {
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 12; ++i) mMon[vMon[i]] = i;
	for (int i = 0; i <= 6; ++i) mWek[vWek[i]] = i;
	int n;
	string st, et;
	cin >> n >> st >> et;
	string syy = st.substr(0, 4), smm = st.substr(4, 2), sdd = st.substr(6, 2), sHH = st.substr(8, 2), sMM = st.substr(10, 2);
	string eyy = et.substr(0, 4), emm = et.substr(4, 2), edd = et.substr(6, 2), eHH = et.substr(8, 2), eMM = et.substr(10, 2);
	int syInt = stoi_x(syy), eyInt = stoi_x(eyy);
	while (n--) {
		vector<string> vmts, vhur, vdfm, vmth, vdfw;
		string minutes, hours, dofmon, month, dofwek, command;
		cin >> minutes >> hours >> dofmon >> month >> dofwek >> command;
		tostandard(month);//�������Сд��ת��Ϊ��׼Сд 
		tostandard(dofwek);//�������Сд��ת��Ϊ��׼Сд 
		if (minutes == "*") minutes = "0-59";
		vmts = splitStringAndbuildVector(minutes, 0);//Ӧ��ִ�еķ��� 
		if (hours == "*") hours = "0-23";
		vhur = splitStringAndbuildVector(hours, 0); //Ӧ��ִ�е�Сʱ
		if (dofmon == "*") dofmon = "1-31";
		vdfm = splitStringAndbuildVector(dofmon, 0);//Ӧ��ִ�е��� 
		if (month == "*") month = "1-12";
		vmth = splitStringAndbuildVector(month, 1);//Ӧ��ִ�е��·� 
		if (dofwek == "*") dofwek = "0-6";
		vdfw = splitStringAndbuildVector(dofwek, 2);//Ӧ���ܼ�ִ�� 
		set<string> wekexist;
		for (size_t i = 0; i<vdfw.size(); ++i) wekexist.insert(vdfw[i]);//����ļ�����ǰ���ڣ�dayofweek���ǲ���Ӧ��ִ�� 
		int curyear = syInt;//�ӿ�ʼ���ִ�� 
		while (curyear <= eyInt) {
			if (isleapyear(curyear)) mtharray[2] = 29;//leapyear��2�·�Ӧ����29�� 
			else mtharray[2] = 28;
			string year = to_string_x(curyear);//��� 
			for (size_t mi = 0; mi<vmth.size(); mi++) {//month
				string curm = vmth[mi];//��ǰ�·� 
				for (size_t di = 0; di<vdfm.size(); di++) {//day of month
					string curd = vdfm[di];//��ǰ���� 
					string wd = getWeekday(year, curm, curd);//���꣬���£����������ڼ� 
					if (wekexist.count(wd) == 0 || stoi_x(curd)>mtharray[stoi_x(curm)])continue;//�������в����������ڻ��ߵ�ǰ����������ǰ�·ݵ�Ӧ������ʱ 
					for (size_t Hi = 0; Hi<vhur.size(); ++Hi)//hour
						for (size_t Mi = 0; Mi<vmts.size(); ++Mi) {//minutes
							string datetime = year + curm + curd + vhur[Hi] + vmts[Mi];
							if (datetime >= st && datetime<et) mrt[datetime] = command;//�ڵ�ǰ����ʱ���� 
						}
				}
			}
			++curyear;//������һ�� 
		}
	}
	for (map<string, string>::iterator it = mrt.begin(); it != mrt.end(); ++it)
		cout << it->first << " " << it->second << endl;
	return 0;
}

