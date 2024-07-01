import numpy as np

def main():
    print("starting")
    total = np.zeros(1000)
    testResults = open("test1_log_6core.txt", "r")
    _ = testResults.readline()
    minimum = np.inf
    maximum = 0
    sum = 0

    for i in range(998):
        line = testResults.readline().strip("\n")
        numAsInt = int(line.split("\t")[0].split(" ")[1])
        total[i] = numAsInt
        if total[i] < minimum:
            minimum = total[i]
        if total[i] > maximum:
            maximum = total[i]
        sum += total[i]
    average = sum/998

    print(f"Min: {minimum}")
    print(f"Max: {maximum}")
    print(f"Avg: {average}")

main()