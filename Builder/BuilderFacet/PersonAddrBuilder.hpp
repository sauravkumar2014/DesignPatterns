#pragma once
#include <string>
#include "PersonBuilder.hpp"

class PersonAddrBuilder : public PersonBuilderBase
{
public:
	PersonAddrBuilder(Person &person) : PersonBuilderBase(person) {}

	PersonAddrBuilder& at(std::string street_addr)
	{
		person.street_addr = street_addr;
		return *this;
	}

	PersonAddrBuilder& with_postcode(std::string post_code)
	{
		person.post_code = post_code;
		return *this;
	}

	PersonAddrBuilder& in(std::string city)
	{
		person.city = city;
		return *this;
	}
};