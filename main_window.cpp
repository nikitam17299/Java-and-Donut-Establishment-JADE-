#include "main_window.h"
#include "dialogs.h"
#include "store.h"
#include "product.h"
#include "Customer.h"
//#include "view.h"
Main_window::Main_window() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //   F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
   Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);
    
    //View
    //Create a view
    Gtk::MenuItem *menuitem_view=Gtk::manage(new Gtk::MenuItem("View",true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu=Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);
	
	  // All products
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_products = Gtk::manage(new Gtk::MenuItem("All products", true));
    menuitem_products->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_products_click));
    viewmenu->append(*menuitem_products);
	
	Gtk::MenuItem *menuitem_listcustomer = Gtk::manage(new Gtk::MenuItem("View Customer", true));
    menuitem_listcustomer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_customers_click));
    viewmenu->append(*menuitem_listcustomer);
    
  
    
    //Create
    //Create a menu
    Gtk::MenuItem *menuitem_create=Gtk::manage(new Gtk::MenuItem("Create",true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu=Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);
    
    //Java
    // Append Java to the Create  menu
    Gtk::MenuItem *menuitem_java = Gtk::manage(new Gtk::MenuItem("Java", true));
    menuitem_java->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_java_click));
    createmenu->append(*menuitem_java);
    
    //Donut
    // Append DOnut to the create  menu
    Gtk::MenuItem *menuitem_donut = Gtk::manage(new Gtk::MenuItem("Donut", true));
    menuitem_donut->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_donut_click));
    createmenu->append(*menuitem_donut);
	
	//Customer
	  Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("Customer", true));
    menuitem_customer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_customer_click));
    createmenu->append(*menuitem_customer);
 
 
   // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //Java
    // Add a java icon
    Gtk::Image *new_image = Gtk::manage(new Gtk::Image{"java.png"});
    Gtk::ToolButton *new_button = Gtk::manage(new Gtk::ToolButton(*new_image));
    new_button->set_tooltip_markup("Create a new java");
    new_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_java_click));
    toolbar->append(*new_button);

    //Donut
    // Add a donut icon
    Gtk::Image *open_image = Gtk::manage(new Gtk::Image{"Donut.png"});
    Gtk::ToolButton *open_button = Gtk::manage(new Gtk::ToolButton(*open_image));
    open_button->set_tooltip_markup("Create A Donut");
    open_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_donut_click));
    toolbar->append(*open_button);

    //Customer
    // Add a customer icon
    Gtk::Image *save_image = Gtk::manage(new Gtk::Image{"customer.png"});
    Gtk::ToolButton *save_button = Gtk::manage(new Gtk::ToolButton(*save_image));
    save_button->set_tooltip_markup("Create a customer");
    save_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_new_customer_click));
    toolbar->append(*save_button);

    Gtk::SeparatorToolItem *sep0 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep0);
	
	
    //list products
    // Add lsit products icon
    Gtk::Image *new_renter_image = Gtk::manage(new Gtk::Image{"list_products.png"});
    Gtk::ToolButton *new_renter_button = Gtk::manage(new Gtk::ToolButton(*new_renter_image));
    new_renter_button->set_tooltip_markup("List products");
    new_renter_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_products_click));
    toolbar->append(*new_renter_button);

    //     L I S T   CUSTOMERS
    // List customers icon
    Gtk::Image *list_renters_image = Gtk::manage(new Gtk::Image{"list_customers.png"});
    Gtk::ToolButton *list_renters_button = Gtk::manage(new Gtk::ToolButton(*list_renters_image));
    list_renters_button->set_tooltip_markup("List all customers");
    list_renters_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_list_customers_click));
    toolbar->append(*list_renters_button);

 
    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit JADE");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

 

    vbox->show_all();

    
}

Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Main_window::on_donut_click() {
   
   		double price_f=0.0,cost_f=0.0;
		

                Gtk::Dialog *dialog = new Gtk::Dialog();
                dialog->set_title("Create a new Donut");
				
				//name
				Gtk::HBox b_name;

                Gtk::Label l_name{"Name:"};
                l_name.set_width_chars(15);
                b_name.pack_start(l_name, Gtk::PACK_SHRINK);

                Gtk::Entry e_name;
                e_name.set_max_length(50);
                b_name.pack_start(e_name, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
				
                // price
                Gtk::HBox b_price;

                Gtk::Label l_price{"Price:"};
                l_price.set_width_chars(15);
                b_price.pack_start(l_price, Gtk::PACK_SHRINK);

                Gtk::Entry e_price;
                e_price.set_max_length(50);
                b_price.pack_start(e_price, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

                //cost
				Gtk::HBox b_cost;

                Gtk::Label l_cost{"Cost:"};
                l_cost.set_width_chars(15);
                b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

                Gtk::Entry e_cost;
                e_cost.set_max_length(50);
                b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

		
                //Frosting
                Gtk::HBox b_frosting;

                Gtk::Label l_frosting{"Frosting:"};
                l_frosting.set_width_chars(15);
                b_frosting.pack_start(l_frosting, Gtk::PACK_SHRINK);

                Gtk::ComboBoxText c_frosting;
                c_frosting.set_size_request(160);
                c_frosting.append("Unfrosted");
                c_frosting.append("Chocolate_top");
                c_frosting.append("Vanilla_top");
                c_frosting.append("Pink_top");
                b_frosting.pack_start(c_frosting, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_frosting, Gtk::PACK_SHRINK);

               
	       //Filling
                Gtk::HBox b_filling;

                Gtk::Label l_filling{"Filling:"};
                l_filling.set_width_chars(15);
                b_filling.pack_start(l_filling, Gtk::PACK_SHRINK);
                Gtk::ComboBoxText c_filling;
                c_filling.set_size_request(160);
                c_filling.append("Unfilled");
                c_filling.append("Creme");
                c_filling.append("Bavarian");
                c_filling.append("Strawberry");
               
				
				b_filling.pack_start(c_filling, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_filling, Gtk::PACK_SHRINK);

				
				 Gtk::CheckButton sprinkles("Sprinkles");
				dialog->get_vbox()->pack_start(sprinkles);
				
	
		// Show dialog
                dialog->add_button("Cancel", 0);
                dialog->add_button("OK", 1);
                dialog->show_all();
                int result = dialog->run();
			

				std::string name_s = e_name.get_text();
				std::string s_price = e_price.get_text();
				std::string s_cost = e_cost.get_text();
				int frosting = c_frosting.get_active_row_number();
				int filling = c_filling.get_active_row_number();
				bool b_sprinkles=sprinkles.get_active();
		
				dialog->close();
				while (Gtk::Main::events_pending())  Gtk::Main::iteration();
			
		
         if (result == 1)
		{           



			if(name_s.empty())
			{
				Dialogs::message("Name field is empty");
			}
	
			if(s_price.empty())
			{
				Dialogs::message("Price field is empty");
			}
			
			if(s_cost.empty())
			{
				Dialogs::message("Cost field is empty");
			}
	
			else {
					try{
							price_f = std::stod(e_price.get_text());
							cost_f = std::stod(e_cost.get_text());
						}
					catch(...)
						{
							
					
	
						}
				 }
	
		if(price_f==0.0||cost_f==00)
	{
		Dialogs::message("Invalid price/cost");
	}
		if(!name_s.empty()&&!s_price.empty()&& !s_cost.empty()&&price_f!=0&&cost_f!=0)
		{	
				Donut* d = new Donut{name_s,price_f,cost_f,(Frosting) frosting,b_sprinkles,(Filling) filling};
	
				_store.add_product(d);
        } 
	}		
delete dialog;

}

void Main_window::on_java_click() {

		double price_f=0.0,cost_f=0.0;
		bool flag = true;
                
			Gtk::Dialog *dialog = new Gtk::Dialog();
            dialog->set_transient_for(*this);
			dialog->set_title("Create a new Java");
				
				//name
				Gtk::HBox name;
				Gtk::Label label_name{"Name:"};
                
                name.pack_start(label_name);

                Gtk::Entry entry_name;
                entry_name.set_max_length(50);
				name.pack_start(entry_name);
                dialog->get_vbox()->pack_start(name);
				
                // price
                Gtk::HBox price;

                Gtk::Label label_price{"Price:"};
               
                price.pack_start(label_price);

                Gtk::Entry entry_price;
                entry_price.set_max_length(50);
                price.pack_start(entry_price);
                dialog->get_vbox()->pack_start(price);

                //cost
				Gtk::HBox cost;

                Gtk::Label label_cost{"Cost:"};
				cost.pack_start(label_cost);

                Gtk::Entry entry_cost;
                entry_cost.set_max_length(50);
                cost.pack_start(entry_cost);
                dialog->get_vbox()->pack_start(cost);

		
                //Darkness
                Gtk::HBox darkness;

                Gtk::Label label_darkness{"Darkness:"};
                darkness.pack_start(label_darkness);

                Gtk::ComboBoxText c_darkness;
                c_darkness.append("Blonde");
                c_darkness.append("Light");
                c_darkness.append("Medium");
                c_darkness.append("Dark");
                c_darkness.append("Extra Dark");
                darkness.pack_start(c_darkness);
                dialog->get_vbox()->pack_start(darkness);

               
	     

	
				// Show dialog
                dialog->add_button("Cancel", 0);
                dialog->add_button("Next", 1);
				
				
                dialog->show_all();
                int result = dialog->run();

                
                std::string name_s = entry_name.get_text();
				std:: string s_price = (entry_price.get_text());
				std:: string s_cost = (entry_cost.get_text());
                
             int  darkness_n = c_darkness.get_active_row_number();
		
	
		
	
                if (result == 1)
		{                
		
			if(name_s.empty())
			{
				Dialogs::message("Name field is empty");
			}
	
			if(s_price.empty())
			{
				Dialogs::message("Price field is empty");
			}
			
			if(s_cost.empty())
			{
				Dialogs::message("Cost field is empty");
			}
	
			else {
				try{
					price_f = std::stod(entry_price.get_text());
					cost_f = std::stod(entry_cost.get_text());
					}
				catch(...){
		
						  }
				}
	
			if(price_f==0.0||cost_f==00)
		{
			Dialogs::message("Invalid price/cost");
		}
	
			if(!name_s.empty()&&!s_price.empty()&& !s_cost.empty()&&price_f!=0&&cost_f!=0)
		{
			Java* j = new Java{name_s,price_f,cost_f,darkness_n};
	
					while(flag)
						{
							Gtk::Dialog shots;	

							shots.set_title("Add shots");
							Gtk::ComboBoxText c_shots;
							c_shots.append("None");
							c_shots.append("Chocolate");
							c_shots.append("Vanilla");
							c_shots.append("Peppermint");
							c_shots.append("Hazelnut");
							shots.get_vbox()->pack_start(c_shots);
				
				 
		
							// Show dialog
							shots.add_button("Cancel", 0);
							shots.add_button("Create", 1);
							shots.add_button("Add",2);
				
							shots.show_all();
							int result = shots.run();
				
                
							int shots_n =  c_shots.get_active_row_number();
				
                
				if(result == 0)
				{
					Main_window();
						shots.close();
				while (Gtk::Main::events_pending())  Gtk::Main::iteration();
				flag = false;
				}
						if(result==2)
							{
								j->add_shot((Shot)shots_n);
								flag=true;
							}
				
						if(result==1)
						{
							_store.add_product(j);
							flag=false;
						}
		
					}
		}			
 	
	}

	delete dialog;
	
}
	
void Main_window::on_new_customer_click(){
	
 try {
                std::string name,phone;
		

                Gtk::Dialog *dialog = new Gtk::Dialog();
                dialog->set_title("Create a new Customer");
				//name
				Gtk::HBox b_name;

                Gtk::Label l_name{"Name:"};
                l_name.set_width_chars(15);
                b_name.pack_start(l_name, Gtk::PACK_SHRINK);

                Gtk::Entry e_name;
                e_name.set_max_length(50);
                b_name.pack_start(e_name, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);
				
				
				//Phone
					Gtk::HBox b_phone;

                Gtk::Label l_phone{"Phone:"};
                l_phone.set_width_chars(15);
                b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

                Gtk::Entry e_phone;
                e_phone.set_max_length(50);
                b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
                dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);
				
               

               
	     

	
				// Show dialog
                dialog->add_button("Cancel", 0);
                dialog->add_button("Create", 1);
                dialog->show_all();
                int result = dialog->run();

                dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();

                name = e_name.get_text();
				phone = e_phone.get_text();
              

		if(result==0)
		{
			Main_window();
			dialog->close();
                while (Gtk::Main::events_pending())  Gtk::Main::iteration();
		}
		
                if (result == 1)
		{               
		
	Customer* c = new Customer{name,phone};	
_store.add_customer(c);
            } 
 }		
	catch(std::runtime_error e) {
              
            }
}	


 void Main_window::on_list_customers_click(){
	 
	 Dialogs::message(_store.c_view());
	 
 }

void Main_window::on_products_click() {
 
    
    Dialogs::message(_store.view());
    
    
}

void Main_window::on_quit_click() {
    hide();
}


