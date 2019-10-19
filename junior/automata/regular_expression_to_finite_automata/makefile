parser: main.o nfa_union.o print_nfa.o  
    gcc -o parser main.c nfa_union.o print_nfa.o
main.o: main.c parser.h
    gcc -c main.c parser.h
nfa_union.o: nfa_union.c parser.h
    gcc -c nfa_union.c parser.h
print_nfa.o: print_nfa.c parser.h
    gcc -c print_nfa.c parser.h
stack.o: stack.c parser.h
    gcc -c stack.c parser.h