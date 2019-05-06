all: kern_switch
	cd /usr/src && make buildkernel && make installkernel

kern_switch:
	mv kern_switch.c /usr/src/sys/kern/kern_switch.c
