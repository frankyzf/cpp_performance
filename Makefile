all:a.out


C++ = g++
INC += -I./ -I./includes -I/export/home/thirdparty/boost/1.47.0/${PLATFORM}/include
CFLAGS= $(INC) -Wreturn-type -Wall -Wno-deprecated -Werror -O2

SRC=${wildcard *.cpp}
OBJ=${SRC:.cpp=.o}

%.o: %.cpp
	$(C++) -c  $(CFLAGS)   $< -o $@

a.out: performance_stringprint.o 
	$(C++)  $< -o $@




clean:
	rm -rf *o a.out 
