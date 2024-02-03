#include <iostream>
#include <Windows.h>
#include "integerarray.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	// обработка некоректного расширения
	try {
		integerarray arr(3);
		arr.print_arr();
		arr.change_size(1);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	cout << "--------" << endl;
	// обработка некоректного индекса
	try {
		integerarray arr(2);
		arr.print_arr();
		arr.at(5);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	cout << "--------" << endl;
	// обработка некоректной длины массива
	try {
		integerarray arr(-6);
		arr.print_arr();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	cout << "--------" << endl;
	try {
		integerarray arr(3);
		arr.print_arr();
		arr.find(20);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	cout << "--------" << endl;
	// Конструктор копирования
	try {
		integerarray arr(3);
		arr.print_arr();
		arr.push_up(2);
		arr.print_arr();
		integerarray arr2(arr);
		arr2.print_arr();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

}