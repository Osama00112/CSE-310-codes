yacc -d -y -v 1805002.y -Wcounterexamples
echo 'Generated the parser C file as well the header file'
g++ -w -c -o y.o y.tab.c
echo 'Generated the parser object file'
flex 1805002.l
echo 'Generated the scanner C file'
g++ -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c
echo 'Generated the scanner object file'
g++ -o a.out y.o l.o -lfl 
echo 'All ready, running'
./a.out 1805002_input.txt
