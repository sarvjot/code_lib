build.sh code.cpp c.out 
build.sh generator.cpp g.out

if [ ! -d input ]; then
    mkdir input
fi

if [ ! -d output ]; then
    mkdir output 
fi

for i in {0..9}
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
