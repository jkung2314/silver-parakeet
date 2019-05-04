test: test_runq
	@dmesg -ac
	for i in 1 2 3 4; do \
		time ./test.sh $$i; \
	done ; \
	make clean_test

test_runq:
	cc -o test_runq test_runq.c -Wall

clean_test:
	rm -f test_runq
