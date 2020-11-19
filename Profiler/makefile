SRC := src
INCLUDE := include
BIN := bin

CC = gcc
CFLAGS = -Wall -ansi 
LDFLAGS = -lMLV
OBJ = $(BIN)/Main.o $(BIN)/Tree.o $(BIN)/Graphic.o $(BIN)/Option.o $(BIN)/Profiler.o

$(BIN)/myprofiler: $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) $(LDFLAGS)

$(BIN)/Main.o: $(SRC)/Main.c $(INCLUDE)/Tree.h $(INCLUDE)/Option.h $(INCLUDE)/Profiler.h  $(INCLUDE)/Macro_Profiler2.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(BIN)/Tree.o: $(SRC)/Tree.c $(INCLUDE)/Tree.h $(INCLUDE)/Graphic.h $(INCLUDE)/Macro_Profiler2.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(BIN)/Graphic.o: $(SRC)/Graphic.c $(INCLUDE)/Tree.h $(INCLUDE)/Macro_Profiler2.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(BIN)/Option.o: $(SRC)/Option.c $(INCLUDE)/Graphic.h $(INCLUDE)/Profiler.h $(INCLUDE)/Macro_Profiler2.h
	$(CC) -c $< -o $@ $(CFLAGS)

$(BIN)/Profiler.o: $(SRC)/Profiler.c $(INCLUDE)/Profiler.h $(INCLUDE)/Macro_Profiler2.h
	$(CC) -c $< -o $@ $(CFLAGS)


clean:
	rm -f bin/*.o myprofiler