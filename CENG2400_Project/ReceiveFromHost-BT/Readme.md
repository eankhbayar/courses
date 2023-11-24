# Hints for CENG2400 Project Week 2

# communicate with bluetooth (HC-05): 

1. This part of project mainly reply on UART communication, please refer to preivous labs for more information of UART.
2. We have provided the basic function of one-way communication, which enables communication from phone/pc to launchpad via HC-05.
3. You are required to implement communication from launchpad to phone/pc.
4. You are recommended to implement the communication function via interrupt instead of the 'while' loop.
5. Before that, the most important thing is to check the default baud rate of HC-05, which determines whether your program will run properly.
6. Baud rate is usually set to 9600, 38400, 115200...
7. Use the software we provide in Appendix A to monitor the bluetooth serial, and use Realterm/Arduino to monitor the launchpad serial.
8. Arduino is much easier to use than Realterm. If you want, you can download here (https://www.arduino.cc/en/software). Please download version: Legacy IDE (1.8.X), since the latest one does not work well.

## Note:

We built this project with the compiler version of TI v20.2.7.LTS. If the code goes wrong, the main reason should be the version incompatibility.
