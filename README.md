# Fall 2021 CS 3353 PA 01 The Art Gallery

## Problem Summary:
   Our goal is to place rectangular paintings of different prices and sizes on a 1024 x 768 wall. Given a set of art pieces that we could potentially place on the wall, we will try to find out a way that would maximize the value (price) on that wall. The paintings can't be rotated, and every piece is guaranteed to fit on the wall.
   
###   To solve the problem, 
  we could break down the process of hanging a painting on the wall into two sections. The first is a way to "place the painting" in an order that could optimize space efficiency. By inserting more images we could find more optimal ways to place the paintings. The second part of this process is that we need three different algorithms to try for the most optimized placement. These algorithms would be eventually sharing the same insertion method but the results may vary based on the sequence of us placing in paintings. And the three algorithms are:
  
###   Brute Force:
   The brute force algorithm's approach is to try every possible way to sort the painting data set so that it could select the best result. However, as the data set grows larger, it would take too long to process through that many combinations. For example, to try all the orders of a 4 items array, we need to generate 4!= 24 ways to sort the array. To keep the runtime reasonable, the implemented brute force algorithm doesn't take data sets that have more than 10 items. 
   
###   Most Expensive Picture First:
   This algorithm approaches the main objective of this problem in a very direct way. To pack as much value as possible, we could sort the paintings in decreasing order by price. Then we try to fit as many in as possible based on that order, and skip any pieces that won't fit until we run out of options. Assuming that the wall would contain the most expensive paintings in the whole set, this algorithm doesn't use another bin.
   
###   Custom Bin Packing: 
   The bin packing algorithm sorts the pictures in decreasing order by size. While iterating through the set of paintings, if a painting can't fit into the current wall, instead of skipping it over, we create another wall (or bin) to fill up. And future paintings that won't fit into previous bins would repeat this process until the set runs out of new paintings. In the end, we output the wall/bin with the most value.
   
###   Running the Program
   Copy the name of the input file (for example "input.txt) into the command line argument to read information for this file. The program would output 3 files for every algorithm that was used. 
   
###   Performance
   Theoretically, in a scenario that the bigger a painting is, the more expensive it is (not really in the real world), the brute force method would have the most value on a wall because it tried every method. Then it's the bin packing because having multiple walls to choose from could lead to a more optimized output. And there is the most-expensive approach that only provides one wall that would be less optimized in space, yet has the most pricy paintings. 
   While brute force method would always provide the best option, its runtime stacks up significantly as the dataset gets larger. For example, finding 11! combinations is 11 times more times to run the sorting function than 10! (which is already 3628800 times). Therefore, using the bin packing or expensive-first approach would be the way to go once the dataset expands. 
   

