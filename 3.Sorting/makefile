mergeSort_exe: mergeSort.o task2.o
	gcc -o mergeSort_exe task2.o mergeSort.o
	./mergeSort_exe

insertionSort_exe: insertionSort.o task2.o
	gcc -o insertionSort_exe task2.o insertionSort.o

mergeSort.o: mergeSort.c
	gcc -c mergeSort.c

insertionSort.o: insertionSort.c 
	gcc -c insertionSort.c 

task2.o: task2.c
	gcc -c task2.c 

clean:
	rm -f *.o *_exe 
