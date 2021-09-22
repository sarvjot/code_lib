g++ naive.cpp -o naive_code
g++ optimised.cpp -o optimised_code
g++ generator.cpp -o gen
for((i = 1; ; ++i)); do
    ./gen > tc.txt
    ./optimised_code < tc.txt > optimised_op.txt
    ./naive_code < tc.txt > naive_op.txt
    diff -i optimised_op.txt naive_op.txt > /dev/null || break
    echo "Passed test: " $i  
done
echo "WA on the following test:"
cat tc.txt
echo "Your answer is:"
cat naive_op.txt
echo "Correct answer is:"
cat optimised_op.txt

# to convert line endings from windows to unix : dos2unix  