# compiler im using = CC
#CC := g++
CC := clang++-10
## compiler flags
# -g 
#
CFLAGS := -g -std=c++11 -Wall -MMD -MP #-Weffc++ -Wextra #-Werror -Wsign-conversion 

# 'LFLAGS' is all my subfiles, .ccp used in the main .cpp file
#LFLAGS := sub_dir/*.cpp

# name of the resulting excutable
TARGET := NearestNeighbours
#LogisticRegression
#main

all: $(TARGET)

$(TARGET): $(TARGET).cpp $(LFLAGS)
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET) $(LFLAGS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)
-include $(DEPS)

