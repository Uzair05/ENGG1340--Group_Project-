RestaurantTables.o:RestaurantTables.cpp RestaurantTables.h TableTop.h
	g++ --pedantic-errors -std=c++11 -c $<
FamilyDeli.o:FamilyDeli.cpp RestaurantTables.h
	g++ --pedantic-errors -std=c++11 -c $<
FamilyDeli:FamilyDeli.o RestaurantTables.o RestaurantTables.h
	g++ --pedantic-errors -std=c++11 $^ -o $@


.PHONY: clean cleanAll
clean:
	rm -rf *.o
cleanAll:
	rm -rf *.o *.txt FamilyDeli
	#This resets everything
