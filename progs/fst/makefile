CFLAGS=-Wall -O -Wuninitialized

TRAFFIC=traffic
OTRAFFIC=traffic.o fst_mealy.o clock.o act_timer.o actions.o lights.o

all:	$(TRAFFIC)

$(TRAFFIC):  $(OTRAFFIC)
	$(CC) -o$@ $(OTRAFFIC)

traffic.o: fst_mealy.h clock.h act_timer.h actions.h traffic_def.h
actions.o: lights.h act_timer.h

clean:
	-rm $(TRAFFIC) *.o

back:
	mkdir -p backup
	-cp *.[ch] makefile backup/







