test: test_runq
	./test_runq 2 && dmesg -ac > out && make clean-test

test_runq:
	cc -o test_runq test_runq.c -Wall

clean-test:
	rm test_runq
