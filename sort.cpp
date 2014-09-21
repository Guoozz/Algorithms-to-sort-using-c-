#include "sort.h"
#include<fstream>

template<class T1>
sort<T1>::sort(const vector<T1>& _v) :v(_v){}
template<class T1>
bool sort<T1>::insertSort(){
	cout << "insert sort result" << endl;
	for (unsigned i = 1; i < v.size(); ++i){
		T1 key = v[i];
		int  j = i - 1;
		for (; j >= 0 &&  key < v[j] ; --j){
			v[j + 1] = v[j];
		}
		v[j+1] = key;
	}
	return true;
}

template<class T1>
bool sort<T1>::selectSort(){
	cout << "select sort result" << endl;
	for ( int i = 0; i != v.size();++i){
		auto min = i;
		auto j = i+1;
		for (; j != v.size(); ++j){
			if (v[j] < v[min])
				min = j;
		}
		auto temp = v[i];
		v[i] = v[min];
		v[min] = temp;
	}
	return true;
}

template<class T1>
bool sort<T1>::mergeSort(int p,int r)
{
	if (p < r){
		int q = (p + r) / 2;
		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
		return true;
	}
	return true;
}

template<class T1>
bool sort<T1>::merge(int p, int q, int r)
{
	vector<T1> v1, v2;
	for (auto i = p; i <= q; ++i){
		v1.push_back(v[i]);
	}
	v1.push_back(0x7fffffff);
	for (auto j = q + 1; j <= r; ++j){
		v2.push_back(v[j]);
	}
	v2.push_back(0x7fffffff);
	auto i = 0, j = 0;
	for (auto k = p; k <= r && i != v1.size() && j != v2.size();  ++k){
		if (v1[i] < v2[j]){
			v[k] = v1[i];
			++i;
		}
		else {
			v[k] = v2[j];
			++j;
		}
	}
	return true;
}

template<class T1>
const sort<T1>& sort<T1>::Display(ostream& out)const
{
	for (auto e : v){
		out << e << ' ';
	}
	out << endl;
	return *this;
}
template<class T1>
bool sort<T1>::print_to_file(ofstream& out)const
{
	for (auto x : v){
		out << x << ' ';
	}
	out << endl;
	return 0;
}

int main()
{
	vector<int> v;
	ifstream in("unsort.txt");
	ofstream out("sorted.txt",ofstream::app);
	int e;
	while (in >> e){
		v.push_back(e);
	}
	sort<int> s(v);
	s.mergeSort(0,v.size());
	s.print_to_file(out);
	cout << "success" << endl;
	system("pause");
	return 0;
}
