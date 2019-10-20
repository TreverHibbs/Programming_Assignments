compile this using gcc

gcc -o parser main.c print_nfa.c transition_util.c conversion_rules.c parser.h

Most of the simple cases produce the proper output 
but the more complex regular expressions result in bad output.