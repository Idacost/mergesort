# Merge Sort Time Measurement

This program implements the **Merge Sort** algorithm and measures the time it takes to sort an array.

## Step 1: Compile the Code

g++ mergesort.cpp -o mergesort

## Step 2: Run

./mergesort

## Step 3: Input

The program will prompt you to input the size of the array you'd like to sort. After entering the size, the program will:

Generate an array of random integers.  
Display the initial unsorted array.  
Sort the array using the Merge Sort algorithm.  
Display the sorted array.  
Display the time taken to sort the array (in seconds).  


### Example Output:

Enter the size of your array: 10  
You inputted: 10  
Initial Array: 89 44 83 16 46 46 64 36 34 41  
Sorted Array: 16 34 36 41 44 46 46 64 83 89  
Time elapsed: 0.00000900 seconds  


# Benchmark in Centaurus

After logging into Centaurus I cloned my GitHub and created a script for Centaurus named "run_mergesort.sh".  
Using the script I set it up for the Slurm scheduler in which it would set the settings I needed for the SBATCH and input 10 to 10^9 as user input for the size of the vectors and print back the times for each inside of a txt file.  

## Benchmark Times


The times I recorded align with the expected growth of a merge sort algorithm, which has the Big O Notation of O(n log n). Since this complexity grows faster than linear time but slower than quadratic time, the increasing execution times make sense. As the input size n grows, the time required increases more than proportionally, matching the expected Big O Notation of a merge sort algorithm.
