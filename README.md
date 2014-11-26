Easy and cheap CAN interface
============================

This repo contains a project of a CAN interface. Main goals are:
- should be cheap
- one layer for homemade PCB or PCB manufacturing in 5cm\*5cm design
- flexible (galvanic isolated is an option)
- useable by many programs and OS (SLCAN API)
- no PIC programmer needed

Price target is 15$ - depends on galvanic isolation 

[![alt text](https://github.com/GBert/EasyCAN/blob/master/pictures/easycan_board_front_t.jpg "PCB front")](https://raw.githubusercontent.com/GBert/EasyCAN/master/pictures/easycan_board_front.jpg)
[![alt text](https://github.com/GBert/EasyCAN/blob/master/pictures/easycan_board_back_II_t.jpg "PCB back")](https://raw.githubusercontent.com/GBert/EasyCAN/master/pictures/easycan_board_back_II.jpg)
[![alt text](https://github.com/GBert/EasyCAN/blob/master/pictures/easycan_board_back_t.jpg "PCB back including CP2102")](https://raw.githubusercontent.com/GBert/EasyCAN/master/pictures/easycan_board_back.jpg)
[![alt text](https://github.com/GBert/EasyCAN/blob/master/pictures/easycan-test_setup_t.jpg "EasyCAN test setup")](https://raw.githubusercontent.com/GBert/EasyCAN/master/pictures/easycan-test_setup.jpg)


### Firmware

Bootloader ([Wellington](http://hg.kewl.org/pub/wellington/)) is programmed by the cheap CP2102 board with Darron Broads [k8048](http://dev.kewl.org/k8048/Doc/). The firmware itself is programmed by the bootloader. So no PIC programmer needed.

### Status

- working test PCB
- working Wellington bootloader
- working easy-loader from Darron Broad
- wip: SLCAN firmware (thx to Darron Broad sending and receiving standard CAN frames works)

