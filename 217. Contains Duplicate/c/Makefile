CC=gcc
CFLAGS=-g

all: clean target

target: contains_duplicate
	$(CC) $(CFLAGS) -o test.out contains_duplicate.o test.c

contains_duplicate:
	$(CC) $(CFLAGS) -o contains_duplicate.o -c contains_duplicate.c

# 清除掉執行檔與除錯檔
clean:
	rm -rf ./*.o
	rm -rf ./*.out
	rm -rf ./*.dSYM
