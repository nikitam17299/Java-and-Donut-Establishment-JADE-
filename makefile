#MAKEFILE

CXXFLAGS += --std=c++17

main: main.o Product.o Donut.o main_window.o Java.o Store.o Customer.o Dialogs.o
	${CXX} ${CXXFLAGS} -o main main.o Product.o Donut.o main_window.o Java.o Store.o Customer.o Dialogs.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main_window.o: main_window.cpp *.h
	${CXX} ${CXXFLAGS} -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
Product.o: Product.cpp *.h
	${CXX} ${CXXFLAGS} -c Product.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags--libs`

Donut.o: Donut.cpp *.h
	${CXX} ${CXXFLAGS} -c Donut.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`


Java.o: Java.cpp *.h
	$(CXX) $(CXXFLAGS) -c Java.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
 
Dialogs.o: Dialogs.cpp *.h
	${CXX} ${CXXFLAGS} -c Dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
Store.o: Store.cpp *.h
	${CXX} ${CXXFLAGS} -c Store.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

Customer.o: Customer.cpp *.h
	${CXX} ${CXXFLAGS} -c Customer.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

clean: 
	rm -f *.o *.gch main
