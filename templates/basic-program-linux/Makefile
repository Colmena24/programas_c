BINARY=main
CODEDIRS=. ../../lib # can be list
INCDIRS=. ../../include/ # can be list

CC=gcc
OPT=-O0
# generate files that encode make rules for the .h dependencies
DEPFLAGS=-MP -MD
# automatically add the -I onto each include directory
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

# for-style iteration (foreach) and regular expression completions (wildcard)
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
# regular expression replacement
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

# First execute the dependent rule, but clean build files after to not confuse students with "residual" files.
all: $(BINARY)
	make clean-build

$(BINARY): $(OBJECTS) # Link math.h by default in every project to make life easier to students in diprog.
	$(CC) -o $@ $^ -lm

# only want the .c file dependency here, thus $< instead of $^.
#
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean-build:
	rm -rf $(OBJECTS) $(DEPFILES)

clean: clean-build
	rm -rf $(BINARY)

# shell commands are a set of keystrokes away
dist: clean
	tar zcvf dist.tgz *

# include the dependencies
-include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean-build clean dist