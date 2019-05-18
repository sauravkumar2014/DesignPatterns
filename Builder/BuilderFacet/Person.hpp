#pragma once
#include <string>
#include <iostream>

class PersonBuilder;

class Person
{
	//addr
	std::string street_addr, post_code, city;

	//job
	std::string company_name, position;
	int annual_income{0};

	friend class PersonBuilder;
	friend class PersonJobBuilder;
	friend class PersonAddrBuilder;
	friend std::ostream& operator << (std::ostream &os, const Person &person);

	Person() {}
public:
	static PersonBuilder create();
};