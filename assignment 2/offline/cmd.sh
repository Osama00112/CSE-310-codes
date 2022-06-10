flex -otest.c hello.l
g++ test.c -lfl -o test.out
./test.out demo2.txt


flex -otest.cpp hello.l
g++ test.cpp -lfl -o test.out
./test.out input.txt


flex -otest.cpp scanner.l
g++ test.cpp -lfl -o test.out
./test.out sample_input1.txt


flex -o $1.c $1.l
g++ $1.c -lfl -o $1.out
./$1.out $1.txt
