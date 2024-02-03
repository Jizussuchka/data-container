#pragma once
#include <exception>

using namespace std;





class integerarray {
public:
	integerarray(const int& size);
	integerarray(const integerarray& arr);
	int& at(const int& index);
	void change_size(const int& new_size);
	void push_back(const int& elem);
	void push_up(const int& elem);
	void delete_elem(const int& index);
	int find(const int& elem);
	void print_arr();
	~integerarray();
private:
	int* _arr;
	int _max_size = 0;

};
