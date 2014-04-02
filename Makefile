GXX=g++
CXXFLAGS = -O2 
EXEC=princ
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

LDFLAGS  = -IL -ILU -ILUT -L/usr/X11R6/lib 
LDLIBS   = -lX11  -lglut -lGL -lGLU -lm -lpng12 

.PHONY:	run	clean

all: $(EXEC)

$(EXEC):  $(OBJ) 
	$(GXX)  -o $@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(GXX)    -o $@    -c $< 

run: $(EXEC)
	./$(EXEC)

clean: 
	rm *.o


cleanall:
	rm *.o *~ ./$(EXEC)