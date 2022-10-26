build.sh your.cpp your 
build.sh correct.cpp correct 
build.sh generator.cpp gen

for((i = 1; ; ++i)); do
    ./gen > tc.txt
    ./your < tc.txt > your.txt
    ./correct < tc.txt > correct.txt
    diff -i your.txt correct.txt > /dev/null || break
    echo "Passed test: " $i  
done

echo "WA on the following test:"
cat tc.txt
echo "Your Output is:"
cat your.txt
echo "Correct Output is:"
cat correct.txt

# to convert line endings from windows to unix : dos2unix  
