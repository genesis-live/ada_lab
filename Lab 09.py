import matplotlib.pyplot as plt;

n_values=[]
time_taken=[]
plt.plot(n_values, time_taken, marker='o')
plt.title('Selection Sort Time Complexity')
plt.xlabel('Number of elements(n)')
plt.ylabel('Time taken(seconds)')
plt.grid(True)
plt.show()