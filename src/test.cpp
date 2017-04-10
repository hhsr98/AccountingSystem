#include "../inc/date.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
using namespace std;
int main()
{
	Date a;
	TimeLen b(0, 3, 29, 15);
	cout << a << endl;
	cout << b << endl;
	cout << (a - b) << endl;
}