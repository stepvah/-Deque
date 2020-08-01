//#include "test_runner.h"

#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;


template <typename T>
class Deque {
public:
	Deque() {
		end_vector = {};
		begin_vector = {};
	}

	bool Empty() const {
		return begin_vector.empty() && end_vector.empty();
	}

	size_t Size() const {
		return begin_vector.size() + end_vector.size();
	}

	T& operator[](size_t ind) {
		if (ind < begin_vector.size()) {
			return begin_vector[begin_vector.size() - ind - 1];
		}
		ind -= begin_vector.size();
		return end_vector[ind];
	}

	const T& operator[](size_t ind) const {
		if (ind < begin_vector.size()) {
			return begin_vector[begin_vector.size() - ind - 1];
		}
		ind -= begin_vector.size();
		return end_vector[ind];
	}

	const T& At(size_t ind) const{
		if (ind >= begin_vector.size() + end_vector.size()) {
			throw out_of_range("deq index out of range");
		}
		if (ind < begin_vector.size()) {
			return begin_vector[begin_vector.size() - ind - 1];
		}
		ind -= begin_vector.size();
		return end_vector[ind];
	}

	T& At(size_t ind) {
		if (ind >= begin_vector.size() + end_vector.size()) {
			throw out_of_range("deq index out of range");
		}
		if (ind < begin_vector.size()) {
			return begin_vector[begin_vector.size() - ind - 1];
		}
		ind -= begin_vector.size();
		return end_vector[ind];
	}

	const T& Front() const{
		return At(0);
	}

	const T& Back() const{
		return At(begin_vector.size() + end_vector.size() - 1);
	}

	T& Front() {
		return At(0);
	}

	T& Back() {
		return At(begin_vector.size() + end_vector.size() - 1);
	}

	void PushBack(T element) {
		end_vector.push_back(element);
	}

	void PushFront(T element) {
		begin_vector.push_back(element);
	}
private:
	vector<T> end_vector;
	vector<T> begin_vector;
};


//void TestDeque() {
//	Deque<int> a;
//	ASSERT(a.Empty());
//	a.PushBack(1);
//	ASSERT(!a.Empty());
//
//	a.PushFront(2);
//	ASSERT_EQUAL(2, a.Front());
//	ASSERT_EQUAL(2, a[0]);
//	ASSERT_EQUAL(1, a.Back());
//}


void TestAll() {
	//TestRunner tr;
	//RUN_TEST(tr, TestDeque);
}


int main() {
	TestAll();
	Deque<int> d1;
	d1.PushFront(2);
	d1.PushFront(1);
	d1.PushBack(3);
	d1.PushBack(4);
	cout << d1[2] << endl;
	cout << d1[3] << endl;
	cout << d1[0] << endl;
	cout << d1[1] << endl;
}