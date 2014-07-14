SRC=src/

.PHONY: src clean

all:
	$(MAKE) -C $(SRC) $(FLAGS)

clean:
	rm RBTest*
	$(MAKE) -C $(SRC) clean
