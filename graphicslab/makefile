TARGETS = trignometricCircle 

CC = cc
#-Weeror option to convert warnings to errors
#-fpic to make object file that can be used for library
CFLAGS = -Wall -Werror -std=c11 -lgraph -lm

# if all is called then first clean is done then $targets is called
all: clean $(TARGETS)

# compiling the file
# @ means suppress the normal echo of command being executed
$(TARGETS): $(TARGETS).c
	@$(CC) $(CFLAGS) $@.c -o $@

# removing the final executable file
clean:
	@rm -f $(TARGETS)
