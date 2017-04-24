%.o: %.c %.h 
	$(CC) -c $<

plansim: main.o lbody.o body.o simulation.o
	$(CC) $^ -o $@

.PHONY: clean
clean:
	-rm *.o plansim
