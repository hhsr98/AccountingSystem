#include "../inc/Analize.h"
#include <string>
#include <sstream>
using namespace std;
double AnalizeVal::getreal() {
	return this->real;
}
double AnalizeVal::getperc() {
	return this->perc;
}
void AnalizeVal::setreal(double x) {
	this->real = x;
}
void AnalizeVal::setperc(double x) {
	this->perc = x;
}
void Analize::addDateStrict(Date a, Date b)
{
	this->filter = new dateFilter(this->filter,a,b);
}
void Analize::addPriceStrict(SingleMoney a, SingleMoney b)
{
	this->filter = new priceFilter(this->filter, a, b);
}
void Analize::makeList()
{
	list = new List(filter);
}
AnalizeByDate::AnalizeByDate(DisplayImp* display, TimeLen* t)
{
	this->t = t;
}
void AnalizeByDate::startAnalize()
{
	static char ts[50];
	if (*t == TimeLen(0, 1, 0, 0))
	{
		/*for (auto i : list->vec_commodity)
		{
			Date t = i->Date();
			stringstream ss;
			ss << t.year << t.month;
			string s = ss.str();
			mp[s] = mp[s] + i->TotalPrice();
		}*/
	}
}