CC := clang++-10 #g++ 
CFLAGS := -g -Wall -MMD -MP -Weffc++ #-Wextra -Wsign-conversion -Werror

TARGET := main

all: $(TARGET)

$(TARGET):$(TARGET).cpp
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)
-include $(DEPS)
