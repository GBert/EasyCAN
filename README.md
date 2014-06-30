Easy and cheap CAN interface
============================

This repo contains a project of a CAN interface. Main goals are:
- should be cheap
- one layer for homemade PCB or PCB manufacturing in 5cm\*5cm design
- flexible (galvanic isolated is an option)
- useable by many programs and OS (SLCAN API)
- no programmer needed

Price target is 15$ - depends on galvanic isolation 

### Firmware

DS30loader is programmed by the cheap CP2102 board with Darron Broads [k8048](http://dev.kewl.org/k8048/Doc/). The
firmware itself is programmed by the bootloader. So no special programmer needed.

### Status

- working test PCB
- working ds30loader firmware
- working bin loader (modified pirate-loader for PIC18F26K80)
- wip: SLCAN firmware (early stage: blinky ;-)

