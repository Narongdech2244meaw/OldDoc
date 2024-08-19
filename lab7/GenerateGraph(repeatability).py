import matplotlib.pyplot as plt

# Data for Linear Ramp-Down Test 1
linear_rampdown_1_sizes = [50000, 40000, 30000, 20000, 10000]
linear_rampdown_1_times = [0.000866083, 0.000676875,
                           0.000453042, 0.000301875, 0.000151042]

# Data for Linear Ramp-Down Test 2
linear_rampdown_2_sizes = [50000, 40000, 30000, 20000, 10000]
linear_rampdown_2_times = [0.000759792, 0.000618792,
                           0.000453333, 0.000301792, 0.000151041]

# Data for Linear Ramp-Down Test 3
linear_rampdown_3_sizes = [50000, 40000, 30000, 20000, 10000]
linear_rampdown_3_times = [0.000754833, 0.000603583,
                           0.000452625, 0.000303583, 0.000152583]

# Create plots for each test type
plt.figure(figsize=(15, 5))

# Linear Ramp-Down Test 1
plt.subplot(1, 3, 1)
plt.plot(linear_rampdown_1_sizes, linear_rampdown_1_times, marker='o')
plt.title('Linear Ramp-Down Test 1')
plt.xlabel('Size')
plt.ylabel('Time (s)')

# Linear Ramp-Down Test 2
plt.subplot(1, 3, 2)
plt.plot(linear_rampdown_2_sizes, linear_rampdown_2_times, marker='o')
plt.title('Linear Ramp-Down Test 2')
plt.xlabel('Size')
plt.ylabel('Time (s)')

# Linear Ramp-Down Test 3
plt.subplot(1, 3, 3)
plt.plot(linear_rampdown_3_sizes, linear_rampdown_3_times, marker='o')
plt.title('Linear Ramp-Down Test 3')
plt.xlabel('Size')
plt.ylabel('Time (s)')

# Adjust layout
plt.tight_layout()

# Show the plots
plt.show()
