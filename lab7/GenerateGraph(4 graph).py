import matplotlib.pyplot as plt

# Data for Linear Ramp-up Test
linear_rampup_sizes = [10000, 20000, 30000, 40000, 50000]
linear_rampup_times = [0.000177709, 0.000336667,
                       0.000506917, 0.000662708, 0.000822583]

# Data for Exponential Ramp-up Test
exponential_rampup_sizes = [1, 10, 100, 1000, 10000]
exponential_rampup_times = [
    4.59e-07, 4.58e-07, 1.75e-06, 1.5375e-05, 0.00015225]

# Data for Linear Ramp-Down Test
linear_rampdown_sizes = [50000, 40000, 30000, 20000, 10000]
linear_rampdown_times = [0.000760916, 0.000603958,
                         0.000454625, 0.000302, 0.000151292]

# Data for Exponential Ramp-Down Test
exponential_rampdown_sizes = [10000, 1000, 100, 10, 1]
exponential_rampdown_times = [0.000151167,
                              1.5459e-05, 1.916e-06, 4.58e-07, 3.33e-07]

# Create plots for each test type
plt.figure(figsize=(10, 6))

# Linear Ramp-up Test
plt.subplot(2, 2, 1)
plt.plot(linear_rampup_sizes, linear_rampup_times, marker='o')
plt.title('Linear Ramp-up Test')
plt.xlabel('Size')
plt.ylabel('Time (s)')

# Exponential Ramp-up Test
plt.subplot(2, 2, 2)
plt.plot(exponential_rampup_sizes, exponential_rampup_times, marker='o')
plt.title('Exponential Ramp-up Test')
plt.xlabel('Size')
plt.ylabel('Time (s)')

# Linear Ramp-Down Test
plt.subplot(2, 2, 3)
plt.plot(linear_rampdown_sizes, linear_rampdown_times, marker='o')
plt.title('Linear Ramp-Down Test')
plt.xlabel('Size')
plt.ylabel('Time (s)')

# Exponential Ramp-Down Test
plt.subplot(2, 2, 4)
plt.plot(exponential_rampdown_sizes, exponential_rampdown_times, marker='o')
plt.title('Exponential Ramp-Down Test')
plt.xlabel('Size')
plt.ylabel('Time (s)')

# Adjust layout
plt.tight_layout()

# Show the plots
plt.show()
