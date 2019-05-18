#include <iostream>
#include <sstream>
using namespace std;
#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"
#include "PersonAddrBuilder.hpp"

int main(int argc, char const *argv[])
{
	Person p = Person::create()
		.lives().at("Souther District 10").with_postcode("112234").in("Fiction")
		.works().at("Rich Company").as_a("KaamWala").earning(-20);

	cout << p << endl;
	getchar();
	return 0;
}