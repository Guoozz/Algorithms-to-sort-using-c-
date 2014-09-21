#ifndef SORT_H
#define SORT_H
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
template <class T1>
class sort
{
public:
	sort(const vector<T1>&);
	const sort<T1>& Display(ostream& out)const;
	bool insertSort();
	bool selectSort();
	bool mergeSort(int,int);
	bool print_to_file(ofstream&)const;
private:
	vector<T1> v;
	bool merge(int p, int q, int r);
};
#endif
