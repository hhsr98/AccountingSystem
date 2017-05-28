#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <iostream>
using namespace std;
template <typename T>
class SmartPtr; 
template <typename T> 
class U_Ptr { 
private:
	friend class SmartPtr<T>;
	U_Ptr(T *ptr) :p(ptr), count(1) { } 
	~U_Ptr() { delete p; }
	int count;
	T *p;
};
template <typename T> 
class SmartPtr { 
public:
	SmartPtr(T *ptr) :rp(new U_Ptr<T>(ptr)) { }
	SmartPtr(const SmartPtr<T> &sp) : rp(sp.rp) { 
	++rp->count; 
	}
	SmartPtr& operator=(const SmartPtr<T>& rhs) {
	++rhs.rp->count; 
	if (--rp->count == 0) 
	delete rp; 
	rp = rhs.rp; 
	return *this;
	}
	~SmartPtr() {
	if (--rp->count == 0) 
	delete rp; 
	}
	T & operator *() { return *(rp->p); }
	T* operator ->() { return rp->p; }
	const int getcount()const {
	return rp->count;
	}
private:
	U_Ptr<T> *rp;
};
#endif