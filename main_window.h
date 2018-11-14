#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H
//#include "view.h"
#include "store.h"
#include <gtkmm.h>
//#include "rental_site.h"
//#include "vehicle.h"
//#include "controller.h"


class Main_window : public Gtk::Window
{
    public:
        Main_window();
        virtual ~Main_window();
    protected:

      void on_quit_click();           // Exit the game
	void on_java_click();
    void on_donut_click();
    void on_products_click();
    void on_list_customers_click();
    void on_new_customer_click();
    void on_about_click();


    private:
    
    Store _store{"ParksMall"};
    Store *p=NULL;


};
#endif 

