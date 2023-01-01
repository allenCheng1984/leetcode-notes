CC=gcc
CFLAGS=-g

all: clean target

target: two_sum
	$(CC) $(CFLAGS) -o test.out two_sum.o test.c

two_sum:
	$(CC) $(CFLAGS) -o two_sum.o -c two_sum.c

# 清除掉執行檔與除錯檔
clean:
	rm -rf ./*.o
	rm -rf ./*.out
	rm -rf ./*.dSYM
