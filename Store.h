#ifndef __STORE_H
#define __STORE_H

#include "product.h"
#include "java.h"
#include "donut.h"
#include "customer.h"
#include <iostream>
#include <vector>
class Store
{
	private:
		std::string _name;
		std::vector<Product*> _products;
    		std::vector<Customer*> _customers;

	public:
		Store(std::string store_name);
		std::string name();
		void add_product(Product *product);
    		std::string view();
       // friend std::ostream &operator<<(std::ostream &ost, Product *product);
		int number_of_products();
		std::string product_to_string(int product);
		void add_customer(Customer *customer);
		int number_of_customers();
		std::string customer_to_string(int Customer);
		std::string c_view();




};

#endif

