#include <iostream>
#include <memory>
#include <map>
#include "HotDrink.hpp"
#include "DrinkFactory.hpp"
using namespace std;

/* All types have to be hard coded here -> Exhausting */
std::unique_ptr<HotDrink> make_drink(std::string type)
{
  std::unique_ptr<HotDrink> drink;
  if (type == "tea")
  {
    drink = make_unique<Tea>();
    drink->prepare(200);
  }
  else 
  {
    drink = make_unique<Coffee>();
    drink->prepare(50);
  }
  return drink;
}

int main()
{
  auto d = make_drink("tea");

  DrinkFactory df;
  df.make_drink("coffee", 200);

  getchar();
  return 0;
}