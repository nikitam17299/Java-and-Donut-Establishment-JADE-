#include <gtkmm.h>
#include "main_window.h"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.rvms");
    Main_window win;
    win.set_title("Java and Donut Establishment(JADE)");
    return app->run(win);
}

