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
	bool Display(ostream& out)const;//排序结果以console进行输出
	bool Display(ofstream& out)const;//排序结果保存在文本文件中
	bool insertSort();
	bool selectSort();
	bool mergeSort();
private:
	vector<T1> v;
	bool merge(int p, int q, int r);
	bool submergeSort(int, int);
};
#endif
