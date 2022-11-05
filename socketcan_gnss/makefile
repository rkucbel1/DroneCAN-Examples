LIBCANARD_PATH=/home/rkucbel1/DroneCAN-Examples/socketcan_gnss/libcanard
SOCKETCAN_PATH=/home/rkucbel1/DroneCAN-Examples/socketcan_gnss/socketcan
INCLUDE_PATH=/home/rkucbel1/DroneCAN-Examples/socketcan_gnss


all:
#	rm -rf bin
#	mkdir bin
# gcc -I$(INCLUDE_PATH) test_canard_rx.c $(LIBCANARD_PATH)/canard.c $(O1HEAP_PATH)/o1heap.c $(SOCKETCAN_PATH)/socketcan.c -o bin/test_canard_rx
#	~/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc  -pthread $(INCLUDE_PATH)/test_canard_tx.c $(LIBCANARD_PATH)/canard.c $(O1HEAP_PATH)/o1heap.c $(SOCKETCAN_PATH)/socketcan.c -o $(INCLUDE_PATH)/socketcan_canard_Tx
	~/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin/arm-none-linux-gnueabihf-gcc -g  $(INCLUDE_PATH)/node_gnss.c $(LIBCANARD_PATH)/canard.c $(SOCKETCAN_PATH)/socketcan.c -o $(INCLUDE_PATH)/socketcan_gnss
	 echo $(shell  scp ~/socketcan_gnss/socketcan_gnss debian@192.168.2.96:/home/debian/bin)
#clean: 
	#rm -rf bin/
 
