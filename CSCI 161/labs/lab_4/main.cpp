#include "growing_array.h"
#include <iostream>
#include <array>
using namespace std;


int main()
{
	GrowingArray gRay;
	gRay.insert(3);
	gRay.insert(4);
	
	GrowingArray eRay(4);
	eRay.insert(3);
	eRay.insert(4);

	if (gRay == eRay)
		cout << "equal" << endl;
	else 
		cout << "not equal" << endl;

	gRay.insert(4);
	gRay.insert(4);
	eRay.insert(4);
	eRay.insert(4);
	
	if (gRay == eRay)
		cout << "equal" << endl;
	else 
		cout << "not equal" << endl;

	cout << gRay.get_size() << endl;
	gRay.show();

	return 0;
}
