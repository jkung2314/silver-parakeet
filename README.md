**Team Name:** Deckard's Replicants  
**Team Captain:** jhkung (Jonathan Kung)  
syakter (Samin Akter)  
stesuh  (Steven Suh)  
emgwong (Emma Wong)  

## Notes
* Our benchmarking code is located in DESIGN.pdf
* The benchmark code we used was posted on the CMPS 111-SPRING-19-01  
Piazza by Axel Eduardo Garcia, and code written by Andrew Purcell. The link  
to the post can be found here: https://piazza.com/class/jtt1omu5bb2sd?cid=347 

## Instructions to Run Code
Run `kenv CMPS_111_SCHED=1` to create/modify kernel variable, where 1 represents case 1,  
and 2 represents case 2, etc.

Run `make all`, which moves the required the kernel file(s) /usr/src/sys/kern,  
then proceeds to build and install kernel.

For testing, cd to /benchmark and run `make all` to generate the `benchmark` executable.  
Then run executable with specified kernel variable.
