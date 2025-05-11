import matplotlib.pyplot as plt;

n_values=[10000, 20000, 30000, 40000, 50000]
time_taken=[]
plt.plot(n_values, time_taken, marker='o')
plt.title('Quick Sort Time Complexity')
plt.xlabel('Number of elements(n)')
plt.ylabel('Time taken(seconds)')
plt.grid(True)
plt.show()