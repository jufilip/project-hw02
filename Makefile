SRC=$(wildcard src/*.c)
OBJ=$(patsubst %c, %o, $(SRC))
EXESRC=$(wildcard exesrc/*.c)
EXEOBJ=$(patsubst %c, %o, $(EXESRC))

EXE01=exe/test01.elf
EXE02=exe/test02.elf
EXE03=exe/test03.elf
EXE04=exe/test04.elf
EXE05=exe/test05.elf
EXE06=exe/test06.elf
EXEdft=exe/test_dft.elf
EXEidft=exe/test_idft.elf

.SECONDARY:

run: all
	./$(EXE01)
	./$(EXE02)
	./$(EXE03)
	./$(EXE04)
	./$(EXE05)
	./$(EXE06)
	./$(EXEdft)
	./$(EXEidft)

all: $(EXE01) $(EXE02) $(EXE03) $(EXE04) $(EXE05) $(EXE06) $(EXEdft) $(EXEidft)

exe/%.elf: exesrc/%.o $(EXEOBJ) $(OBJ) 
	gcc $< $(OBJ) -o $@ -lm

%.o: %.c
	gcc -c $< -I inc/ -o $@

clean:
	rm -f $(OBJ) $(EXEOBJ) $(EXE01) $(EXE02) $(EXE03) $(EXE04) $(EXE05) $(EXE06) $(EXEdft) $(EXEidft)
