#pragma once
#include "Person.hpp"

class PersonJobBuilder;
class PersonAddrBuilder;

class PersonBuilderBase
{
protected:
	Person& person;
	PersonBuilderBase(Person &p) : person{p} {}
public:

	PersonJobBuilder works();
	PersonAddrBuilder lives();

	operator Person() {
		return std::move(person);
	}
};

class PersonBuilder : public PersonBuilderBase
{
	Person p;
public:
	PersonBuilder() : PersonBuilderBase{p} {}
};