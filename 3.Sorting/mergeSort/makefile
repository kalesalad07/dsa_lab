mergeSortIter_exe: intMergeSort.o intMerge.o mergeAuxIter.o
	gcc -o mergeSortIter_exe intMergeSort.o  intMerge.o mergeAuxIter.o
	./mergeSortIter_exe

mergeSortRec_exe: intMergeSort.o intMerge.o mergeAuxRec.o
	gcc -o mergeSortRec_exe intMergeSort.o intMerge.o mergeAuxRec.o
	./mergeSortRec_exe

intMergeSort.o: intMergeSort.c
	gcc -c intMergeSort.c

intMerge.o: intMerge.c
	gcc -c intMerge.c

mergeAuxIter.o: mergeAuxIter.c
	gcc -c mergeAuxIter.c

mergeAuxRec.o: mergeAuxRec.c
	gcc -c mergeAuxRec.c

clean:
	rm -f *.o *_exe