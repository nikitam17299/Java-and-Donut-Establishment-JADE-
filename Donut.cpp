#include "donut.h"

Donut::Donut(std::string name, double price, double cost, Frosting frosting, bool sprinkles, Filling filling):Product{name, price, cost},_frosting{frosting},_filling{filling},_sprinkles{sprinkles} {}

std::string Donut::to_string()
{
  std::string s = " ";
  std::string s_filling=" ";
  std::string s_frosting=" ";
  std:: string s_sprinkles ="";

  	if(_filling==0)
    	{	
      		s_filling="No";
    	}	
 
   	 else if(_filling==1)
    	{
      		s_filling="Creme";
    	}	
 
       	else if(_filling==2)
    	{
      		s_filling="Bavarian";
    	}
  
	else if(_filling==3)
    	{
      		s_filling="Strawberry";
    	}
 
       	else
    	{
      		s_filling="No";
    	}

  if(_frosting==0)
    {
      s_frosting="No";
    }
  else if(_frosting==1)
    {
      s_frosting="Chocolate_pop";
    }
  else if(_frosting==2)
    {
      s_frosting="Vanilla_pop";
    }
  else if(_frosting==3)
    {
      s_frosting="Pink_top";
    }
  else
    {
      s_frosting="No";
    }
    
if(_sprinkles)
{
	s_sprinkles = " with sprinkles";
}

//else if(_sprinkles = false)
//{
//	s_sprinkles  = " with no sprinkles";
//}

    s=Product::to_string()+" with "+s_filling+" filling and "+s_frosting+" Frosting"+ s_sprinkles+"\n";
  return s;
}
