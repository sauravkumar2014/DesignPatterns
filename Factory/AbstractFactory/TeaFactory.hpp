#pragma once
#include "HotDrinkFactory.hpp"

/* Factory of Base Class */
struct TeaFactory : HotDrinkFactory
{
  std::unique_ptr<HotDrink> make() const override {
  	return std::make_unique<Tea>();
  }
};