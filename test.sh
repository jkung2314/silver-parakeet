CASE=$1
START=$(date +%s)

echo testing case $CASE...

kenv CMPS_111_SCHED=$CASE

for i in `seq 1 10`;
do
  ./test_runq 1000000000 $i in-$CASE &
done

kenv CMPS_111_SCHED_SAVE=1
wait
dmesg -c > out-$CASE

END=$(date +%s)
echo "case $CASE took $((END - START)) seconds" >> out-$CASE

cat in-$CASE >> out-$CASE
rm -f in-$CASE
