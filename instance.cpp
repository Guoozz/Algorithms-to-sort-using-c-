#include"sort.cpp"
#include"sort.h"
int main()
{
	vector<int> v;
	ifstream in("unsort.txt");
	ofstream out("sorted.txt", ofstream::app);
	int e;
	while (in >> e){
		v.push_back(e);
	}
	sort<int> s(v);
	s.mergeSort();
	s.Display(out);//根据参数的不同进行重载
	cout << "success" << endl;
	system("pause");
	return 0;
}
