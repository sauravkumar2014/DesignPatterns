#pragma once
#include <string>
#include <iostream>

/* Implementation of PersonImpl and Person hidden.
 * Can be easily forwarded to any consumer of API without releasing secrets/implementation
 * prevents recompilation of sources reliant on the header
 */
struct Person
{
  std::string name;

  class PersonImpl;
  PersonImpl *impl; // bridge - not necessarily inner class, can vary

  Person();
  ~Person();

  void greet();
};
