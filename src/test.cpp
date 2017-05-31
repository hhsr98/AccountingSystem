#include "../inc/date.h"
#include "../inc/Unit.h"
#include "../inc/Shop.h"
#include "../inc/Analize.h"
#include "../inc/Shop.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <sstream>
using namespace std;
AnalizeByDate* a;
int main()
{
	Date t = Date(1, 1, 0, 0);
	stringstream ss;
	ss << t.year <<" "<< t.month;
	string s = ss.str();
	cout << s << endl;
	//cout << a.getperc() << endl;
	system("pause");
	/*double mass=1;
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
    cout<<volume<<mass_unit<<endl;*/
}
