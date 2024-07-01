import numpy as np

def main():
    # Value determined from non-deadlocking tests from ndTests folder
    # minimum value from several non-dealocking tests found was 160500 when ran on 6-core cpu 
    no_deadlock_max = 170000

    print("Test 3 Results for 2-core CPU")
    total = np.zeros(999)
    testResults = open("test3_log_2core.txt", "r")
    _ = testResults.readline()
    minimum = np.inf
    maximum = 0
    sum = 0
    deadlock = 0 

    for i in range(999):
        line = testResults.readline().strip("\n")
        numAsInt = int(line.split("\t")[0].split(" ")[1])
        total[i] = numAsInt
        if total[i] < minimum:
            minimum = total[i]
        if total[i] > maximum:
            if total[i] > no_deadlock_max:
                deadlock += 1
            else:
                maximum = total[i]
        sum += total[i]
    average = sum/999

    print(f"Min: {minimum}")
    print(f"Max: {maximum}")
    print(f"Avg: {average}")
    print(f"Deadlock encountered: {deadlock} times")

main()