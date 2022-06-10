flex -otest.cpp scanner.l
g++ -std=c++14 test.cpp -lfl -o test.out
./test.out sample_input.txt