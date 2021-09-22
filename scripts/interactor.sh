#
#
#       STILL HAVE TO FIX FILE PERMISSIONS FOR MEMORY, TILL THEN YOU SHOULD USE COMMANDS DIRECTLY IN TERMINAL
#
#

bld="g++ -std=gnu++17 -O3 -DDEBUG -g -fsanitize=signed-integer-overflow -fsanitize=bounds-strict -fsanitize=address -fsanitize=integer-divide-by-zero -fsanitize=float-divide-by-zero -fsanitize=pointer-overflow -fsanitize=shift-exponent -fsplit-stack -Wshadow -Wall 
-fconcepts"
$bld ./1556D.cpp -o soln
$bld ./1556D_interactor.cpp -o inter
rm -rf /tmp/fifo && mkfifo /tmp/fifo && (./soln < /tmp/fifo) 1>&2 | (./inter > /tmp/fifo 1>&2)
