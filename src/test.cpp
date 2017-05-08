#include "../inc/date.h"
#include "../inc/Unit.h"
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

	double mass=1;
	Unit mass_unit(Unit::kilogram);
    cout<<mass<<mass_unit<<'=';
    mass*=mass_unit.convertTo(Unit::ch_Liang);
    cout<<mass<<mass_unit<<'=';
    mass*=mass_unit.convertTo(Unit::pound);
    cout<<mass<<mass_unit<<endl;
    mass*=mass_unit.convertTo(Unit::kilogram);
    mass*=mass_unit.convertTo(Unit::milliliter);
    cout<<mass<<mass_unit<<endl;
    mass*=mass_unit.convertTo(Unit::no_unit);
    cout<<mass<<mass_unit<<endl;
    mass_unit.setUnit(Unit::liter);
    double &volume=mass;
    cout<<volume<<mass_unit<<endl;
    volume*=mass_unit.convertTo(Unit::us_gallon);
    cout<<volume<<mass_unit<<endl;
    volume*=mass_unit.convertTo(Unit::kilometer);
    cout<<volume<<mass_unit<<endl;


}
