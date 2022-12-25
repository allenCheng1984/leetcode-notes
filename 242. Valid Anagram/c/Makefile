CC=gcc
CFLAGS=-g

all: clean target

target: valid_anagram
	$(CC) $(CFLAGS) -o test.out valid_anagram.o test.c

valid_anagram:
	$(CC) $(CFLAGS) -o valid_anagram.o -c valid_anagram.c

# 清除掉執行檔與除錯檔
clean:
	rm -rf ./*.o
	rm -rf ./*.out
	rm -rf ./*.dSYM
