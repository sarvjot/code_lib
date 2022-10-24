build.sh naive.cpp naive
build.sh optimised.cpp optimised
build.sh generator.cpp gen
for((i = 1; ; ++i)); do
    ./gen > tc.txt
    ./optimised < tc.txt > optimised.txt
    ./naive < tc.txt > naive.txt
    diff -i optimised.txt naive.txt > /dev/null || break
    echo "Passed test: " $i  
done
echo "WA on the following test:"
cat tc.txt
echo "Your answer is:"
cat naive.txt
echo "Correct answer is:"
cat optimised.txt

# to convert line endings from windows to unix : dos2unix  
