#include "Person.hpp"
#include "PersonBuilder.hpp"

PersonBuilder Person::create()
{
	return PersonBuilder{};
}

std::ostream& operator << (std::ostream &os, const Person &person)
{
	return os << "lives on " << person.street_addr
			<<" in "<< person.city
			<<" with code "<< person.post_code
			<<" works in "<< person.company_name
			<<" as a "<< person.position
			<<" for "<< std::to_string(person.annual_income);
}