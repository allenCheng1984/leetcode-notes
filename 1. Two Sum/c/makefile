CC = gcc
CFLAGS += -g # 啟用 debug 資訊 (使用 GDB 除錯時用)
CFLAGS += -Wall # 顯示錯誤與警告訊息
CFLAGS += -Wextra # 顯示額外的錯誤警告訊息
CFLAGS += -I ../../libs # 設定 include header 的額外目錄位置
# CFLAGS += -v # 顯示編譯與連接時的訊息
# CFLAGS += -O2 # 效能優化
# CFLAGS += -pedantic # 依嚴格的ANSI C的標準發出警告訊息，並駁回任使用不允許擴充函數的程式。
# CFLAGS += -std=gnu11 # 指定編譯器版本

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
