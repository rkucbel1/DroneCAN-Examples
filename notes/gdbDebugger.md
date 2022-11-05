Debugger Setup and Operation Notes:
-----------------------------------

Setup:
------
- On x86 machine install gdb-multiarch
- On x86 machine create .gdbinit file in home directory
- On x86 machine create .gdbinit file in working directory -> sets IP addr of target
- set compile debug flag in makefile '-g'

- On target install gdbserver

.gdbinit file in home directory
add-auto-load-safe-path /home/rkucbel1/DroneCAN-Examples/socketcan_gnss/.gdbinit

.gdbinit file in project directory (ip address according to specif target) :2345 is arbitrary
set architecture arm
target remote 192.168.2.96:2345




Operation:
----------

On target: (ie: Beaglebone)
> cd [location of binary file to be debugged]
> gdbserver localhost:2345 [name_of_binary]

On host: (ie: x86 machine)
> cd [location of binary file to be debugged]
> gdb-multiarch [name_of_binary]

Some basic gdb commands:
------------------------

(gdb) b 29                      //set break point on line 29
(gdb) del 1                     //remove break point number 1
(gdb) list                      //shows program list
(gdb) print [name of variable]  //print values of variable
(gdb) continue                  //runs the program when target is remote; continue from break point
(gdb) info local                //shows all local vars
(gdb) step                      //step into; go to next line

