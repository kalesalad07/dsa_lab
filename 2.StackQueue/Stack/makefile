runStackWithArray: stackDriver.o stack_array.o
	gcc -o runStackWithArray stackDriver.o stack_array.o
	./runStackWithArray

stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c

stack_array.o:
	gcc -c stack_array.c

runStackWithLinkedList: stackDriver.o stack_ll.o linked_list.o
	gcc -o runStackWithLinkedList stackDriver.o linked_list.o stack_ll.o
	./runStackWithLinkedList

stack_ll.o:
	gcc -c stack_ll.c

linked_list.o:
	gcc -c linked_list.c

clean:
	rm -f *.o runStackWithArray runCgWithArray runCgWithLinkedList runStackWithLinkedList

runCgWithArray: cgStackDriver.o stack_array.o heap_usage.o
	gcc -o runCgWithArray cgStackDriver.o stack_array.o heap_usage.o
	

runCgWithLinkedList: cgStackDriver.o stack_ll.o heap_usage.o linked_list.o
	gcc -o runCgWithLinkedList cgStackDriver.o stack_ll.o linked_list.o heap_usage.o
	

cgStackDriver.o:
	gcc -c cgStackDriver.c

heap_usage.o: 
	gcc -c heap_usage.c
