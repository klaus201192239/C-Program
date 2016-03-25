#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
int tell(string s){
	for(int i=0;i<s.length();i++){
		if(s[i]!=' '){
			return 0;
		}
	}
	return 1;
}
int main()
{
	//定义阶段
	string ch[29]={"#","bgin","if","then","wile","do","end","777777","888888","9999999","letter","dight","12121221","+","-","*","/",":",":=","19191919",
		"<","{}","<=",">",">=","=",";","(",")"};
	char getstring[100];
	string letter[100];
	string dig[100];
	string str="                    ";
	string S;
	int arr[200]={0};
	int count=0;
	int le=0;
	int di=0;
	int temp;
	ostringstream os;
	//定义阶段
	cin>>getstring;
	S.assign(getstring);
	do{
		for(int i=0;i<29;i++){
			if(S.find(ch[i],0)!=string::npos){
				if(ch[i].compare(":")==0&&S[S.find(ch[i],0)+1]=='='){
					arr[S.find(ch[i],0)]=i+1;
					S.replace(S.find(ch[i],0),2,str,0,2);
				}
				else if(ch[i].compare("<")==0&&S[S.find(ch[i],0)+1]=='='){
					arr[S.find(ch[i],0)]=i+2;
					S.replace(S.find(ch[i],0),2,str,0,2);
				}
				else if(ch[i].compare(">")==0&&S[S.find(ch[i],0)+1]=='='){
					arr[S.find(ch[i],0)]=i+1;
					S.replace(S.find(ch[i],0),2,str,0,2);
				}
				else{
					arr[S.find(ch[i],0)]=i;
					S.replace(S.find(ch[i],0),ch[i].length(),str,0,ch[i].length());
				}
			}
		}
		for(int i=0;i<29;i++){
			if(S.find(ch[i],0)==string::npos){
				count++;
			}
		}
		if(count!=29){count=0;}
	}while(count!=29);
	for(int i=0;i<S.length();i++){
		if(((S[i]<='z')&&(S[i]>='a'))||((S[i]<='Z')&&(S[i]>='A'))){
			arr[i]=le+30;
			temp=i;
			while(S[i]!=' '){
				i++;
			}
			letter[le].append(S,temp,i-temp);
			S.replace(temp,i-temp,str,0,i-temp);
			le++;
		}
		if(((S[i]<='9')&&(S[i]>='0'))){
			temp=i;
			arr[i]=di+200;
			while(S[i]!=' '&&(S[i]<='9')&&(S[i]>='0')){
				i++;
			}
			dig[di].append(S,temp,i-temp);
			S.replace(temp,i-temp,str,0,i-temp);
			di++;
		}
	}
	for(int i=0;i<200;i++){
		if(arr[i]!=0){
			if(arr[i]>=30){
				if(arr[i]>=200){
					cout<<"(";
					os<<dig[arr[i]-200];
					cout<<os.str();
					cout<<"     11)"<<endl;
				}
				else{
					cout<<"(";
					os<<letter[arr[i]-30];
					cout<<os.str();
					cout<<"     10)"<<endl;
				}
			}
			else{
				cout<<"(";
				os<<ch[arr[i]];
				cout<<os.str();
				cout<<"     "<<arr[i]<<")"<<endl;
			}
		}
	}
	/*for(int i=0;i<S.length();i++){
		cout<<S[i];
	}
	cout<<endl;*/
	system("pause");
	return 0;
}

