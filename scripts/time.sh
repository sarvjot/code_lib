start=$(date +%s%N)
$@
end=$(date +%s%N)
echo "Elapsed time: $(($(($end-$start))/1000000)) ms"
