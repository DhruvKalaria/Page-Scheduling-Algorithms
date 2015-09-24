# PageScheduling
Implementation of 3 page scheduling algorithms:

The project simulates various page replacement algorithms under different working conditions like 
varying page frame size and page numbers. Algorithms are judged based on the number of page faults it produces under similar working conditions. 
Graphs are plotted in the XY plane to compare various algorithms

There are many page replacement algorithms available, but we have tried to implement following 3 algorithms:

1. FIFO
2. LRU
3. Optimal

After simulating the results, we have following observations:

1. Page Fault is a linear function of Page Numbers that is as the number of page numbers increases the number of page faults also increases in a linear fashion.
2. Slope of graphs of LRU and FIFO are almost same and the number of page faults increases at a higher rate as compared to optimal.
3. As the number of randomness becomes equal to the page frame size all the algorithms behave similar and the page fault equals the numbers of page frame size.
4. Optimal algorithm is most complex to implement followed by LRU and then FIFO. Based on above analysis any of the 3 algorithms may be used based on the requirement.
