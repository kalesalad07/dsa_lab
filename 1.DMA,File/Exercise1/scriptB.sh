rm *.o
rm *exe

gcc -c setB.c
gcc -c quiz.c
gcc -o quizB_exe setB.o quiz.o

./quizB_exe
