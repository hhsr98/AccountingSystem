#define _CRT_SECURE_NO_WARNINGS
#pragma once
//#include <json/json.h>
class Shop {
	double longitude, latitude;
	enum OnlineShop{
		JingDong,
		Taobao,
		Amazon,
		eBuy,
		Other
	};
	bool isOnline;
	string Country, Province, City, District, Shopname;
	void getPlace() {
		latitude = 0.0;
		longitude = 0.0;
	}
public:
	//Shop() { getPlace(); }
	Shop(string s) {
		Shopname = s;
	}
	string getShopName() {
		return Shopname;
	}
};
