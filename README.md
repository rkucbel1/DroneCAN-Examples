# DroneCAN-Examples
DroneCAN Examples using SocketCAN for Linux Systems
# DroneCAN-Examples
DroneCAN Examples using SocketCAN for Linux Systems

This repository was started by copying much of what is in the dronecan/libcanard repository.

The intent is to provide working examples of the libcanard implementation for my own use.

Development Platform
---------------------
The hardware platform used is two beaglebone-blue single board computers connected together
by CAN bus (can0). An optional Ardupilot or PX4 autopilot configured to use DroneCAN can be
added for experimentation. (3.3V CAN bus transceivers are compatible with 5.0V CAN transceivers
on the same bus)

Each beaglebone has tightVNC server installed and lxde. This way the DroneCAN gui_tool can
be used directly on the beaglebone to monitor bus traffic from the development host computer.
(This saves having to buy any special CAN bus hardware)

To support lxde, the beaglebone needs to be run from a distribution on an SD card (8GB or more).
The onboard flash is not big enough. Once you are booted from the SD card run the grow_partition.sh
script in /opt/scripts/tools/ directory.

gui_tool can be downloaded from the offical dronecan repository. I had trouble installing it through the
instructions. I did get it to work by copying the entire gui_tool directory and running the binary in 
the bin/ folder. The first time I tried to run it, there were lots of python dependencies missing. Read
the error outputs and install the missing packages. One package took quite a while to install.

The CAN bus on the beaglebone is not enabled on startup. Run the following to get it up. (I made a script
to do this at bootup)

: sudo /sbin/ip link set can0 up type can bitrate 1000000
: sudo ifconfig can0 up

Note: These notes can be adapted to use beaglebone-black or raspberry pi. I'm not 100% sure if the
raspberry pi has a CAN controller. I actually did this with one sbc as a beaglebone-black since it
is what I had and it has a CAN controller. I did have to build an add on CAN transceiver from parts 
I had laying around. But if you value your time, just go for the qty 2 beaglebone-blues.

Development System
------------------
For the development system, I use a Linux machine running Ubuntu.

Development is done on Eclipse mainly because I like the indexer and I know how to setup the beaglebones
as remote systems to automatically deploy the cross-compiled binary. 

For the debugger I use gdb-multiarch on the development machine and gdbserver on the beaglebone. Both
are run through a terminal window. It is old school, but even a basic use of this debugger can quickly
get to the root of a problem. Also I can not for the life of me get the remote debugger configured 
properly on Eclipse for that 'one stop shop' experience.

For the vnc viewer (to use gui_tool) I use tvnjviewer. Java mght need to be installed. Just make sure if
Java is needed to be installed, install the non-headless version.
