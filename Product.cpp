#include "product.h"
#include <iomanip>

Product::Product(std::string name,double price, double cost):_name{name},_price{price},_cost{cost}{}

std::string Product::name()
{
	return _name;
}

std::string Product::to_string()
{
  auto p=std::to_string(_price);
  auto c=std::to_string(_cost);
    std::string a= "Product: "+_name+"  "+"Price: "+p+"  "+"Cost: "+c+"  ";
  return a;
  
}
