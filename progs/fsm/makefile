CFLAGS=-Wall -O -Wuninitialized

VEND=vend
OVEND=vend.o fsm_moore.o

GAME=game
OGAME=game.o fsm_moore.o

all:	$(VEND) $(GAME)

$(VEND):  $(OVEND)
	$(CC) -o$@ $(OVEND)

$(GAME):  $(OGAME)
	$(CC) -o$@ $(OGAME)

vend.o:	fsm_moore.h vend_def.h
game.o: fsm_moore.h game_def.h

clean:
	-rm $(VEND) $(GAME) *.o

back:
	mkdir -p backup
	-cp *.[ch] makefile backup


