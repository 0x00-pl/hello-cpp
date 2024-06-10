#include<iostream>
//#include<map>
//#include<vector>
using namespace std;
//
//#if 0
//#include"huffman.h"
//#endif
//#if 0
//template<typename T>
//class aptr{
//public:
//	aptr(){ ptr=0; }
//	aptr(T* pointer){ ptr=pointer; }
//	~aptr(){ delete ptr; }
//	T& point(T* pointer){ 
//		delete ptr;
//		ptr= pointer;
//		return get();
//	}
//	bool isnil(){ return !ptr; }
//	T* move(){
//		T* ret= ptr;
//		ptr= 0;
//		return ret;
//	}
//	T& get(){ return *ptr; }
//	T* operator->(){ return ptr; }
//
//private:
//	aptr(const aptr&);
//	void operator=(const aptr&);
//	T* ptr;
//};
//
//
//int f_add1(aptr<int> a){ 
//	if(1==0){
//		return ++a.get();
//	}else{
//		int r;
//		r= a.get()+1;
//		return r;
//	}
//}
//
//template<class T>
//class tail{
//public:
//	static T call(tail<T>* func__will_delete){
//		T ret;
//		return tail::call(ret, func__will_delete); 
//	}
//	static T& call(T& pret, tail<T>* func__will_delete){
//		if(func__will_delete==0) return pret;
//		tail<T>* pnext= func__will_delete;
//		while(pnext){
//			func__will_delete= pnext;
//			pnext= pnext->impl(pret);
//			delete func__will_delete;
//		}
//		return pret;
//	}
//
//	virtual ~tail(){}
//	virtual tail<T>* impl(T& pret){return 0;}
//};
//
//class test: public tail<float>{
//public:
//	int n;
//	float last;
//	test(int _n){last=1; n=_n;}
//	test(float _last, int _n){last=_last; n=_n;}
//	test* impl(float& ret){
//		if(n<=1){ret=last; return 0;}
//		return new test(last*n, n-1);
//	}
//};
//
//class fibonacci:public tail<int>{
//public:
//	int a,b,index,ito;
//	fibonacci(int to){ a=b=index=1; ito=to; }
//	fibonacci(int _a, int _b, int _index, int to){
//		a=_a;
//		b=_b;
//		index=_index;
//		ito=to; 
//	}
//
//	fibonacci* impl(int& ret){
//		if(index>=ito){ret= b; return 0;}
//		return new fibonacci(b,a+b,index+1,ito);
//	}
//};
//
//
//class search_root:public tail<float>{
//public:
//	static const float tolerance;
//	float(*func)(float);
//	float l,h;
//	static bool close_enough(float a, float b){
//		return abs(a-b) < tolerance;
//	}
//	search_root(float(*f)(float), float a, float b):func(f){l=min(a,b);h=max(a,b);}
//	search_root* impl(float& ret){
//		float adv= (l+h)/2;
//		if(close_enough(l,h)){ ret= adv; return 0; }
//		float over_z= func(adv);
//		if(over_z>0){
//			return new search_root(func,l,adv);
//		}
//		return new search_root(func,adv,h);
//	}
//};
//const float search_root::tolerance= 0.00001;
//
//class  fixed_point:public tail<float>{
//public:
//	static const float tolerance;
//	float(*func)(float);
//	float guess;
//	static bool close_enough(float a, float b){
//		return abs(a-b) < tolerance;
//	}
//	fixed_point(float(*f)(float), float _guess):func(f),guess(_guess){}
//	fixed_point* impl(float& ret){
//		float iter_next= func(guess);
//		if(close_enough(iter_next,guess)){ ret= iter_next; return 0; }
//		return new fixed_point(func,iter_next);
//	}
//};
//const float fixed_point::tolerance= 0.00001;
//
//float my_func_sinx_add_cosx(float x){
//	return sin(x)+cos(x);
//}
//float my_func_as(float x){
//	return 1+1/x;
//}
//float my_func_asd(float x){
//	return (x*x*x-2*x)-3;
//}
//template<typename T>
//class base_b{
//public:
//	T t;
//};
//
//template<template<typename> class T>
//class my_c{
//public:
//	T<int> t;
//};
//
//namespace 不能被继承的类{
//	template<typename T>
//	class un_base;
//	template<typename T>
//	class un_base_I:public T{
//		friend un_base<T>;
//	private:
//		un_base_I(){}
//	};
//	template<typename T>
//	class un_base:virtual public un_base_I<T>{
//	public:
//		un_base(){}
//	};
//
//	class my_class{public: int a,b,c;};
//
//	class my_err_test:public un_base<my_class>{};//ERROR
//	void main() {
//		un_base<my_class> oc;//OK
//	}
//}
//struct hasintmember{int a,b,c;};
//
//
//
////针对类中某一对象比较'<'
//template<class V, class T>
//struct lt_pred{
//	lt_pred(V T::*_pm){pm=_pm;}
//	V T::*pm;
//	bool operator()(const T& a, const T& b){
//		return a.*pm < b.*pm;
//	}
//};
//
//template<class V, class T>
//lt_pred<V,T> create_lt_pred(V T::*pm){//自动推倒参数用
//	return lt_pred<V,T>(pm);
//}
//
////sort(ha,ha+3, create_lt_pred(&hasintmember::a));
//
//
//template<
//	template<class _Ty,
//		class _Ax = allocator<_Ty> >  class TT1>
//class t1st{
//public:
//	TT1<int> val;
//};
//class GRO{
//public:
//	GRO(){is_void= true;}
//	~GRO(){if(is_void)cout<<"void: GRO()"<<endl;}
//	
//	template<class T>
//	operator T(){
//		is_void= false;
//		cout<<typeid(T).name()<<": GRO()"<<endl;
//		return T();
//	}
//	bool is_void;
//};
//#endif
//
//#if 0
//
//template<typename T>
//class node{
//public:
//	static int glb_cnt;
//	node(T&& val):value(val){
//		next=prev=0;
//		++glb_cnt;
//	}
//	node(const T& val):value(val){
//		next=prev=0;
//		++glb_cnt;
//	}
//	~node(){
//		if(prev)prev->next= 0;
//		delete next;//delete 0 is safe
//		next= 0;
//		--glb_cnt;
//	}
//
//	void set_val(const T& val){
//		value= val;
//	}
//	const T& get_val(){
//		return value;
//	}
//
//	node<T>* head(){
//		node<T>* ret;
//		for(ret= this; ret->prev != 0; ret= ret->prev) ;
//		return ret;
//	}
//	node<T>* back(){
//		node<T>* ret;
//		for(ret= this; ret->next != 0; ret= ret->next) ;
//		return ret;
//	}
//
//	node<T>* link_next(node<T>* _next){
//		if(_next->head()!= _next) return 0;// _next is not head
//		delete next;
//		next= _next;
//		_next->prev= this;
//		return next;
//	}
//	node<T>* link_prev(node<T>* _prev){
//		if(head()!= this) return 0;// this is not head
//		delete _prev->next;
//		prev->next= this;
//		prev= _prev;
//		return prev;
//	}
//
//public:
//	node<T>* next;
//	node<T>* prev;
//private:
//	friend node<T>;
//	T value;
//};
//
//template<typename T>
//int node<T>::glb_cnt= 0;
//
//int gnnmap[]={0,1,1,2,6,24,120,720};
//
//template<size_t N>
//void fmap(size_t index, int (&nset)[N], int (&outset)[N]){
//	for(size_t i=0; i<N; i++){
//		size_t ap= gnnmap[N-i];
//		size_t cn= index/ap;
//		outset[i]= nset[cn];
//		index%= ap;
//
//		//避免重复数字
//		for(int j=0; j<N-cn-1; ++j) nset[cn+j]=nset[cn+j+1];
//	}
//
//}
//#endif
//
//class magic{
//public:
//	static magic* create(){
//		return encode(new magic);
//	}
//	int& get_val(){
//		magic* real_ptr= decode(this);
//		return real_ptr->val;
//	}
//	void operator delete(void* p){
//		::delete decode(static_cast<magic*>(p));
//	}
//private:
//	friend magic;
//	static magic* encode(magic* p){return _2ptr(_2int(p)^magic_num);}
//	static magic* decode(magic* p){return encode(p);}
//	static int _2int(magic* p){return *(int*)&p;}
//	static magic* _2ptr(int i){return *(magic**)&i;}
//	const static int magic_num= 0x42424242;
//	int val;
//};
//
//#define pl_foreach(from, to, iter) for(auto iter=from; iter!=to; ++iter)
//
//int f_bd(int user_sum, int obj_sum, int* user_data){
//	map<float,int> data;
//	int diff=0;
//	float mini= 0.00001;
//	pl_foreach(0,user_sum,userid_i){
//		pl_foreach(0,user_data[userid_i],curpos_i){
//			data[(float)curpos_i/user_data[userid_i]+mini*diff]= userid_i;
//			++diff;
//		}
//	}
//	vector<int> last_pos(user_sum);
//	pl_foreach(0, user_sum,i)
//		last_pos[i]= -1;
//	int ret_sum=0;
//	int pos=0;
//	pl_foreach(data.begin(), data.end(),i){
//		if(last_pos[i->second]!=-1) 
//			ret_sum+= pos - last_pos[i->second];
//		last_pos[i->second]= pos;
//		++pos;
//	}
//	return ret_sum;
//}
//
//void booting(){
//	int n,m;
//	cin>>n>>m;
//	int* ud= new int[m];
//	pl_foreach(0,m,i)
//		cin>>ud[i];
//	cout<<f_bd(m,n,ud);
//	delete[]ud;
//}
//
//int inputn(){
// int res;
// printf("输入数值入栈, 输入-1出栈: ");
// scanf("%d",&res);
// return res;
//}
//
//void stackf(){
// int n;
// while((n=inputn()) != -1){
//  printf("%d入栈\n",n);
//  stackf();
//  printf("%d出栈\n",n);
// }
//}


//#include"testpattern.c"

void main3(){
	//main2();
	//stackf();
/*
	int ud[3]={3,3,2};
	cout<<f_bd(3,8,ud);*/

	//magic* m= new magic;
	////m->get_val()= 10; //ERROR!

	//magic* cm= magic::create();

	//cm->get_val()= 42;
	//cout<<cm->get_val();

	//delete cm;
	system("pause");
}
//END