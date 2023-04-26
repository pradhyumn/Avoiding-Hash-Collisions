//HW5 by Pradhyumn Bhale
//SU Net ID: pbhale SUID: 3116245952
//HW5.  Due: Wednesday (November 17) at 11:59pm

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class myCompareClass {
	//For all comparions, compare the sums of all int objects in the structures.


public:

	bool operator()(int* p1, int* p2)  const { //cant make the pointer constant as it will not allow to change through the reference 
		return *p1 < *p2;
	}
		 
	bool operator()(list<set<int*, myCompareClass>*>* p1, list<set<int*, myCompareClass>*>* p2) const {
		int Sum1{ 0 }, Sum2{ 0 };
		for (auto& i : *p1) {
			for (auto& j : *i) {
				Sum1 += *j;
			}
		}
		for (auto& i : *p2) {
			for (auto& j : *i) {
				Sum2 += *j;
			}
		}
		return Sum1 < Sum2;
	}

	bool operator() (const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M1,
		const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M2)  const {
		int Sum1{ 0 }, Sum2{ 0 };
		for (auto& i : M1) {
			for (auto& j : *i.first) {
				for (auto& k : *j) {
					Sum1 += *k;
				}
			}
			for (auto& j : *i.second) {
				Sum1 += *j;
			}
		}
		for (auto& i : M2) {
			for (auto& j : *i.first) {
				for (auto& k : *j) {
					Sum2 += *k;
				}
			}
			for (auto& j : *i.second) {
				Sum2 += *j;
			}
		}
		return Sum1 < Sum2;
	}

};

class myHashEqualClass {
	//For Hashing function use h(sums int in the sturcture), where hash<int> h;
	//For Hasing, the sum = 2*odd numbers + even numbers
public:
	bool operator() (const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M1,
		const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M2)  const {
		int Sum1{ 0 }, Sum2{ 0 };
		for (auto& i : M1) {
			for (auto& j : *i.first) {
				for (auto& k : *j) {
					Sum1 += *k;
				}
			}
			for (auto& j : *i.second) {
				Sum1 += *j;
			}
		}
		for (auto& i : M2) {
			for (auto& j : *i.first) {
				for (auto& k : *j) {
					Sum2 += *k;
				}
			}
			for (auto& j : *i.second) {
				Sum2 += *j;
			}
		}
		return Sum1 == Sum2;
		
	}
	size_t operator()(const map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >& M) const {
		int Sum{ 0 };
		for (auto& i : M) {
			for (auto& j : *i.first) {
				for (auto& k : *j) {
					if (*k % 2 == 0) { Sum += *k; }
					else { Sum += 2 * (*k); }
				}
			}
			for (auto& j : *i.second) {
				if (*j % 2 == 0) { Sum += *j; }
				else { Sum += 2 * (*j); }
			}
		}
		hash<int> h;
		return h(Sum);
	}

};

//The following is a suggestion. You can implement the overloaded operator<< differently.
template <class T> ostream& operator<<(ostream& str, const list<T*>& L);

template <class T> ostream& operator<<(ostream& str, const set<T*, myCompareClass>& S);

template <class T> ostream& operator<<(ostream& str, const vector<T*>& V);

template <class T> ostream& operator<<(ostream& str, const vector<T>& V);

template <class T1, class T2> ostream& operator<<(ostream& str, const map<T1*, T2*, myCompareClass>& M);

template <class T1, class T2> ostream& operator<<(ostream& str, const map<T1, T2, myCompareClass>& M);

template <class T> ostream& operator<<(ostream& str, const set<T, myCompareClass>& S);

template <class T1, class T2> ostream& operator<<(ostream& str, const unordered_map<T1, T2, myHashEqualClass, myHashEqualClass>& M);


