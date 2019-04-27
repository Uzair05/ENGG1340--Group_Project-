RestaurantTables.o:RestaurantTables.cpp RestaurantTables.h TableTop.h Reservation.h billing.h
	g++ --pedantic-errors -std=c++11 -c $<
Reservation.o: Reservation.cpp Reservation.h
	g++ --pedantic-errors -std=c++11 -c $<
Billing.o:Billing.cpp billing.h
	g++ --pedantic-errors -std=c++11 -c $<
FamilyDeli.o:FamilyDeli.cpp RestaurantTables.h
	g++ --pedantic-errors -std=c++11 -c $<
FamilyDeli:FamilyDeli.o RestaurantTables.o Reservation.o Billing.o RestaurantTables.h Reservation.h billing.h
	g++ --pedantic-errors -std=c++11 $^ -o $@


.PHONY: clean cleanAll
clean:
	rm -rf *.o
