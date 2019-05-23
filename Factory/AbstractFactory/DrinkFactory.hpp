#pragma once
#include <string>
#include <map>
#include <memory>
#include <functional>
#include <utility>
#include "HotDrink.hpp"
#include "TeaFactory.hpp"
#include "CoffeeFactory.hpp"

struct HotDrink;

/* Abstract Factory */
class DrinkFactory
{
  std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
public:
  DrinkFactory()
  {
    hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
    hot_factories["tea"] = std::make_unique<TeaFactory>();
  }

  std::unique_ptr<HotDrink> make_drink(const std::string& name, int&& vol)
  {
    auto drink = hot_factories[name]->make();
    drink->prepare(std::forward<int>(vol));
    return drink;
  }
};


/* Functional Factory */
class DrinkWithVolumeFactory
{
  std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;
public:

  DrinkWithVolumeFactory()
  {
    factories["tea"] = [] {
      auto tea = std::make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };
  }

  std::unique_ptr<HotDrink> make_drink(const std::string& name);
};

inline std::unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(const std::string& name)
{
  return factories[name]();
}
