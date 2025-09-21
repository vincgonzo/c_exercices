# capstone library name (without prefix 'lib' and suffix '.so')
LIBNAME = capstone

basic_caplinear.c: basic_caplinear.c.o
	${CC} $< -O3 -Wall -l$(LIBNAME) -o $@

%.o: %.c
	${CC} -c $< -o $@
