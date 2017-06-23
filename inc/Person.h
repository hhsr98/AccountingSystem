#ifndef __PERSON_H
#define __PERSON_H

class Person
{
    string name;
public:
    Person(string _name):name(_name){}

    Person():name("new person"){}

    string Name()
    {return name;}

    void setName(string _name)
    {name=_name;}
};
#endif // __PERSON_H
