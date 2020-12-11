# :roller_coaster: Roller coaster problem solution
### using :vertical_traffic_light: semaphore

- Semaphore is used to represent the number of places in the car (3)    
- When a visitor (represented by a thread) jumps in a number of vacant places (semaphore value) decreases :arrow_down:  
- When a visitor finishes the ride (it takes 3 sec), number of vacant places (semaphore value) increases :arrow_up:  
- The next visitor can jump in :arrow_heading_down:  
- The simulation finishes when all 10 have taken a ride :white_check_mark:

To compile && run type ``make`` in this directory

### Output preview:

![Output preview](https://github.com/k-allard/imgs/blob/master/Screenshot%202020-12-11%20at%2021.15.23.png)
