BIN = haproxy-base64
SRCS = base64.c main.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	gcc -Wall -o $@ $^

.c.o:
	gcc -Wall -c -o $@ $<

base64.o: base64.c
main.o: main.c

.PHONY: clean
clean:
	$(RM) $(BIN) $(OBJS)

.PHONY: test
test: $(BIN)
	set -x; test "$$(./$(BIN) s30tob64 393463510)" = "Xc8bW"
	set -x; test "$$(./$(BIN) s32tob64 1573854040)" = "Xc8bW"
	set -x; test "$$(./$(BIN) b64tos30 Xc8bV)" = "393463509"
	set -x; test "$$(./$(BIN) b64tos32 Xc8bV)" = "1573854036"
