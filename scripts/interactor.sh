#
#
#       STILL HAVE TO FIX FILE PERMISSIONS FOR MEMORY, TILL THEN YOU SHOULD USE COMMANDS DIRECTLY IN TERMINAL
#
#

build.sh solution.cpp soln
build.sh interactor.cpp inter
rm -rf /tmp/fifo && mkfifo /tmp/fifo && (./soln < /tmp/fifo) 1>&2 | (./inter > /tmp/fifo 1>&2)
