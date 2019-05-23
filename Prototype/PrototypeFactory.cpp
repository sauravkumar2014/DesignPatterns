#include <string>
#include <iostream>
#include <memory>
using namespace std;

struct Address
{
  string street;
  string city;
  int suite;


  Address(const string& street, const string& city, const int suite)
    : street{street}, city{city}, suite{suite} { }

  Address(const Address& other)
    : street{other.street}, city{other.city}, suite{other.suite} { }

  friend ostream& operator<<(ostream& os, const Address& obj)
  {
    return os
      << "street: " << obj.street
      << " city: " << obj.city
      << " suite: " << obj.suite;
  }
};


struct Contact
{
  string name;
  Address* address;

  Contact(const string& name, Address* address)
    : name{name}, address{address} { }

  Contact(const Contact& other)
    : name{other.name}, address{ new Address{*other.address} } { }

public:
  ~Contact()
  {
    delete address;
  }


  friend ostream& operator<<(ostream& os, const Contact& obj)
  {
    return os << "name: " << obj.name << " works at " << *(obj.address);
  }
};

struct EmployeeFactory
{
  static unique_ptr<Contact> NewMainOfficeEmployee(const string& name,
          const int suite)
  {
    static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
    return NewEmployee(name, suite, p);
  }

private:
  static unique_ptr<Contact> NewEmployee(const string& name,
          const int suite, const Contact proto)
  {
    auto result = make_unique<Contact>(proto);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

int main()
{
  auto john = EmployeeFactory::NewMainOfficeEmployee("John Doe", 123);
  auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Smith", 103);

  cout << *john << endl << *jane << endl;
  return 0;
}