# LMU CMSI  387 Spring 2019
## Assignment #3
### Tyler Edmiston, Teddy Chu, Anthony Keba

1. See DiningPhilosophers.java.
2. Philosophers are generic Java objects and use the `synchronized` keyword. The primary reason for deadlock in our soulutoin is the wait condition. In order to ensure the circular wait c ondition is broken, we have all Philosophers reach for their left fork first, except one that reaches for their right fork. This is a simple solution to a simple deadlock problem with emphasis on the circular wait.
3. See `file-processes.c`.
4. See `mmap.c`.
5. A bounded buffer class could be used for the holding area; the producer would store a value into the immediate storage area (i.e. buffer). Once the value from the buffer is ready, the consumer retrieves it. For the TopicServer, the synchronization pattern of the bounded buffer would look like this:
> The receive method stores messages into the buffer while another thread takes the messages and delivers them to their respective subscribers. With the buffer, the receive thread is free to bring messages into said buffer while other threads consume the messages as needed.