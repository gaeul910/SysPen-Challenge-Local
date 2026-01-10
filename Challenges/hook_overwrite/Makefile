CC = gcc
CFLAGS = -fno-stack-protector -no-pie -g

all: hook_overwrite

hook_overwrite: hook_overwrite.c
	$(CC) $(CFLAGS) -o hook_overwrite hook_overwrite.c

clean:
	rm -f hook_overwrite
