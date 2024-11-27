CC = gcc
CFLAGS = -O0 -m32 -fno-stack-protector -fno-stack-check -no-pie
SRC = p2vuln.c
OUT = p2vuln

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)


.PHONY: clean