#pragma once
#include <memory>
#include "HotDrink.hpp"

/* Factory of Base Class */
struct HotDrinkFactory
{
  virtual std::unique_ptr<HotDrink> make() const = 0;
};