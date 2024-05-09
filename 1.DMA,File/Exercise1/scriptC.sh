rm *.o
rm *exe

gcc -c setC.c
gcc -c quiz.c
gcc -o quizC_exe setC.o quiz.o

./quizC_exe
