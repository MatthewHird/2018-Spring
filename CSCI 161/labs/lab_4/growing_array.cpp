#include "growing_array.h"
#include <iostream>
#include <array>
using namespace std;


GrowingArray::GrowingArray(){
	count = 0;
	size = 2;
	g_array = new int[size];
}

GrowingArray::GrowingArray(int in_size){
	count = 0;
	size = in_size;
	g_array = new int[size];
}

GrowingArray::~GrowingArray(){
	delete []g_array;
}

void GrowingArray::insert(double entry){
	if (count == size) {
		int * temp = new int[size * 2];
		for (int i = 0; i < count; i++) {
			temp[i] = g_array[i];
		}
		size = size * 2;
		delete []g_array;
		g_array = temp;
	}
	g_array[count] = entry;
	count++;
	return;
}

void GrowingArray::show(){
	for (int i = 0; i < count; i++) {
    	cout << ' ' << g_array[i];
	}
	cout << endl;
	return;
}

int GrowingArray::get_size(){
	return size;
}

bool GrowingArray::operator==(const GrowingArray& other){
	if (size != other.size){
		return 0;
	}
	for (int i = 0; i < size; i++) {
		if (g_array[i] != other.g_array[i]) {
			return 0;
		}
	}
	return 1;
}
