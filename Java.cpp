#include "java.h"
#include <iostream>

Java::Java(std::string name, double price, double cost,int darkness):_darkness{darkness},Product{name,price,cost}  {}


void Java::add_shot(Shot shot)
{
	_shots.push_back(shot);
}

std::string Java::to_string() 
{
 	 std:: string s="\n";
  	std::string s_shot=" ";
	std::string s_darkness="";
	std::string separator = "";
	if(_darkness ==0)
			s_darkness="Blonde ";
		
		else 
		if(_darkness==1)
			s_darkness="Light ";
		else if (_darkness==2)
			s_darkness="Medium ";
		else if(_darkness==3)
			s_darkness="Dark ";
		else if(_darkness==4)
			s_darkness="Extra Dark ";
		    s =  Product::to_string() + " (" + s_darkness+ ") with ";
  for(auto ss:_shots)
    {
      if(ss==0)
	{
        	s_shot="No ";

	}
      else if(ss==1)
	{
	  	s_shot="Chocolate ";
	}
      else if(ss==2)
	{
	  	s_shot= "Vanilla ";
	}
      else if(ss==3)
	{
	  	s_shot="Peppermint ";
	}
      else if(ss==4)
	{
	  	s_shot= "Hazlenut ";
	}
     
     s += separator + s_shot; separator = ", "; 
    }
	s=s+"shots";
    //s=Product::to_string()+" Darkness: "+ s_darkness+" with  "+s_shot+" shots"+"\n";
  return s+"\n";
}
