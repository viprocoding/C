Queue
=====
Generic C queue. <br><br>

<B>Left to do:</B><br>
* Write a proper test program to validate that everything works correctly.<br>

<B>To use the queue properly:</B><br>

1. Once a queue is declared, always initialized it with queueInit. <br>
2. Once something is passed on to the queue, it's considered to be owned by the
queue. The programmer has "no rights" to try and use the elements that are
in custody of the queue, and is therefor not resposible to clean up anything
that is considered to be owned by the queue. <br>
3. Always call queueDispose when you are done using a queue. This is to prevent
memory leaks. <br><br>
