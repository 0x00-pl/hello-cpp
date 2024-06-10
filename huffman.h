#pragma once
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//以下为辅助类
template<typename T>
class will_delete{
public:
	will_delete(T* ptr){p= ptr;}
	operator T*(){return p;}
	T* operator->(){return p;}
	T* p;
};

template<typename T>
class vtree{
public:
	vtree(){val=0;}
	vtree(will_delete<T> data){val= data;}
	~vtree(){
		for(size_t i=0; i<_list.size(); i++) delete _list[i];
		delete val;
	}
	bool leaf()const{return _list.empty();}
	vector<vtree<T>*> _list;
	T* val;
};
//辅助类结束

struct huffman_node{
	huffman_node(string st, size_t w){s=st;wight=w;}
	string s;
	size_t wight;
};

//辅助函数
bool vtree_huffman_node_ja(vtree<huffman_node>* a, vtree<huffman_node>* b){
	return  a->val->wight > b->val->wight;
}

class huffman_rule{
public:
	huffman_rule(vector<huffman_node>& data){
		for(size_t i=0; i<data.size(); i++)
			encode._list.push_back(new vtree<huffman_node>( new huffman_node(data[i].s,data[i].wight) ));
		while(encode._list.size()> 2){
			sort(encode._list.begin(), encode._list.end(), &vtree_huffman_node_ja);
			vtree<huffman_node>* min1= encode._list.back();
			encode._list.pop_back();
			vtree<huffman_node>* min2= encode._list.back();
			encode._list.pop_back();
			encode._list.push_back(join(min1,min2));
		}
		size_t wight=0;
		switch(encode._list.size()){
		case 2:wight+=encode._list[1]->val->wight;
		case 1:wight+=encode._list[0]->val->wight;
		default:;
		}
		encode.val= new huffman_node("", wight);
	}
	vtree<huffman_node>* join(vtree<huffman_node>* a, vtree<huffman_node>* b){
		vtree<huffman_node>* ret= new vtree<huffman_node>(new huffman_node("",a->val->wight+b->val->wight));
		ret->_list.push_back(a);
		ret->_list.push_back(b);
		return ret;
	}

	vector<bool> find_symbol(vtree<huffman_node>* ptree, string& symbol){
		if(ptree->leaf() && ptree->val->s==symbol) return vector<bool>(); 
	}

	vector<bool> encode_string(const vector<string>& strs){
		vector<bool> ret,temp;
		for(size_t i=0; i< strs.size(); i++){
			temp= _encode_single(encode, strs[i]);
			ret.insert(ret.end(), temp.rbegin(), temp.rend());
		}
		return ret;
	}
	vector<string> decode_bool(vector<bool>& code){
		vector<string> ret;
		vector<bool>::iterator i= code.begin();
		while(i!= code.end()){
			ret.push_back(_decode_single(encode, i, code.end()));
		}
		return ret;
	}

private:
	static vector<bool> _encode_single(const vtree<huffman_node>& obj, const string& str){
		vector<bool> ret;
		if(obj.val->s==str){
			ret.push_back(true);//返回值会被删除 只是表明找到了
			return ret;
		}
		for(size_t i=0; i<obj._list.size(); i++){
			ret= _encode_single(*obj._list[i], str);
			if(ret.size()){
				if(obj._list[i]->leaf()) ret.pop_back();//删除标识已找到的符号
				ret.push_back(i==0?0:1);
				return ret;
			}
		}
		ret.clear();
		return ret;
	}
	static string _decode_single(const vtree<huffman_node>& obj, vector<bool>::iterator& pbit, vector<bool>::iterator pend){
		while(!obj.leaf()){
			bool path= *pbit;
			if(pbit!=pend){
				pbit++;
			}else{
				return "";
			}
			return _decode_single(path==0?*obj._list[0]:*obj._list[1], pbit, pend);
		}
		return obj.val->s;
	}

	vtree<huffman_node> encode;
};


void huffman_main(){
	//初始化用词频率规则
	vector<huffman_node> data;
	data.push_back(huffman_node("a",2));
	data.push_back(huffman_node("na",16));
	data.push_back(huffman_node("boom",1));
	data.push_back(huffman_node("sha",3));
	data.push_back(huffman_node("get",2));
	data.push_back(huffman_node("yip",9));
	data.push_back(huffman_node("job",2));
	data.push_back(huffman_node("wah",1));
	huffman_rule r(data);

	//要加密的字符串
	vector<string> text, out_text;
	text.push_back("na");
	text.push_back("na");
	text.push_back("na");
	text.push_back("boom");
	text.push_back("na");
	text.push_back("na");
	text.push_back("na");
	text.push_back("wah");

	//加密函数
	vector<bool> code= r.encode_string(text);

	//解密函数
	out_text= r.decode_bool(code);
}