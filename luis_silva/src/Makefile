CC=g++
CFLAGS=-Wall -Wextra -g
EXEC=./tp3 # nome do executavel que sera gerado, nao troque
TMPOUT=tp3.testresult


$(EXEC): main.cpp celula.o arvore.o 
	$(CC) $(CFLAGS) main.cpp celula.o arvore.o -o $(EXEC)

celula.o: headers/celula.cpp
	$(CC) $(CFLAGS) -c headers/celula.cpp -o celula.o 

arvore.o: headers/arvore.cpp
	$(CC) $(CFLAGS) -c headers/arvore.cpp -o arvore.o 

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf selection.o
	rm -rf celula.o