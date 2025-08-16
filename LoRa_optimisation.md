Created a target class and the receiver handler to start optimising the LoRa transmission. 
The issue with the current setup is that with additional clients, it can cause delays or watchdog timeouts. I believe this is due to the existing packets large size, and an inefficient use of the existing LoRa module. 

TODO:

- add unit ID to packet 
- create template for different info packets 
- create prioritisation framework for packet types

TO THINK ABOUT: 

- setting SNR threshold for packet types
ie only allow packets < 10 bytes for SNR > 10dB 
- asynchronous handler for sending data 
- implementing freeRTOS receive handler 
- implementing DMA to reduce CPU time loss on data reception 