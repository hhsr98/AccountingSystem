#define _CRT_SECURE_NO_WARNINGS
#pragma once
//#include <json/json.h>
#include<string>
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
	std::string Country, Province, City, District, Shopname;
	void getPlace(std::string C,std::string P,std::string CI,std::string D) {/*
		system("python location.py");
		FILE *fp = fopen("locate.txt", "r");
		static char s[50];
		if(C.length())
			Country = C;
		else
			fscanf();
		else
		Province = P;
		District = D;
		City = CI;
		latitude = 0.0;
		longitude = 0.0;*/
	}
public:
	//Shop() { getPlace(); }
	Shop(std::string s, std::string C = std::string(),std::string P = std::string(), std::string CI =std::string(),std::string D = std::string()) {
		getPlace(C,P,CI, D);
		Shopname = s;
	}
	std::string getShopName() {
		return Shopname;
	}
};
