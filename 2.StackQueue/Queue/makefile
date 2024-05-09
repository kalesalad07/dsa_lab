runQueueWithArray: queueDriver.o queue_array.o heap_usage.o
	gcc -o runQueueWithArray queueDriver.o queue_array.o heap_usage.o
	./runQueueWithArray

queueDriver.o:
	gcc -c queueDriver.c

queue_array.o:
	gcc -c queue_array.c

heap_usage.o:
	gcc -c heap_usage.c

runQueueWithLinkedList: queueDriver.o queue_ll.o linked_list.o heap_usage.o
	gcc -o runQueueWithLinkedList queueDriver.o linked_list.o queue_ll.o heap_usage.o
	./runQueueWithLinkedList

queue_ll.o:
	gcc -c queue_ll.c

linked_list.o:
	gcc -c linked_list.c

clean:
	rm -f *.o runQueueWithArray runQueueWithLinkedList