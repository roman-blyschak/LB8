#pragma once
#include <ctime>
#include <iostream>
using namespace std;

template<typename T>
class Matrix {
private:
	T** arr;
	int weight;
	int height;
public:
	Matrix(int height, int weight);
	~Matrix();
	void Clear();
	void Random();
	void Show();
	int Averge();
	void SetArr(T** arr, int height, int weight);
};

template<typename T>
Matrix<T>::Matrix(int height, int weight)
{
	if (height < 0 || weight < 0)
	{
		throw "Out range exception";
	}
	this->height = height;
	this->weight = weight;
	arr = new T * [height];
	for (int i = 0; i < height; i++) {
		arr[i] = new T[weight];
	}
	Clear();
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < height; i++) {
		delete arr[i];
	}
	delete arr;
}

template<typename T>
void Matrix<T>::Clear()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < weight; j++) {
			arr[i][j] = (T)0;
		}
	}
}

template<typename T>
void Matrix<T>::Random()
{
	srand(time(NULL));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < weight; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}

template<typename T>
void Matrix<T>::Show()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < weight; j++) {
			cout<<arr[i][j] <<"\t";
		}
		cout << endl;
	}
}

template<typename T>
int Matrix<T>::Averge()
{
	double paired = 0;
	double notpaired = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < weight; j++) {
			if ((i*weight+ j)%2 != 0) {
				paired = paired + ((double)arr[i][j])/(0.5*weight*height);
			}
			else {
				notpaired = notpaired + ((double)arr[i][j]) / (0.5 * weight * height);
			}
		}
	}
	if (paired == notpaired) {
		return 0;
	}
	else if(paired> notpaired) {
		return 1;
	}
	else {
		return -1;
	}
}

template<typename T>
void Matrix<T>::SetArr(T** arr, int height, int weight)
{
	if (height < 0 || weight < 0)
	{
		throw "Out range exception";
	}
	for (int i = 0; i < this->height; i++) {
		delete this->arr[i];
	}
	delete this->arr;
	this->height = height;
	this->weight = weight;
	this->arr = new T * [height];
	for (int i = 0; i < height; i++) {
		this->arr[i] = new T[weight];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < weight; j++) {
			this->arr[i][j] = arr[i][j];
		}
	}
}
