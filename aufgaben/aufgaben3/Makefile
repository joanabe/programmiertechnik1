CFLAGS = -Wall -O3 -std=gnu99
PROGRAMS=factors primefactors factorial_factors

all: $(PROGRAMS)

factors: factors.c

primefactors: primefactors.c

factorial_factors: factorial_factors.c

clean: 
	rm -f $(PROGRAMS)
	rm -f *.o
	rm -rf *.dSYM 


$(PROGRAMS): %: %.c 
	$(CC) $(CFLAGS) $< -o $@

