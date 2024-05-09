rm *.o
rm *exe

gcc -c setA.c
gcc -c quiz.c
gcc -o quizA_exe setA.o quiz.o

./quizA_exe
