CC = g++
CCFLAGS = -g -W -Wall

FLEX = flex
FLEX_OPTS = -Pcalc

BISON = bison
BISON_OPTS = -t -pcalc

OBJS = Absyn.o Lexer.o Parser.o Printer.o
MAIN_OBJS = Absyn.o Lexer.o Parser.o Interpreter.o

.PHONY: clean distclean

all: Main

clean:
	rm -f *.o Testcalc calc.aux calc.log calc.pdf calc.dvi calc.ps calc

distclean: clean
	rm -f Absyn.C Absyn.H Test.C Parser.C Parser.H Lexer.C Skeleton.C Skeleton.H Printer.C Printer.H Makefile calc.l calc.y calc.tex 

Testcalc: ${OBJS} Test.o
	@echo "Linking Testcalc..."
	${CC} ${CCFLAGS} ${OBJS} Test.o -o Testcalc

Main: ${MAIN_OBJS} Main.o
	@echo "Linking Interpreter..."
	${CC} ${CCFLAGS} ${MAIN_OBJS} Main.o -o Main

Absyn.o: Absyn.C Absyn.H
	${CC} ${CCFLAGS} -c Absyn.C

Lexer.C: calc.l
	${FLEX} -oLexer.C calc.l

Parser.C: calc.y
	${BISON} calc.y -o Parser.C

Lexer.o: Lexer.C Parser.H
	${CC} ${CCFLAGS} -c Lexer.C

Parser.o: Parser.C Absyn.H
	${CC} ${CCFLAGS} -c Parser.C

Printer.o: Printer.C Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Printer.C

Skeleton.o: Skeleton.C Skeleton.H Absyn.H
	${CC} ${CCFLAGS} -c Skeleton.C

Test.o: Test.C Parser.H Printer.H Absyn.H
	${CC} ${CCFLAGS} -c Test.C

Interpreter.o: Interpreter.C Interpreter.H Absyn.H
	${CC} ${CCFLAGS} -c Interpreter.C

Main.o: Main.C Parser.H Interpreter.H Absyn.H
	${CC} ${CCFLAGS} -c Main.C

