RestaurantTables.o:RestaurantTables.cpp RestaurantTables.h TableTop.h
	g++ --pedantic-errors -std=c++11 -c $<
FamilyDeli.o:FamilyDeli.cpp RestaurantTables.h TableTop.h
	g++ --pedantic-errors -std=c++11 -c $<
main:RestaurantTables.o RestaurantTables.h TableTop.h
	g++ --pedantic-errors -std=c++11 $^ -o $@


.PHONY: clean
clean:
	rm -rf *.o
