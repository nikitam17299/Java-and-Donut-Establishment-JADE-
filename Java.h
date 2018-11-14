#ifndef __JAVA_H
#define __JAVA_H

#include "product.h"
#include <vector>
#include <iostream>

enum Shot {None, Chocolate,Vanilla,Peppermint,Halenut};

class Java:public Product
{
	protected:
		int _darkness;
		std::vector<Shot> _shots;
	public:
		Java(std::string name, double price, double cost,int darkness);
		void add_shot(Shot shot);
		std::string to_string() override;

		
};

#endif
