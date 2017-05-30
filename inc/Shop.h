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
	void getPlace(string C,string P,string CI,string D) {
		system("python location.py");
		FILE *fp = fopen('locate.txt', 'r');
		static char s[50];
		if(C.length()) 
			Country = C;
		else 
			fscanf()
		else 
		Province = P;
		District = D;
		City = CI;
		latitude = 0.0;
		longitude = 0.0;
	}
public:
	//Shop() { getPlace(); }
	Shop(string s, string C = string(),string P = string(), string CI =string(), string D = string()) {
		getPlace(C,P,CI, D);
		Shopname = s;
	}
	string getShopName() {
		return Shopname;
	}
};
