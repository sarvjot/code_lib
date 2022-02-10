bld="g++ -std=gnu++17 -O3 -DDEBUG -g -fsanitize=signed-integer-overflow -fsanitize=bounds-strict -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=float-divide-by-zero -fsanitize=pointer-overflow -fsanitize=shift-exponent -fsplit-stack -Wshadow -Wall -fconcepts"

$bld code.cpp -o c.out
$bld generator.cpp -o g.out

if [ ! -d input ]; then
    mkdir input
fi

if [ ! -d output ]; then
    mkdir output 
fi

for i in {3..9}
do
    inp_file=./input/input0$i.txt
    out_file=./output/output0$i.txt

    touch $inp_file
    touch $out_file

    ./g.out > $inp_file
    ./c.out < $inp_file > $out_file

    echo "Succesfully Generated Testcase $i"
    sleep 1
done
