#include "Person.hpp"

struct Person::PersonImpl
{
  void greet(Person* p);
};

void Person::PersonImpl::greet(Person* p)
{
  std::cout << "hello " << p->name;
}

Person::Person() : impl(new PersonImpl) { }

Person::~Person() { delete impl; }

void Person::greet()
{
  impl->greet(this);
}


