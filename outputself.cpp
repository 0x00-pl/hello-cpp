char* code="#include<iostream>\n\
#include<string>\n\
using namespace std;\n\
string escape(string s){\n\
	string ret;\n\
	ret+=\"\\\"\";\n\
	for(int i=0; i<s.size(); ++i) switch(s[i]){\n\
	case '\\':\n\
		ret+='\\';\n\
		ret+='\\';\n\
		break;\n\
	case '\n':\n\
		ret+=\"\\\\n\\\\\\n\";\n\
		break;\n\
	case '\"':\n\
		ret+='\\';\n\
		ret+='\"';\n\
		break;\n\
	default:\n\
		ret+=s[i];\n\
	}\n\
	ret+=\"\\\"\";\n\
	return ret;\n\
}\n\
void main(){\n\
	cout<<\"char* code=\";\n\
	cout<<escape(code)<<';'<<endl;\n\
	cout<<code<<endl;\n\
}";

#include<iostream>
#include<string>
using namespace std;
string escape(string s){
	string ret;
	ret+="\"";
	for(int i=0; i<s.size(); ++i) switch(s[i]){
	case '\\':
		ret+='\\';
		ret+='\\';
		break;
	case '\n':
		ret+="\\n\\\n";
		break;
	case '"':
		ret+='\\';
		ret+='"';
		break;
	default:
		ret+=s[i];
	}
	ret+="\"";
	return ret;
}
void main(){
	cout<<"char* code=";
	cout<<escape(code)<<";"<<endl;
	cout<<code<<endl;
	system("pause");
}