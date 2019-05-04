test: test_runq
	for i in 1 2 3 4; do \
		./test_runq $i; \
	done ; \
	make clean_test

test_runq:
	cc -o test_runq test_runq.c -Wall

clean_test:
	rm -f test_runq
