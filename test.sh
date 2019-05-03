cc -o test_runq test_runq.c -Wall
kenv CMPS_111_SCHED=$CASE

for CASE in `seq 1 4`;
do
  time for temp in `seq 1 1`;
  do
    for i in `seq 1 10`;
    do
      if [[ $i -eq 10 ]]; then
        ./test_runq 1000000000 ;
      else
        ./test_runq 1000000000 &
      fi
    done

    dmesg -ac > out-$CASE
  done
done

kenv CMPS_111_SCHED=0
rm test_runq
echo "test done"
