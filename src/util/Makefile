CHECK_SUITE=util_testrunner
CHECK_SRCS=$(CHECK_SUITE).c \
	   util.c

CLEANFILES=$(CHECK_SUITE)

CHECK_LIBS	= -lcheck
CHECK_CC	= gcc

CHECK_CFLAGS += -Werror -Wextra
CHECK_CFLAGS += -Wall -Wcast-align -Wimplicit
CHECK_CFLAGS += -Wpointer-arith -Wswitch
CHECK_CFLAGS += -Wredundant-decls -Wreturn-type -Wshadow -Wunused
CHECK_CFLAGS += -fno-builtin
CHECK_CFLAGS += -funsigned-char
CHECK_CFLAGS += -funsigned-bitfields
CHECK_CFLAGS += -fpack-struct

check: $(CHECK_SUITE)
	@echo ",---------------------."
	@echo "| Running Unit Tests  |"
	@echo "'---------------------'"
	./$(CHECK_SUITE);
	@echo ""

$(CHECK_SUITE): $(CHECK_SRCS)
	$(CHECK_CC) $(CHECK_SRCS) $(CHECK_CFLAGS) $(CHECK_LIBS) -o $@

clean:
	rm -f $(CLEANFILES)

all:
	check
