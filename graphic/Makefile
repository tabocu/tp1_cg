SRC = paint.cpp\
	  transform.cpp

INC = -I../math/\
	  -I../util/

#test path
DIR_TEST = test/
DIR_BIN = bin/
TEST = test
LOG = log

CC = g++

CCFLAGS = -g -Wall

MKDIR = mkdir

.PHONY: test clean

default:
	$(CC) -c $(CCFLAGS) $(INC) $(SRC)

test:
	$(CC) $(CCFLAGS) $(INC) $(SRC) $(DIR_TEST)$(TEST).cpp -o \
		$(DIR_TEST)$(TEST)
	./$(DIR_TEST)$(TEST) > ./$(DIR_TEST)$(LOG)

clean:
	$(RM) *.o
	$(RM) $(DIR_TEST)*.o
	$(RM) $(DIR_TEST)$(LOG)
	$(RM) $(DIR_TEST)$(TEST)
