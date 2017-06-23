#ifndef __PERSON_H
#define __PERSON_H
#include<string>
class Person
{
    std::string name;
public:
    Person(std::string _name):name(_name){}

    Person():name("new person"){}

    std::string Name()
    {return name;}

    void setName(std::string _name)
    {name=_name;}
};
#endif // __PERSON_H
