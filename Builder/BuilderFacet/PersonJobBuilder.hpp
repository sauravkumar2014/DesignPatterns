#pragma once
#include <string>
#include "PersonBuilder.hpp"

class PersonJobBuilder : public PersonBuilderBase
{
public:
	PersonJobBuilder(Person &person) : PersonBuilderBase(person) {}

	PersonJobBuilder& at(std::string company_name)
	{
		person.company_name = company_name;
		return *this;
	}

	PersonJobBuilder& as_a(std::string position)
	{
		person.position = position;
		return *this;
	}

	PersonJobBuilder& earning(int annual_income)
	{
		person.annual_income = annual_income;
		return *this;
	}
};