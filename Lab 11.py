import matplotlib.pyplot as plt;

n_values=[6000, 7000, 8000, 9000, 10000, 11000, 12000]
time_taken=[]
plt.plot(n_values, time_taken, marker='o')
plt.title('Merge Sort Time Complexity')
plt.xlabel('Number of elements(n)')
plt.ylabel('Time taken(seconds)')
plt.grid(True)
plt.show()