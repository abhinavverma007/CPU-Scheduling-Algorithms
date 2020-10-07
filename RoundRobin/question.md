Systems that run concurrently on a single CPU have round-robin scheduling process for which tasks to run,at what time to run them,and how to break them up. This round-robin scheduling
technique runs each job for a fixed amount of time before switching to the next job. The waiting time for the job is the total time that it spends waiting to be run. Each job arrives
in a queue at a particular time and takes certain amount of time to run. When a new job arrives, it is scheduled to run after the jobs that are already waiting for the CPU.
Jobs that arrive at the same time are prcoessed in the order they are found in the arrival array. You may assume jobs arrive in such frequency the CPU is never idle. A list of job 
submissions is given.

Write a algorithm to determine average waiting time for all the jobs using round-robin scheduling process.

Input
1) First line number of processes
2) List of arrival times
3) List of run time
4) time quantum

Example:
3
0 1 4
5 2 3
3

Output:
2.33
