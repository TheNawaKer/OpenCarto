GXX=g++
CXXFLAGS = -G3 
EXEC=princ
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

LDFLAGS  = -L/usr/X11R6/lib 
LDLIBS   = -lX11  -lglut -lGL -lGLU -lm -lpng12 -lIL -lILU -lILUT

.PHONY:	run	clean

all: $(EXEC)

$(EXEC):  $(OBJ) 
	$(GXX) -g3 -o $@ $^ $(LDFLAGS) $(LDLIBS) 

%.o: %.cpp
	$(GXX)    -o $@    -c $<

run: $(EXEC)
	./$(EXEC)

clean: 
	rm *.o


cleanall:
	rm *.o *~ ./$(EXEC)