int main() {

	set<map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >, myCompareClass> S1{ {{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{13},new int{5},new int{6}},new set<int*,myCompareClass>{new int{4},new int{5},new int{3}},
		new set<int*,myCompareClass>{new int{3},new int{11},new int{9}}},new vector<int*>{new int{4},new int{14},new int{3}}} ,{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{11},new int{15},new int{1}},new set<int*,myCompareClass>{new int{3},new int{8},new int{6}},
		new set<int*,myCompareClass>{new int{7},new int{5},new int{13}}},new vector<int*>{new int{3},new int{12},new int{5}}},{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{3},new int{13},new int{4}},new set<int*,myCompareClass>{new int{2},new int{13},new int{16}},
		new set<int*,myCompareClass>{new int{2},new int{12},new int{5}}},new vector<int*>{new int{5},new int{17},new int{2}}}},{{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{3},new int{5},new int{7}},new set<int*,myCompareClass>{new int{2},new int{5},new int{8}},
		new set<int*,myCompareClass>{new int{3},new int{6},new int{11}}},new vector<int*>{new int{7},new int{13},new int{19}}} ,{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{3},new int{5},new int{17}},new set<int*,myCompareClass>{new int{3},new int{8},new int{5}},
		new set<int*,myCompareClass>{new int{1},new int{3},new int{6}}},new vector<int*>{new int{4},new int{3},new int{14}}},{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{1},new int{13},new int{7}},new set<int*,myCompareClass>{new int{1},new int{15},new int{2}},
		new set<int*,myCompareClass>{new int{6},new int{20},new int{16}}},new vector<int*>{new int{19},new int{5},new int{4}}}},{{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{3},new int{5},new int{7}},new set<int*,myCompareClass>{new int{2},new int{5},new int{8}},
		new set<int*,myCompareClass>{new int{6},new int{11},new int{3}}},new vector<int*>{new int{11},new int{7},new int{3}}} ,{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{17},new int{3},new int{5}},new set<int*,myCompareClass>{new int{3},new int{5},new int{8}},
		new set<int*,myCompareClass>{new int{1},new int{6},new int{3}}},new vector<int*>{new int{14},new int{4},new int{3}}},{new list<set<int*, myCompareClass>*>
		{new set<int*,myCompareClass>{new int{3},new int{5},new int{4}},new set<int*,myCompareClass>{new int{2},new int{5},new int{18}},
		new set<int*,myCompareClass>{new int{2},new int{6},new int{13}}},new vector<int*>{new int{11},new int{5},new int{13}}}} };
	//For each STL container, at least three elements are required.

	int* a{ new int(5) };
	cout << S1 << endl;



	unordered_map< map < list<set<int*, myCompareClass>*>*, vector<int*>*, myCompareClass >, vector<int>, myHashEqualClass, myHashEqualClass> H1{
		{{{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{5},new int{3},new int{7}},new set<int*, myCompareClass>
		{new int{2},new int{8},new int{5}},new set<int*, myCompareClass>{new int{3},new int{11},new int{6}}},new vector<int*>{new int{7},new int{9}, new int{13}}},
		{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{3},new int{17},new int{5}},new set<int*, myCompareClass>
		{new int{3},new int{8},new int{5}},new set<int*, myCompareClass>{new int{1},new int{6},new int{3}}},new vector<int*>{new int{4},new int{14}, new int{3}}},
		{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{1},new int{13},new int{7}},new set<int*, myCompareClass>
		{new int{1},new int{15},new int{2}},new set<int*, myCompareClass>{new int{6},new int{16},new int{20}}},new vector<int*>{new int{5},new int{19}, new int{4}}}},{7,8,9}},
		{{{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{5},new int{13},new int{6}},new set<int*, myCompareClass>
		{new int{3},new int{4},new int{5}},new set<int*, myCompareClass>{new int{3},new int{9},new int{11}}},new vector<int*>{new int{4},new int{14}, new int{3}}},
		{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{5},new int{13},new int{7}},new set<int*, myCompareClass>
		{new int{1},new int{15},new int{11}},new set<int*, myCompareClass>{new int{3},new int{6},new int{8}}},new vector<int*>{new int{5},new int{12}, new int{3}}},
		{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{3},new int{13},new int{4}},new set<int*, myCompareClass>
		{new int{2},new int{12},new int{5}},new set<int*, myCompareClass>{new int{2},new int{16},new int{13}}},new vector<int*>{new int{5},new int{17}, new int{2}}}},{3,5,7}},
		{{{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{3},new int{7},new int{5}},new set<int*, myCompareClass>
		{new int{2},new int{5},new int{8}},new set<int*, myCompareClass>{new int{3},new int{11},new int{6}}},new vector<int*>{new int{7},new int{11}, new int{3}}},
		{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{3},new int{17},new int{5}},new set<int*, myCompareClass>
		{new int{3},new int{8},new int{5}},new set<int*, myCompareClass>{new int{1},new int{3},new int{6}}},new vector<int*>{new int{4},new int{14}, new int{3}}},
		{new list<set<int*, myCompareClass>*>{new set<int*, myCompareClass>{new int{3},new int{4},new int{5}},new set<int*, myCompareClass>
		{new int{2},new int{18},new int{5}},new set<int*, myCompareClass>{new int{2},new int{13},new int{6}}},new vector<int*>{new int{5},new int{11}, new int{13}}}},{1,2,3}}
	};
	//For each STL container, at least three elements are required.

	cout << H1 << endl;

	return 0;
}

template <class T> ostream& operator<<(ostream& str, const list<T*>& L) {
	str << "[";
	for (auto& i : L) {
		str << *i << " ";
	}
	str << "]";
	return str;
}

template <class T> ostream& operator<<(ostream& str, const set<T*, myCompareClass>& S) {
	str << " < ";
	for (auto& i : S) {
		str << *i << " ";
	}
	str << ">";
	return str;
}

template <class T> ostream& operator<<(ostream& str, const vector<T*>& V) {
	str << " ( ";
	for (auto& i : V) {
		str << *i << " ";
	}
	str << ") ";
	return str;
}

template <class T> ostream& operator<<(ostream& str, const vector<T>& V) {
	str << "(";
	for (auto& i : V) {
		str << i << " ";
	}
	str << ")";
	return str;
}

template <class T1, class T2> ostream& operator<<(ostream& str, const map<T1*, T2*, myCompareClass>& M) {
	str << "{  ";
	for (auto& i : M) {
		str << *i.first << " " << *i.second << " ";
	}
	str << "}";
	return str;
}

template <class T1, class T2> ostream& operator<<(ostream& str, const map<T1, T2, myCompareClass>& M) {
	for (auto& i : M) {
		str << i.first << " " << i.second << " ";
	}
	return str;
}

template <class T> ostream& operator<<(ostream& str, const set<T, myCompareClass>& S) {
	str << "<" << endl;
	for (auto& i : S) {
		str << i << " "<<endl;
	}
	str << ">" << endl;
	return str;
}

template <class T1, class T2> ostream& operator<<(ostream& str, const unordered_map<T1, T2, myHashEqualClass, myHashEqualClass>& M) {
	str << "{" << endl;
	for (auto& i : M) {
		str  << i.first << " " << i.second<<endl;
	}
	str << "}" << endl;
	return str;
}

