#pragma once
#include "HotDrinkFactory.hpp"

/* Factory of Base Class */
struct CoffeeFactory : HotDrinkFactory
{
  std::unique_ptr<HotDrink> make() const override {
    return std::make_unique<Coffee>();
  }
};