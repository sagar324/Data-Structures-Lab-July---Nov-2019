# Data-Structures-Lab-July---Nov-2019
 lines (41 sloc)  2.54 KB
  
At any given point in time, there are a number processes waiting in the ready queue to be executed by the processor (CPU) in a computer. The operating system (OS) schedules the processes, i.e., chooses one of the processes from the pool, and assigns it to the CPU to be executed. Only one process can be in running state at a time in a single processor system. Consider a case in which the OS uses, for process scheduling, the priority scheduling with preemption algorithm which works as follows:<br />
<br />
Every process is associated with a process number (unique), priority value, arrival time and burst (execution) time. At any point in time, the OS always chooses the process with inverse priority value to be executed (for eg., priority value of 1 is considered to be higher than 2). Any ties in priority are resolved using arrival time. If there arrives a process with higher priority while a lower priority process is being executed, the running process is preempted (i.e., sent back) to the ready queue (which is a priority queue) and the higher priority process starts execution. When the preempted process again gets scheduled, it resumes its execution from the state it was preempted. A process may get preempted multiple number of times.<br />
<br />
Write a piece of code to implement the above scheduling algorithm. Use binary min-heap to maintain the ready queue of processes. Please note that the key that needs to be considered is the priority value of the process. Any ties in priority values are resolved using arrival time. Also, consider the following instructions:<br />
<br />
The processes are always given in increasing order of their arrival time. Hence, no two processes with the same priority have the same arrival time.<br />
You can assume that the first process always arrives at time 0<br />
Input Format<br />
<br />
N<br />
N lines of < Process_No, Process_Priority, Arrival_Time, Burst_Time ><br />
<br />
Constraints<br />
<br />
N – Number of processes, 1 <= N <= 200<br />
Priority of a process >= 0<br />
Execution start time = 0<br />
Burst time <= 50<br />
<br />
Output Format<br />
<br />
Print the heap in preorder traversal every time an item is deleted from the heap. Do not print anything if the heap is empty<br />
Print the process numbers in the order of their execution<br />
Print the time value at which there is either a context switch or a process finishes (In other words, before a min-node is extracted from the heap)<br />
Sample Input 0<br />
<br />
3<br />
1 2 0 4<br />
2 1 2 3<br />
3 2 2 4<br />
Sample Output 0<br />
<br />
1 3 <br />
3 <br />
1 2 1 3 <br />
2 5 7 11 <br />
Sample Input 1<br />
<br />
5<br />
1 2 0 6<br />
2 1 1 3<br />
3 3 1 2<br />
4 1 2 1<br />
5 2 3 5<br />
Sample Output 1<br />
<br />
4 5 3 1 <br />
1 5 3 <br />
5 3 <br />
3 <br />
1 2 4 1 5 3 <br />
1 4 5 10 15 17<br />
