CC := clang++-10 #g++
CFLAGS := -g -std=c++11 -Wall -MMD -MP # -Weffc++ -Wextra #  -Werror  -Wsign-conversion

TARGET := main

all: $(TARGET)

$(TARGET):$(TARGET).cpp
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)
-include $(DEPS)
