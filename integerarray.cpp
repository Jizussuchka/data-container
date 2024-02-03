#include "integerarray.h"
#include <iostream>



using namespace std;


class bad_lenght : public exception {
public:
	int _lenght;
	bad_lenght(const int& lenght) : _lenght(lenght) {};
	virtual const char* what() const noexcept override {
		return "Ошибка связанная с длинной массива!";
	}
};

class bad_range : public exception {
public:
	int _range, _max;
	bad_range(const int& range, const int& max) : _range(range), _max(max) {};
	virtual const char* what() const noexcept override {
		return "Ошибка Выход за пределы!";
	}
};

class bad_find : public exception {
public:
	bad_find() {};
	virtual const char* what() const noexcept override {
		return "Ошибка Элемент не найден!";
	}
};

integerarray::integerarray(const int& size) {
	if (size > 0) {
		this->_max_size = size;
		this->_arr = new int[size];
		for (int i = 0; i < this->_max_size; ++i) {
			this->_arr[i] = 0;
		}
		cout << "integerarray создан успешно" << endl;
	}
	else {

		throw bad_lenght(size);
	}
}

integerarray::integerarray(const integerarray& arr) {
	this->_max_size = arr._max_size;
	this->_arr = new int[arr._max_size];
	for (int i = 0; i < this->_max_size; ++i) {
		this->_arr[i] = arr._arr[i];
	}
}

int& integerarray::at(const int& index) {
	if (index >= 0 && index < this->_max_size) {
		return (this->_arr)[index];
	}
	else {
		bad_range b(index, this->_max_size);
		throw b;
	}

}


void integerarray::change_size(const int& new_size) {
	if (new_size >= this->_max_size && new_size > 0) {
		int* new_arr = new int[new_size];
		for (int i = 0; i <= this->_max_size; i++) {
			new_arr[i] = (this->_arr)[i];
		}

		for (int i = this->_max_size; i < new_size; ++i) {
			new_arr[i] = 0;
		}

		delete[] this->_arr;
		this->_arr = new_arr;
		this->_max_size = new_size;
	}
	else {
		throw bad_range(this->_max_size, new_size);
	}
}

void integerarray::push_back(const int& elem) {
	int* new_arr = new int[_max_size + 1];

	new_arr[_max_size] = elem;
	for (int i = 0; i < _max_size; ++i) {
		new_arr[i] = this->_arr[i];
	}

	delete[] this->_arr;
	++this->_max_size;
	this->_arr = new_arr;
}

void integerarray::push_up(const int& elem) {
	int* new_arr = new int[_max_size + 1];
	int temp = elem;
	for (int i = 0; i < _max_size; ++i) {
		swap(temp, this->_arr[i]);
		swap(this->_arr[i], new_arr[i]);
	}
	new_arr[_max_size] = temp;
	delete[] this->_arr;
	++this->_max_size;
	this->_arr = new_arr;
}

void integerarray::delete_elem(const int& index) {
	if (this->_max_size > index && index >= 0) {
		int ch = 0;
		int* new_arr = new int[(this->_max_size)];
		for (int i = 0; i < this->_max_size; ++i) {
			if (i != index) {
				new_arr[i + ch] = this->_arr[i];
			}
			else {
				--ch;
			}
		}
		delete[] this->_arr;
		this->_arr = new_arr;
		--(this->_max_size);
	}
	else {

		throw bad_range(index, this->_max_size);
	}
}

int integerarray::find(const int& elem) {
	int index = -1;
	for (int i = 0; i < this->_max_size; ++i) {
		if (elem == this->_arr[i]) {
			index = i;
		}
	}
	if (index != -1) {
		return index;
	}
	throw bad_find();
}

void integerarray::print_arr() {
	cout << "[";
	for (int i = 0; i < this->_max_size; ++i) {
		cout << " " << this->_arr[i] << " ";
	}
	cout << "]" << endl;
}

integerarray::~integerarray() {
	cout << "Удаление integerarray" << endl;
	delete[] this->_arr;
}