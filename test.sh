CASE=$1
START=$(date +%s)

kenv CMPS_111_SCHED=$CASE

for i in `seq 1 10`;
do
  if [[ $i -eq 10 ]]; then
    kenv CMPS_111_SCHED_SAVE=1
    ./test_runq 1000000000 ;
  else
    ./test_runq 1000000000 &
  fi
done

dmesg -ac > out-$CASE

END=$(date +%s)

echo "case $CASE took $((END - START)) seconds" >> out-$CASE
