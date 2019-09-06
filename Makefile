all: do

do: main.o funcoes.o concessionaria.o automovel.o tempo.o
	g++ -std=c++11 -Wall -pedantic -g -O0 -o exec main.o funcoes.o concessionaria.o automovel.o tempo.o

main.o: cpp/main.cpp includes/funcoes.h
	g++ -std=c++11 -Wall -pedantic -g -O0 -c cpp/main.cpp

funcoes.o: cpp/funcoes.cpp includes/funcoes.h
	g++ -std=c++11 -Wall -pedantic -g -O0 -c cpp/funcoes.cpp

concessionaria.o: cpp/concessionaria.cpp includes/concessionaria.h
	g++ -std=c++11 -Wall -pedantic -g -O0 -c cpp/concessionaria.cpp

automovel.o: cpp/automovel.cpp includes/automovel.h
	g++ -std=c++11 -Wall -pedantic -g -O0 -c cpp/automovel.cpp

tempo.o: cpp/tempo.cpp includes/tempo.h
	g++ -std=c++11 -Wall -pedantic -g -O0 -c cpp/tempo.cpp

clean:
	rm -rf *.o exec

# # my first good makefile

# # name of the project
# PROJ_NAME=exec

# # .cpp files
# CPP_SOURCE=$(wildcard *.cpp)

# # .h files
# H_SOURCE=$(wildcard *.h)

# # Object files
# OBJ=$(CPP_SOURCE: .c=.o)

# # Compiler
# CC=g++

# # Flags for compiler
# CPP_FLAGS= -W -Wall -pedantic -std=c++11 -c

# #
# #  Compilation and linking
# #

# all: $(PROJ_NAME)

# $(PROJ_NAME): $(OBJ)
# 	$(CC) -o $@ $^

# %.o: %.cpp %.h
# 	$(CC) -o $@ $< $(CPP_FLAGS)

# main.o: main.cpp $(H_SOURCE)
# 	$(CC) -o $@ $< $(CPP_FLAGS)

# clean:
# 	rm -rf *.o $(PROJ_NAME)

