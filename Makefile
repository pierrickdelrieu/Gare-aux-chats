SOURCES=./sources/*.c
HEADERS=./headers/
OUTPUT=./
COMPILER=clang
STD=c11
EXEC = exe

main: clean
	$(COMPILER) -ggdb3 -std=$(STD) -o $(OUTPUT)/$(EXEC) $(SOURCES) -I $(HEADERS)

clean:
	rm -rf $(OUTPUT)/$(EXEC)

run:
	cd $(OUTPUT) && ./$(EXEC)

#debug: main
#	gdb $(OUTPUT)/$(EXEC)

all: clean main run

