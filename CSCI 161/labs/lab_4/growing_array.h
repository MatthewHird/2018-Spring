#pragma once
#include <iostream>
#include <array>
using namespace std;


class GrowingArray
{
private:
	int count;
	int size;
	int * g_array;

public:
	GrowingArray();
	GrowingArray(int in_size);
	~GrowingArray();

	void insert(double entry);
	void show();
	int get_size();

	bool operator==(const GrowingArray& other);
};
