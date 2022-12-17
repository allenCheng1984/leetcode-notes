CC=gcc
CFLAGS=-g

all: clean target

target: lru_cache
	$(CC) $(CFLAGS) -o test.out lru_cache.o test.c

lru_cache:
	$(CC) $(CFLAGS) -o lru_cache.o -c lru_cache.c

# 清除掉執行檔與除錯檔
clean:
	rm -rf ./*.o
	rm -rf ./*.out
	rm -rf ./*.dSYM
