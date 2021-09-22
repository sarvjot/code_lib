start=$(date +%s%N)

g++ $1

end=$(date +%s%N)
echo "Elapsed time: $(($(($end-$start))/1000000)) ms"