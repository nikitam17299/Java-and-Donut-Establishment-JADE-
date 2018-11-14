#include "store.h"

Store::Store(std::string store_name):_name{store_name}{}

std::string Store::name()
{
	return _name;
}

void Store::add_product(Product *product)
{
	_products.push_back(product);

}

int Store::number_of_products()
{
	return _products.size();
}

std::string Store:: product_to_string(int product)
{	
	std::string s;
	s = _products[product]->to_string();
    return s;
}
std::string Store::view()
{
    int i=0;
    std::string s;
    for(i=0;i<number_of_products();i++)
    {
        s=s+product_to_string(i);
    }
    std::string ss= _name+"\n\n"+s;
    return ss;
    
    
}
std::string Store::c_view()
{
    int i=0;
    std::string s;
    for(i=0;i<number_of_customers();i++)
    {
        s=s+customer_to_string(i);
    }
    std::string ss= _name+"\n\n"+s;
    return ss;
    
    
}
void Store::add_customer(Customer* customer)
{
	_customers.push_back(customer);

}

int Store::number_of_customers()

{
	int n=_customers.size();

	return n;
}

std::string Store::customer_to_string(int customer)
{
	std::string s;

	s = _customers[customer]->to_string();
	
	return s;

}

