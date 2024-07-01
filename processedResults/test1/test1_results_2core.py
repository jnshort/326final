import numpy as np

def main():
    # Value determined from non-deadlocking tests from ndTests folder
    no_deadlock_max = 125000

    print("starting")
    total = np.zeros(1000)
    testResults = open("test1_log_2core.txt", "r")
    _ = testResults.readline()
    minimum = np.inf
    maximum = 0
    sum = 0
    no_deadlock = 0 

    for i in range(1000):
        line = testResults.readline().strip("\n")
        numAsInt = int(line.split("\t")[0].split(" ")[1])
        total[i] = numAsInt
        if total[i] < minimum:
            minimum = total[i]
        if total[i] > maximum:
            if total[i] > no_deadlock_max:
                no_deadlock += 1
            else:
                maximum = total[i]
        sum += total[i]
    average = sum/1000

    print(f"Min: {minimum}")
    print(f"Max: {maximum}")
    print(f"Avg: {average}")
    print(f"No deadlock encountered: {no_deadlock} times")

main()