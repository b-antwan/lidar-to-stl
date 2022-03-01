CC=gcc
CFLAGS= -Wall -Wextra -pedantic -g -std=c11 -O3
CFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined -fsanitize=leak
LDFLAGS=-lm
LDFLAGS_ASAN=-fsanitize=address -fno-omit-frame-pointer


all: main compile_test


main: main.o  c_vector_ci/point.o c_vector_ci/vector.o c_vector_ci/error.o c_vector_ci/las.o stl/stl.o triangle/triangle.o triangle/triangulation.o c_vector_ci/i_edge.o c_vector_ci/i_triangle.o c_vector_ci/vector_point_2d.o c_vector_ci/vector_point_3d.o 
	$(CC) -o $@ $^ $(CFLAGS) $(CFLAGS_ASAN) $(LDFLAGS) $(LDFLAGS_ASAN)
	
%.o : %.c
	$(CC) $(COMPILE_OPTS) $(OPTIM_OPTS) $(SANITIZERS) -c $^ -o $@

compile_test: c_vector_ci/vector.o c_vector_ci/error.o c_vector_ci/filter_functions.o c_vector_ci/map_functions.o test/test_vector.c test/test_filter_functions.o test/test_map_functions.o
	$(CC) test/test.c $^ -o test.out $(LIBS) $(CFLAGS) $(CFLAGS_ASAN) -lcunit

test: compile_test
	./test.out

clean:
	rm -f */*.o *.o

