compile : make

run:

./run 2

Enter command> submit ls -l
job 1  ls -l added to the queue

Enter command> submit ps -a
job 2  ps -a added to the queue

Enter command> submit ./ss 20
job 3  ./ss 20 added to the queue

Enter command> showjobs
Jobid Command              Status     Starttime Endtime`
    3 ./ss 20              running    Sat Apr 15 15:22:21 2023

Enter command> submit ./ss 30
job 4  ./ss 30 added to the queue

Enter command> showjobs
Jobid Command              Status     Starttime Endtime`
    3 ./ss 20              running    Sat Apr 15 15:22:21 2023
    4 ./ss 30              running    Sat Apr 15 15:22:32 2023
Enter command> submit ./ss 25
job 5  ./ss 25 added to the queue
Enter command> showjobs
Jobid Command              Status     Starttime Endtime`
    4 ./ss 30              running    Sat Apr 15 15:22:32 2023
    5 ./ss 25              running    Sat Apr 15 15:22:41 2023
Enter command> submit ./ss 23
job 6  ./ss 23 added to the queue
Enter command> showjobs
Jobid Command              Status     Starttime Endtime`
    4 ./ss 30              running    Sat Apr 15 15:22:32 2023
    5 ./ss 25              running    Sat Apr 15 15:22:41 2023
    6 ./ss 23              waiting
Enter command> submithistory
Jobid Command              Status     Starttime Endtime`
    1 ls -l                completed  Sat Apr 15 15:22:04 2023 Sat Apr 15 15:22:04 2023
    2 ps -a                completed  Sat Apr 15 15:22:09 2023 Sat Apr 15 15:22:09 2023
    3 ./ss 20              completed  Sat Apr 15 15:22:21 2023 Sat Apr 15 15:22:41 2023
    4 ./ss 30              completed  Sat Apr 15 15:22:32 2023 Sat Apr 15 15:23:02 2023
Enter command> submithistory
Jobid Command              Status     Starttime Endtime`
    1 ls -l                completed  Sat Apr 15 15:22:04 2023 Sat Apr 15 15:22:04 2023
    2 ps -a                completed  Sat Apr 15 15:22:09 2023 Sat Apr 15 15:22:09 2023
    3 ./ss 20              completed  Sat Apr 15 15:22:21 2023 Sat Apr 15 15:22:41 2023
    4 ./ss 30              completed  Sat Apr 15 15:22:32 2023 Sat Apr 15 15:23:02 2023
    5 ./ss 25              completed  Sat Apr 15 15:22:41 2023 Sat Apr 15 15:23:06 2023
Enter command> showjobs
Jobid Command              Status     Starttime Endtime`
Enter command> submithistory
Jobid Command              Status     Starttime Endtime`
    1 ls -l                completed  Sat Apr 15 15:22:04 2023 Sat Apr 15 15:22:04 2023
    2 ps -a                completed  Sat Apr 15 15:22:09 2023 Sat Apr 15 15:22:09 2023
    3 ./ss 20              completed  Sat Apr 15 15:22:21 2023 Sat Apr 15 15:22:41 2023
    4 ./ss 30              completed  Sat Apr 15 15:22:32 2023 Sat Apr 15 15:23:02 2023
    5 ./ss 25              completed  Sat Apr 15 15:22:41 2023 Sat Apr 15 15:23:06 2023
    6 ./ss 23              completed  Sat Apr 15 15:23:02 2023 Sat Apr 15 15:23:25 2023
Enter command>
